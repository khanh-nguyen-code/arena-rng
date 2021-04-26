package rng

// RNG : Random Number Generator
type RNG interface {
	Next() float64
}

// NewArenaRNG : create new RNG
func NewArenaRNG(seed [6]int64) RNG {
	return &arenaRNG{
		[4]int64{0, seed[0], seed[1], seed[2]},
		[4]int64{0, seed[3], seed[4], seed[5]},
	}
}
