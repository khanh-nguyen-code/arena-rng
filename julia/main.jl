let
    include("rng.jl")

    rng = RNG.ArenaIter(1, 2, 3, 4, 5, 6)

    for (_, rand) in zip(1:10, rng)
        println(rand) 
    end
end