
import typing
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        super().__init__()
        self.data: typing.List[typing.Tuple[int, str]] = []
        self.next: int = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self.data:
            raise IndexError("No data available")
        return self.data.pop(0)


class DataStream:
    def __init__(self) -> None:
        self.processors: typing.List[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        if isinstance(proc, DataProcessor):
            self.processors.append(proc)
            print(f"{type(proc).__name__} Processor registered")
        else:
            print("Error: Couldn't register data processor")

    def process_stream(self, stream: list[typing.Any]) -> None:
        for item in stream:
            found = False
            for p in self.processors:
                if p.validate(item):
                    p.ingest(item)
                    found = True
                    break
            if not found:
                print(f"Data Stream Error - Can't process element: {item}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.processors:
            print("No processors found, no data")
            return

        for p in self.processors:
            print(f"{type(p).__name__}", end="")
            print(f"total {p.next} processed", end="")
            print(f", remaining {len(p.data)} on processor")


class NumericProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            if all(isinstance(_, (int, float)) for _ in data):
                return True
        return False

    def ingest(
        self,
        data: typing.Union[int, float, typing.List[typing.Union[int, float]]]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        items = data if isinstance(data, list) else [data]
        try:
            for item in items:
                self.data.append((self.next, str(item)))
                self.next += 1
        except Exception as e:
            raise RuntimeError(f"Numeric data corruption (fatal crash): {e}")


class TextProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            if all(isinstance(_, str) for _ in data):
                return True
        return False

    def ingest(self, data: typing.Union[str, typing.List[str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        items = data if isinstance(data, list) else [data]
        try:
            for item in items:
                self.data.append((self.next, item))
                self.next += 1
        except Exception as e:
            raise RuntimeError(f"Text ingestion error: {e}")


class LogProcessor(DataProcessor):
    def _is_log(self, d: typing.Any) -> bool:
        return (
            isinstance(d, dict)
            and all(isinstance(k, str) and isinstance(v, str)
                    for k, v in d.items())
        )

    def validate(self, data: typing.Any) -> bool:
        if self._is_log(data):
            return True
        return isinstance(data, list) and all(self._is_log(_) for _ in data)

    def ingest(
        self,
        data: typing.Union[typing.Dict[str, str],
                           typing.List[typing.Dict[str, str]]]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper Log data")

        items = data if isinstance(data, list) else [data]
        try:
            for item in items:
                level = item.get('log_level', 'UNKWOWN')
                message = item.get('log_message', 'No data available')
                log_formatted = f"{level}: {message}"
                self.data.append((self.next, log_formatted))
                self.next += 1
        except Exception as e:
            raise RuntimeError(f"Log ingestion error: {e}")


if __name__ == "__main__":
    DATA_POOL = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {'log_level': 'WARNING', 'log_message':
             'Telnet access! Use ssh instead'},
            {'log_level': 'INFO', 'log_message': 'User wil is connected'}
        ],
        42,
        ['Hi', 'five']
    ]
    print("=== Code Nexus - Data Stream ===\n")
    data_stream = DataStream()
    data_stream.print_processors_stats()

    print("\nRegistering Numeric Processor")
    num = NumericProcessor()
    data_stream.register_processor(num)

    print(f"Send first batch of data on stream {DATA_POOL}")
    data_stream.process_stream(DATA_POOL)
    data_stream.print_processors_stats()

    print("\nRegistering other data processors")
    text = TextProcessor()
    log = LogProcessor()
    data_stream.register_processor(text)
    data_stream.register_processor(log)
    print("Sending the same batch again")
    data_stream.process_stream(DATA_POOL)
    data_stream.print_processors_stats()

    print("\nConsume some elements: Numeric 3, Text 2, Log 1")
    for i in range(3):
        num.output()
    for i in range(2):
        text.output()
    log.output()
    data_stream.print_processors_stats()
