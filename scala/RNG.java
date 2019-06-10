public class RNG {
	private long[] A;
	private long[] B;
	public RNG() {
		A = new long[4];
		B = new long[4];
	}
	public RNG(long[] seed) {
		A = new long[4];
		B = new long[4];
		A[0] = 0;
		A[1] = seed[0] % 4294967087L;
		A[2] = seed[1] % 4294967087L;
		A[3] = seed[2] % 4294967087L;
		B[0] = 0;
		B[1] = seed[3] % 4294967087L;
		B[2] = seed[4] % 4294967087L;
		B[3] = seed[5] % 4294967087L;
	}
	
	public double next() {
		// Arena RNG
		A[0] = (1403580L*A[2] - 810728L*A[3]) % 4294967087L;
		B[0] = (527612L*B[1] - 1370589L*B[3]) % 4294944443L;
		long Z = (A[0] - B[0]) % 4294967087L;
		Z += (Z < 0) ? 4294967087L : 0L;
		if (Z < 0)
			throw new RuntimeException("RNG INTERNAL ERROR!");
		double U = 0;
		if (Z > 0)
			U = ((double)Z)/4294967087L;
		else
			U = ((double)4294967087L)/4294967088L;

		A[3] = A[2];
		A[2] = A[1];
		A[1] = A[0];
		B[3] = B[2];
		B[2] = B[1];
		B[1] = B[0];
		
		return U;
	}
}
