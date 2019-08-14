class RNG {
    constructor(seed) {
        this._a = [0, seed[0], seed[1], seed[2]];
        this._b = [0, seed[3], seed[4], seed[5]];
    }
    get a() {
        return this._a;
    }
    get b() {
        return this._b;
    }
    Next() {
        this._a[0] = (1403580 * this._a[2] - 810728 * this._a[3]) % 4294967087;
        this._b[0] = (527612 * this._b[1] - 1370589 * this._b[3]) % 4294944443;
        var z = (this._a[0] - this._b[0]) % 4294967087;
        if (z < 0) {
            z += 429467087;
        }
        var u = 4294967087.0 / 4294967088.0;
        if (z > 0) {
            u = z / 4294967087.0;
        }
        this._a[3] = this._a[2];
        this._a[2] = this._a[1];
        this._a[1] = this._a[0];
        this._b[3] = this._b[2];
        this._b[2] = this._b[1];
        this._b[1] = this._b[0];
        return u;
    };
}

function main() {
    var seed = [1, 2, 3, 4, 5, 6];
    var gen = new RNG(seed);
    for (var i = 0; i < 10; i++) {
        console.log(gen.Next());
    }
}
main();
