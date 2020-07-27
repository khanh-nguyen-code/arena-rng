#include"rng.h"
#include<stdio.h>
struct rng_state rng = {
  {0, 1, 2, 3},
  {4, 5, 6, 7},
};
int main() {
  for (int i=0; i<10; i++) {
    printf("%f\n", rng_next(&rng));
  }
}
