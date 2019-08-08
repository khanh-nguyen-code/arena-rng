package main

import (
	"fmt"
	"rng"
)

func main() {
	seed := [6]int64{1, 2, 3, 4, 5, 6}
	gen := rng.NewRNG(seed)
	for i := 0; i < 10; i++ {
		fmt.Printf("%f\n", gen.Next())
	}
}
