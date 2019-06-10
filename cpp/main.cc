#include<RNG.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
int length = 100000;
int main() {
	int64_t seed[6] = {1,2,3,4,5,6};
	auto gen = RNG(seed);
	auto data = std::vector<double>(length);
	for (int i=0; i<length; i++) {
		data[i] = gen.next();
	}

	std::sort(data.begin(), data.end());
	auto& sorted = data;

	auto baseline = std::vector<double>(length);
	std::generate(baseline.begin(), baseline.end(), 
			[] (void) -> int {
				static int i = 0.0;
				return i++;
			}
	);
	auto baselinemin = std::vector<double>(length);
	auto baselinemax = std::vector<double>(length);
	std::transform(baseline.begin(), baseline.end(), baselinemin.begin(), 
		[] (double x) -> double {
			return x / length;
		}		
	);
	std::transform(baseline.begin(), baseline.end(), baselinemax.begin(), 
		[] (double x) -> double {
			return (1+x) / length;
		}		
	);

	auto diffmin = std::vector<double>(length);
	auto diffmax = std::vector<double>(length);

	std::transform(sorted.begin(), sorted.end(), baselinemin.begin(), diffmin.begin(), 
		[] (double x, double y) -> double {
			return x - y;
		}		
	);
	std::transform(sorted.begin(), sorted.end(), baselinemax.begin(), diffmax.begin(), 
		[] (double x, double y) -> double {
			return y - x;
		}		
	);

	double max1 = *std::max_element(diffmin.begin(), diffmin.end());
	double max2 = *std::max_element(diffmax.begin(), diffmax.end());

	auto d = (max1 > max2) ? max1 : max2;
	std::cout<<"D\t"<<d<<std::endl;
	auto dbase = 2 / std::sqrt(length);
	std::cout<<"D base\t"<<dbase<<std::endl;
}
