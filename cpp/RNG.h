#ifndef _RNG_H_
#define _RNG_H_
#include<cstdint>
class RNG {
private:
	uint32_t A[4];
	uint32_t B[4];
public:
	RNG() {}
	RNG(uint32_t *seed) {
		A[0] = 0;
		A[1] = seed[0];
		A[2] = seed[1];
		A[3] = seed[2];
		B[0] = 0;
		B[1] = seed[3];
		B[2] = seed[4];
		B[3] = seed[5];
	}
	double next() {
		A[0] = (140358 * A[2] - 810728 * A[3]) % 4294967087;
		B[0] = (527612 * B[1] - 1370589 * B[3]) % 4294944443;
		uint32_t z = (A[0] - B[0]) % 4294967087;
		double u = (z > 0) ? 
		static_cast<double>(z)/4294967087 : 4294967087.0 / 4294967088;
		A[3] = A[2];
		A[2] = A[1];
		A[1] = A[0];
		B[3] = B[2];
		B[2] = B[1];
		B[1] = B[0];
		return u;
	}
};
#endif
