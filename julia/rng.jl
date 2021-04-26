module RNG
    struct ArenaIter
        a::NTuple{3, Int64}
        b::NTuple{3, Int64}
        function ArenaIter(a::NTuple{3, Int64}, b::NTuple{3, Int64})
            new(a, b)
        end
        # custom constructor
        function ArenaIter(seed::Vararg{Int64, 6})
            new(seed[1:3], seed[4:6])
        end
    end
    function next(iter::ArenaIter)::Tuple{Float64,ArenaIter}
        a = (1403580 * iter.a[2] - 810728 * iter.a[3]) % 4294967087  # might be negative
        b = (527612 * iter.b[1] - 1370589 * iter.b[3]) % 4294944443  # might be negative
        z = (a - b) % 4294967087
        z += (z < 0) ? 4294967087 : 0 # positivify
        u = (z > 0) ? convert(Float64, z) / 4294967088.0 : 4294967087.0 / 4294967088.0
        u, ArenaIter((a, iter.a[1], iter.a[2]), (b, iter.b[1], iter.b[2]))
    end
    # iteration
    function Base.iterate(iter::ArenaIter)::Union{Nothing, Tuple{Float64, ArenaIter}}
        next(iter)
    end
    function Base.iterate(iter::ArenaIter, state::ArenaIter)::Union{Nothing, Tuple{Float64, ArenaIter}}
        next(state)
    end
end