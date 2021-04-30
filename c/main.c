#include <stdio.h>
#include "arena_rng.h"

int main() {
    int64_t seed[6] = {1, 2, 3, 4, 5, 6};
    struct rng_state state = rng_state_new(seed);
    for (int i=0; i<10; i++) {
        struct rng_result result = rng_state_next(state);
        state = result.state;
        printf("%f\n", result.value);
    }
    return 0;
}
