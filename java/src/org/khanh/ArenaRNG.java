package org.khanh;

public final class ArenaRNG implements RNG {
    public ArenaRNG(long[] seed) {
        a = new long[4];
        b = new long[4];
        a[1] = seed[0];
        a[2] = seed[1];
        a[3] = seed[2];
        b[1] = seed[3];
        b[2] = seed[4];
        b[3] = seed[5];
    }
    public final double Next() {
        a[0] = (1403580L * a[2] - 810728L * a[3]) % 4294967087L; // might be negative
        b[0] = (527612L * b[1] - 1370589L * b[3]) % 4294944443L; // might be negative
        long z = (a[0] - b[0]) % 4294967087L; // might be negative
        z += (z < 0) ? 4294967087L : 0; // positivify
        double u = (z > 0) ? ((double)z)/4294967087.0 : 4294967087.0 / 4294967088.0;
        // shift
        a = new long[]{0, a[0], a[1], a[2]};
        b = new long[]{0, b[0], b[1], b[2]};
        return u;
    }
    private long[] a;
    private long[] b;
}
