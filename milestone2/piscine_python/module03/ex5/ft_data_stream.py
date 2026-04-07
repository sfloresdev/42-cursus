
import random
import typing

NAMES = ["alice", "dylan", "charlie", "bob"]
ACTIONS = ["move", "swim", "run", "grab", "sleep", "climb", "eat"]


def get_event() -> typing.Generator[tuple[str, str], None, None]:
    while True:
        name = random.choice(NAMES)
        action = random.choice(ACTIONS)
        yield (name, action)


def consume_event(event_list: list[tuple[str, str]]):
    while len(event_list) > 0:
        index = random.randrange(len(event_list))
        event = event_list.pop(index)
        yield event


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    event_stream = get_event()
    for i in range(1000):
        event = next(event_stream)
        print(f"Event{i}: Player {event[0]} did action {event[1]}")

    event_list = [next(event_stream) for _ in range(10)]
    print(f"\nBuilt list of 10 events: {event_list}")

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")
