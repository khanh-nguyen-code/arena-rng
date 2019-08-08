#ifndef _RNG_HH_
#define _RNG_HH_
#include<cstdint>
#include<array>
class RNG {
private:
	std::array<int64_t, 4> a;
	std::array<int64_t, 4> b;
public:
	RNG() {}
	RNG(int64_t *seed) {
		a[0] = 0;
		a[1] = seed[0];
		a[2] = seed[1];
		a[3] = seed[2];
		b[0] = 0;
		b[1] = seed[3];
		b[2] = seed[4];
		b[3] = seed[5];
	}
	double Next() {
		a[0] = (1403580 * a[2] - 810728 * a[3]) % 4294967087;
		b[0] = (527612 * b[1] - 1370589 * b[3]) % 4294944443;
		int64_t z = (a[0] - b[0]) % 4294967087;
		z += (z < 0) ? 4294967087 : 0;
		double u = (z > 0) ? 
		static_cast<double>(z)/4294967087.0 : 4294967087.0 / 4294967088.0;
		a[3] = a[2];
		a[2] = a[1];
		a[1] = a[0];
		b[3] = b[2];
		b[2] = b[1];
		b[1] = b[0];
		return u;
	}
};
#endif
