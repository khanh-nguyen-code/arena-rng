from typing import List, Iterator


def ArenaRNG(seed: List[int]) -> Iterator[float]:
    a = [0, *seed[0:3]]
    b = [0, *seed[3:6]]
    while True:
        a[0] = (1403580 * a[2] - 810728 * a[3]) % 4294967087  # might be negative
        b[0] = (527612 * b[1] - 1370589 * b[3]) % 4294944443  # might be negative
        z = (a[0] - b[0]) % 4294967087
        if z < 0:
            # positivify
            z += 4294967087
        if z > 0:
            u = float(z) / 4294967088.0
        else:
            u = 4294967087.0 / 4294967088.0
        # shift
        a = [0, *a[0:3]]
        b = [0, *b[0:3]]
        yield u


if __name__ == "__main__":
    rng = ArenaRNG([1, 2, 3, 4, 5, 6])
    for i in range(10):
        print(next(rng))
