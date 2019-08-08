#ifndef _RNG_PUBLIC_HH_
#define _RNG_PUBLIC_HH_
#include<array>
struct RNG {
	RNG(const std::array<int64_t, 6>& seed);
	double Next();
	// padding
	std::array<int64_t, 8> _;
};
#endif
