#ifndef _RNG_PUBLIC_HH_
#define _RNG_PUBLIC_HH_
#include<array>
struct RNG {
	// no need padding here
	RNG(const std::array<int64_t, 6>& seed);
	double Next();
	// padding (not necessary)
	std::array<int64_t, 8> _;
};
#endif
