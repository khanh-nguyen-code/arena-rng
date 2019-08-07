var RNG = /** @class */ (function () {
    function RNG(seed) {
        this.a = [0, seed[0], seed[1], seed[2]];
        this.b = [0, seed[3], seed[4], seed[5]];
    }
    RNG.prototype.next = function () {
        this.a[0] = (1403580 * this.a[2] - 810728 * this.a[3]) % 4294967087;
        this.b[0] = (527612 * this.b[1] - 1370589 * this.b[3]) % 4294944443;
        var z = (this.a[0] - this.b[0]) % 4294967087;
        if (z < 0) {
            z += 429467087;
        }
        var u = 4294967087.0 / 4294967088.0;
        if (z > 0) {
            u = z / 4294967087.0;
        }
        this.a[3] = this.a[2];
        this.a[2] = this.a[1];
        this.a[1] = this.a[0];
        this.b[3] = this.b[2];
        this.b[2] = this.b[1];
        this.b[1] = this.b[0];
        return u;
    };
    return RNG;
}());
function main() {
    var seed = [1, 2, 3, 4, 5, 6];
    var gen = new RNG(seed);
    for (var i = 0; i < 10; i++) {
        console.log(gen.next());
    }
}
main();
