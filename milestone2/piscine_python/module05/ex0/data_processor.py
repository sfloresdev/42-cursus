
import typing
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        super().__init__()
        self.data: list[tuple[int, str]] = []
        self.next: int = 0

    @abc.abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> Tuple[int, str]:
        if not self.data:
            raise IndexError("No data available")
        return self.data.pop(0)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            if all(isinstance(_, (int, float)) for _ in data):
                return True
        return False

    def ingest(self, data: Any) -> None:
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
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            if all(isinstance(_, str) for _ in data):
                return True
        return False

    def ingest(self, data):
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
    def _is_log(self, d: Any) -> bool:
        return (
            isinstance(d, dict)
            and all(isinstance(k, str) and isinstance(v, str)
                    for k, v in d.items())
        )

    def validate(self, data: Any) -> bool:
        if self._is_log(data):
            return True
        return isinstance(data, list) and all(self._is_log(_) for _ in data)

    def ingest(self, data: Any) -> :
        if not self.validate(data):
            raise ValueError("Improper Log data")

        items = data if isinstance(data, list) else [data]
        try:
            for item in items:
                level = item.get('log_level', 'UNKWOWN')
                message = item.get('log_message', '')
                log_formatted = f"{level} : {message}"
                self.data.append((self.next, log_formatted))
                self.next += 1
        except Exception as e:
            raise RuntimeError(f"Log ingestion error: {e}")
