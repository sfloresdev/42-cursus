def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda m: m['power'] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda s: f"* {s} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    powers = list(map(lambda m: m['power'], mages))

    if not powers:
        return {"max_power": 0, "min_power": 0, "avg_power": 0}

    return {
        'max_power': max(powers),
        'min_power': min(powers),
        'avg_power': round(sum(powers) / len(powers), 2)
    }


if __name__ == "__main__":
    artifacts = [{'name': 'Wind Cloak', 'power': 61, 'type': 'armor'}, {'name': 'Lightning Rod', 'power': 103, 'type': 'weapon'}, {'name': 'Ice Wand', 'power': 87, 'type': 'armor'}, {'name': 'Lightning Rod', 'power': 90, 'type': 'focus'}]
    print(f"{artifact_sorter(artifacts)}")

    mages = [{'name': 'Jordan', 'power': 76, 'element': 'wind'}, {'name': 'Riley', 'power': 80, 'element': 'ice'}, {'name': 'Jordan', 'power': 97, 'element': 'lightning'}, {'name': 'Zara', 'power': 87, 'element': 'water'}, {'name': 'Morgan', 'power': 51, 'element': 'wind'}]
    print(f"\n{power_filter(mages, 77)}")

    print(f"\n^TEST^{mage_stats(mages)}")

    spells = ['flash', 'earthquake', 'freeze', 'tornado']
    print(f"\n{spell_transformer(spells)}")
