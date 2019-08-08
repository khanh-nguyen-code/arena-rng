#include"RNG.h"
#include<stdio.h>
int main() {
  int64_t seed[6] = {1, 2, 3, 4, 5, 6};
  RNG gen = _RNG.new(seed);
  for (int i=0; i<10; i++) {
    printf("%f\n", _RNG.next(gen));
  }
}