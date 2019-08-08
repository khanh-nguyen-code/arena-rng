#ifndef _RNG_H_
#define _RNG_H_
#include<stdint.h>
struct rng;
struct rng_trait;
typedef struct rng RNG;
typedef struct rng_trait RNG_TRAIT;
struct rng {
  int64_t a[4];
  int64_t b[4];
};
struct rng_trait {
  RNG* (*make)(int64_t seed[6]);
  double (*next)(RNG* this);
};
RNG_TRAIT _RNG;
#endif