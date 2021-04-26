class ArenaRNG {
    constructor(seed) {
        this.a = [0, seed[0], seed[1], seed[2]];
        this.b = [0, seed[3], seed[4], seed[5]];
    }
    Next() {
        this.a[0] = (1403580 * this.a[2] - 810728 * this.a[3]) % 4294967087; // might be negative
        this.b[0] = (527612 * this.b[1] - 1370589 * this.b[3]) % 4294944443; // might be negative
        let z = (this.a[0] - this.b[0]) % 4294967087;
        if (z < 0) {
            // positivify
            z += 4294967087;
        }
        let u = 4294967087.0 / 4294967088.0;
        if (z > 0) {
            u = z / 4294967087.0;
        }
        // shift
        this.a = [0, this.a[0], this.a[1], this.a[2]];
        this.b = [0, this.b[0], this.b[1], this.b[2]];
        return u;
    };
}

module.exports = {ArenaRNG};
