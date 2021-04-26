#ifndef _RNG_H_
#define _RNG_H_
#include<cstdint>
#include<array>

class rng {
public:
    virtual ~rng() = default;
    virtual double next() = 0;
};

class arena_rng final: public rng {
public:
    ~arena_rng() final = default;
    explicit arena_rng(const std::array<int64_t, 6>& seed);
	double next() final;
private:
	std::array<int64_t, 4> a{};
	std::array<int64_t, 4> b{};
};
arena_rng::arena_rng(const std::array<int64_t, 6>& seed) {
    a[0] = 0;
    a[1] = seed[0];
    a[2] = seed[1];
    a[3] = seed[2];
    b[0] = 0;
    b[1] = seed[3];
    b[2] = seed[4];
    b[3] = seed[5];
}

double arena_rng::next() {
    a[0] = (1403580 * a[2] - 810728 * a[3]) % 4294967087; // might be negative
    b[0] = (527612 * b[1] - 1370589 * b[3]) % 4294944443; // might be negative
    int64_t z = (a[0] - b[0]) % 4294967087; // might be negative
    z += (z < 0) ? 4294967087 : 0; // positivify
    double u = (z > 0) ? static_cast<double>(z)/4294967087.0 : 4294967087.0 / 4294967088.0;
    // shift
    a[3] = a[2];
    a[2] = a[1];
    a[1] = a[0];
    b[3] = b[2];
    b[2] = b[1];
    b[1] = b[0];
    return u;
}
#endif // _RNG_H_
