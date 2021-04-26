let
    include("rng.jl")

    rng = RNG.ArenaIter(1, 2, 3, 4, 5, 6)

    count = 0
    for i in rng 
        println(i)
        count += 1
        if count ≥ 10 
            break
        end
    end
end