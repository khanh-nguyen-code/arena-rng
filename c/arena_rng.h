//
// Created by Khanh Nguyen Ngoc on 30/4/21.
//

#ifndef C_ARENA_RNG_H
#define C_ARENA_RNG_H

#include <stdint.h>

struct rng_state {
    int64_t a[3];
    int64_t b[3];
};

struct rng_result {
    struct rng_state state;
    double value;
};

struct rng_state rng_state_new(const int64_t seed[6]) {
    struct rng_state state = {
            {seed[0], seed[1], seed[2]},
            {seed[3], seed[4], seed[5]},
    };
    return state;
}

struct rng_result rng_state_next(struct rng_state state) {
    int64_t a = (1403580 * state.a[1] - 810728 * state.a[2]) % 4294967087; // might be negative
    int64_t b = (527612 * state.b[0] - 1370589 * state.b[2]) % 4294944443; // might be negative
    int64_t z = (a - b) % 4294967087;
    z += (z <= 0) ? 4294967087 : 0; // positivify, set z to 4294967087 if z == 0
    double u = ((double) z) / 4294967088.0;
    struct rng_state next_state = {
            {a, state.a[0], state.a[1]},
            {b, state.b[0], state.b[1]},
    };
    struct rng_result result = {
            next_state,
            u,
    };
    return result;
}


#endif //C_ARENA_RNG_H
