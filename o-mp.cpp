#include <iostream>
#include <vector>
#include <random>
#include <omp.h>

#include "o-mp-headers/parallelSearch.hpp"
#include "o-mp-headers/parallelFor.hpp"

int main(void)
{

	std::vector<int> v;

	for (int i = 0; i < 5000000; i++)

		v.push_back(i);

	std::random_device rd;

	int search = rd() % 5000001;

	long ss = sequentialSearch(v, search);
	long pss = parallelSequentialSearch(v, search);

	std::cout << "Measurements in nanoseconds:\n"
		  << "Sequential Search (single-thread): " << ss << std::endl
		  << "Sequential Search (multithreaded): " << pss << std::endl;

	if ( pss < ss )

		std::cout << "Parallel Sequential Search is faster!\n";

	else

		std::cout << "Parallel Sequential Search is not faster!\n";

	long sitr = nonParallelFor();
	long pitr = parallelFor();

	std::cout << "For loops iterated over 5000000 iterations (nanoseconds):\n"
		  << "Single-threaded: " << sitr << std::endl
		  << "Parallelized:    " << pitr << std::endl;

	return 0;
}
