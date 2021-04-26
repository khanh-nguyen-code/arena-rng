package rng

// RNG : Random Number Generator
type RNG interface {
	Next() float64
}

type arenaRNG struct {
	a [4]int64
	b [4]int64
}

// NewArenaRNG : create new RNG
func NewArenaRNG(seed [6]int64) RNG {
	return &arenaRNG{
		[4]int64{0, seed[0], seed[1], seed[2]},
		[4]int64{0, seed[3], seed[4], seed[5]},
	}
}

func (rng *arenaRNG) Next() float64 {
	rng.a[0] = (1403580*rng.a[2] - 810728*rng.a[3]) % 4294967087 // might be negative
	rng.b[0] = (527612*rng.b[1] - 1370589*rng.b[3]) % 4294944443 // might be negative
	var z = (rng.a[0] - rng.b[0]) % 4294967087                   // might be negative
	if z < 0 {
		// positivify
		z += 4294967087
	}
	var u float64
	if z > 0 {
		u = float64(z) / 4294967087.0
	} else {
		u = 4294967087.0 / 4294967088.0
	}
	// shift
	rng.a[3] = rng.a[2]
	rng.a[2] = rng.a[1]
	rng.a[1] = rng.a[0]
	rng.b[3] = rng.b[2]
	rng.b[2] = rng.b[1]
	rng.b[1] = rng.b[0]
	return u
}
