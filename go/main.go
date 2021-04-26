package main

import (
	"fmt"
	"github.com/khanhhhh/arena-rng/go/rng"
)

func main() {
	seed := [6]int64{1, 2, 3, 4, 5, 6}
	gen := rng.NewArenaRNG(seed)
	for i := 0; i < 10; i++ {
		fmt.Println(gen.Next())
	}
}
