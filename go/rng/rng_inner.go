package rng

type arenaRNG struct {
	a [4]int64
	b [4]int64
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
	rng.a = [4]int64{0, rng.a[0], rng.a[1], rng.a[2]}
	rng.b = [4]int64{0, rng.b[0], rng.b[1], rng.b[2]}
	return u
}
