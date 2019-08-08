#include<RNG.hh>
#include<iostream>
int main() {
	int64_t seed[6] = {1,2,3,4,5,6};
	auto gen = RNG(seed);
	for (int i=0; i<10; i++) {
		std::cout<<gen.Next()<<std::endl;
	}
}
