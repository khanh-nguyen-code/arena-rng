#include <iostream>
#include "arena_rng.h"

int main() {
    auto s = arena_rng({1, 2, 3, 4, 5, 6});
    for (int i=0; i<10; i++) {
        std::cout << s.next() << std::endl;
    }
    return 0;
}
