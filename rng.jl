module RNG
    struct State
        a::NTuple{3, UInt64}
        b::NTuple{3, UInt64}
    end

    # constructor
    function New(seed::Vararg{Int, 6})::State
        State(
            map(n -> UInt64(n) % 2^32, seed[1:3]),
            map(n -> UInt64(n) % 2^32, seed[4:6]),
        )
    end

    function next(state::State)::Tuple{State, Float64}
        # each component always in range [0, 2^64)
        # a, b always in range [0, 2^32)
        a = (1403580 * state.a[2] + (4294967087 - 810728) * state.a[3]) % 4294967087
        b = (527612 * state.b[1] + (4294944443 - 1370589) * state.b[3]) % 4294944443
        # z always in range [1, 4294967087]
        z = (a + 4294967087 - b) % 4294967087 + 1 # shifted by +1 comparing to arena
        u = Float64(z) / 4294967088.0
        next_state = State((a, state.a[1], state.a[2]), (b, state.b[1], state.b[2]))
        # return
        next_state, u
    end

    # iteration
    function Base.iterate(iter::State)::Union{Nothing, Tuple{Float64, State}}
        next(iter)
    end
    function Base.iterate(iter::State, state::State)::Union{Nothing, Tuple{Float64, State}}
        next(state)
    end
end

function main()
    state = RNG.New(1, 2, 3, 4, 5, 6)
    for i in 1:100
        state, u = RNG.next(state)
        println("$i: $u")
    end
end

main()
