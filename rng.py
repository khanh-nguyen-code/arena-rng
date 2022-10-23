from typing import Iterator
from dataclasses import dataclass

@dataclass
class State:
    a: tuple[int, int, int]
    b: tuple[int, int, int]

def new(seed: tuple[int, int, int, int, int, int]) -> State:
    return State(
        a=seed[0:3],
        b=seed[3:6],
    )

def next(state: State) -> tuple[State, float]:
    # each component always in range [0, 2^64)
    # a, b always in range [0, 2^32)
    a = (1403580 * state.a[1] + (4294967087 - 810728) * state.a[2]) % 4294967087
    b = (527612 * state.b[0] + (4294944443 - 1370589) * state.b[2]) % 4294944443
    # z always in range [1, 4294967087]
    z = (a + 4294967087 - b) % 4294967087 + 1  # shifted by +1 comparing to arena
    u = float(z) / 4294967088.0
    next_state = State(
        a=(a, *state.a[0:2]),
        b=(b, *state.b[0:2]),
    )
    # return
    return next_state, u

if __name__ == "__main__":
    state = new((1, 2, 3, 4, 5, 6))
    for i in range(100):
        state, u = next(state)
        print(f"{i}: {u}")
