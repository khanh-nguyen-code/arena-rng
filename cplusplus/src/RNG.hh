#ifndef _RNG_HH_
#define _RNG_HH_
#include<cstdint>
#include<array>
class RNG {
private:
	std::array<int64_t, 4> a;
	std::array<int64_t, 4> b;
public:
	RNG(const std::array<int64_t, 6>& seed);
	double Next();
};
#endif
