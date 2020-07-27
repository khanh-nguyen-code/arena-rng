#ifndef _RNG_H_
#define _RNG_H_
#include<stdint.h>
struct rng_state {
  int64_t a[4];
  int64_t b[4];
};
double rng_next(struct rng_state*);
#endif