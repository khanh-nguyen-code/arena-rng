package rng

// RNG : Random Number Generator
type RNG interface {
	Next() float64
}

type rng struct {
	a [4]int64
	b [4]int64
}

// NewRNG : create new RNG
func NewRNG(seed [6]int64) RNG {
	r := rng{}
	r.a[0] = 0
	r.a[1] = seed[0]
	r.a[2] = seed[1]
	r.a[3] = seed[2]
	r.b[0] = 0
	r.b[1] = seed[3]
	r.b[2] = seed[4]
	r.b[3] = seed[5]
	return RNG(&r)
}

func (r *rng) Next() float64 {
	r.a[0] = (1403580*r.a[2] - 810728*r.a[3]) % 4294967087
	r.b[0] = (527612*r.b[1] - 1370589*r.b[3]) % 4294944443
	var z int64 = (r.a[0] - r.b[0]) % 4294967087
	if z < 0 {
		z += 429467087
	}
	var u float64
	if z > 0 {
		u = float64(z) / 4294967087.0
	} else {
		u = 4294967087.0 / 4294967088
	}
	r.a[3] = r.a[2]
	r.a[2] = r.a[1]
	r.a[1] = r.a[0]
	r.b[3] = r.b[2]
	r.b[2] = r.b[1]
	r.b[1] = r.b[0]
	return u
}
