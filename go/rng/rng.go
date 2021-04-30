package rng

// ArenaState : Random Number Generator
type ArenaState struct {
	a [3]int64
	b [3]int64
}

func New(seed [6]int64) ArenaState {
	return ArenaState{
		a: [3]int64{seed[0], seed[1], seed[2]},
		b: [3]int64{seed[3], seed[4], seed[5]},
	}
}

func (state ArenaState) Next() (nextState ArenaState, value float64) {
	var a int64 = (1403580*state.a[1] - 810728*state.a[2]) % 4294967087 // might be negative
	var b int64 = (527612*state.b[0] - 1370589*state.b[2]) % 4294944443 // might be negative
	var z int64 = (a - b) % 4294967087
	if z <= 0 {
		// positivify, set z to 4294967087 if z == 0
		z += 4294967087
	}
	value = float64(z) / 4294967088.0
	return ArenaState{
		a: [3]int64{a, state.a[0], state.a[1]},
		b: [3]int64{b, state.b[0], state.b[1]},
	}, value
}
