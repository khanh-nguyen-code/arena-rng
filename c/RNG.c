#include"RNG.h"
#include<stdlib.h>
RNG* rng_make(int64_t seed[6]) {
  RNG *this = malloc(sizeof(RNG));
  this->a[0] = 0;
  this->a[1] = seed[0];
  this->a[2] = seed[1];
  this->a[3] = seed[2];
  this->b[0] = 0;
  this->b[1] = seed[3];
  this->b[2] = seed[4];
  this->b[3] = seed[5];
  return this;
}
double rng_next(RNG* this) {
  this->a[0] = (1403580 * this->a[2] - 810728 * this->a[3]) % 4294967087;
	this->b[0] = (527612 * this->b[1] - 1370589 * this->b[3]) % 4294944443;
	int64_t z = (this->a[0] - this->b[0]) % 4294967087;
	z += (z < 0) ? 4294967087 : 0;
	double u = (z > 0) ? 
	((double)z)/4294967087.0 : 4294967087.0 / 4294967088.0;
	this->a[3] = this->a[2];
	this->a[2] = this->a[1];
	this->a[1] = this->a[0];
	this->b[3] = this->b[2];
	this->b[2] = this->b[1];
	this->b[1] = this->b[0];
	return u;
}
struct rng_trait _RNG = {
  rng_make,
  rng_next
};
