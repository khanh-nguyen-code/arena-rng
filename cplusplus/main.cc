#include<RNG.hh>
#include<iostream>
int main() {
	std::array<int64_t, 6> seed = {1,2,3,4,5,6};
	auto gen = RNG(seed);
	for (int i=0; i<10; i++) {
		std::cout<<gen.Next()<<std::endl;
	}
}
