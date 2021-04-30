module RNG
    struct State
        a::NTuple{3, UInt64}
        b::NTuple{3, UInt64}
        # constructor
        function State(seed::Vararg{Int, 6})::State
            for i in 1:6
                @assert 0 ≤ seed[i] < 2^32 "seed[$i] must be in range [0, 2^32)"
            end
            new(seed[1:3], seed[4:6])
        end
        # default constructor
        function State(a::NTuple{3, UInt64}, b::NTuple{3, UInt64})::State
            new(a, b)
        end
    end

    function next(state::State)::Tuple{Float64, State}
        # each component always in range [0, 2^64)
        # a, b always in range [0, 2^32)
        a = (1403580 * state.a[2] + (4294967087 - 810728) * state.a[3]) % 4294967087
        b = (527612 * state.b[1] + (4294944443 - 1370589) * state.b[3]) % 4294944443
        # z always in range [1, 4294967087]
        z = (a + 4294967087 - b) % 4294967087 + 1 # shifted by +1 comparing to arena
        u = Float64(z) / 4294967088.0
        # return
        u, State((a, state.a[1], state.a[2]), (b, state.b[1], state.b[2]))
    end

    # iteration
    function Base.iterate(iter::State)::Union{Nothing, Tuple{Float64, State}}
        next(iter)
    end
    function Base.iterate(iter::State, state::State)::Union{Nothing, Tuple{Float64, State}}
        next(state)
    end
end

rng = RNG.State(1, 2, 3, 4, 5, 6)
for (i, rand) in zip(1:100, rng)
    println("$i: $rand")
end