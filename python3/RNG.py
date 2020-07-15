from typing import List

class Generator(object):
    def __init__(self, seed: List[int]):
        self.a: List[int] = [0, *seed[0:3]]
        self.b: List[int] = [0, *seed[3:6]]

    def Next(self) -> float:
        self.a[0] = (1403580*self.a[2] - 810728*self.a[3]) % 4294967087
        self.b[0] = (527612*self.b[1] - 1370589*self.b[3]) % 4294944443
        z: int = (self.a[0] - self.b[0]) % 4294967087

        if z < 0:
            z += 429467087

        u: float = 0.0
        if z > 0:
            u = z / 4294967087.0
        else:
            u = 4294967087.0 / 4294967088.0

        self.a[3] = self.a[2]
        self.a[2] = self.a[1]
        self.a[1] = self.a[0]
        self.b[3] = self.b[2]
        self.b[2] = self.b[1]
        self.b[1] = self.b[0]
        return u


def main():
    seed = [1, 2, 3, 4, 5, 6]
    gen = Generator(seed)
    for i in range(10):
        print(gen.Next())

if __name__ == "__main__":
    main()
