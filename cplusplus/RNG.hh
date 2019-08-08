#ifndef _RNG_PUBLIC_HH_
#define _RNG_PUBLIC_HH_
#include<array>
struct RNG {
	std::array<int64_t, 8> _; // padding
	RNG(const std::array<int64_t, 6>& seed);
	double Next();
};
#endif
