#include <iostream>
#include "rng.h"

int main() {
    auto s = rng({1, 2, 3, 4, 5, 6});
    for (int i=0; i<10; i++) {
        std::cout << s.next() << std::endl;
    }
    return 0;
}
