#ifndef _RNG_HH_
#define _RNG_HH_
#include<cstdint>
#include<array>
struct RNG {
	RNG(const std::array<int64_t, 6>& seed);
	double Next();
private:
	std::array<int64_t, 4> a;
	std::array<int64_t, 4> b;
};
#endif
