const {ArenaRNG} = require("./rng");


let rng = new ArenaRNG([1, 2, 3, 4, 5, 6]);
for (let i = 0; i < 10; i++) {
    console.log(rng.Next());
}
