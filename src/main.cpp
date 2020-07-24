#include <iostream>

#include "bitOperator.hpp"
#include "findLargestSum.hpp"

int main() {
    std::cout << "1/ Bit operator example : " << add(2, 5) << std::endl;

	std::cout << "2/ Find largest sum : " << std::endl;

	uint32_t T = 11;
	std::vector<uint32_t> I = {1, 2, 3, 4, 5, 6, 7};
	std::vector<uint32_t> M;
	uint32_t S=0;

	find_largest_sum(T, I, M, S);
	std::cout << "Input vector : ";
    for (auto const& v : I) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
	std::cout << "Solution vector with S=" << S << " : ";
    for (auto const& v : M) {
        std::cout << v << " ";
    }
	std::cout << std::endl;

    return 0;
}
