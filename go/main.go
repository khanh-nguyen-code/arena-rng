package main

import (
	"fmt"
	"github.com/khanhhhh/arena-rng/go/rng"
)

func main() {
	seed := [6]int64{1, 2, 3, 4, 5, 6}
	state := rng.New(seed)
	var value float64
	for i := 0; i < 10; i++ {
		state, value = state.Next()
		fmt.Println(value)
	}
}
