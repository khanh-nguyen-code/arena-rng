from typing import Iterator


def RNG(*args: int) -> Iterator[float]:
    assert len(args) == 6, "seed must be 6 non-negative integers less than 2^32"
    for seed in args:
        assert isinstance(seed, int), "seed must be 6 non-negative integers less than 2^32"
        assert 0 <= seed < 2 ** 32, "seed must be 6 non-negative integers less than 2^32"

    a_list = [*args[0:3]]
    b_list = [*args[3:6]]
    while True:
        # each component always in range [0, 2^64)
        # a, b always in range [0, 2^32)
        a = (1403580 * a_list[1] + (4294967087 - 810728) * a_list[2]) % 4294967087
        b = (527612 * b_list[0] + (4294944443 - 1370589) * b_list[2]) % 4294944443
        # z always in range [1, 4294967087]
        z = (a + 4294967087 - b) % 4294967087 + 1  # shifted by +1 as compare to arena
        u = float(z) / 4294967088.0
        # shift
        a_list = [a, *a_list[0:2]]
        b_list = [b, *b_list[0:2]]
        yield u


if __name__ == "__main__":
    rng = RNG(1, 2, 3, 4, 5, 6)
    for i in range(10):
        print(next(rng))
