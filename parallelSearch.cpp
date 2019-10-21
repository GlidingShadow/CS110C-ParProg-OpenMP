#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <chrono>
#include <vector>

#include "parallelSearch.hpp"

long sequentialSearch(std::vector<int> d_set, int search)
{

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < d_set.size(); i++) {

		if (search == d_set.at(i)) {

			break;

		}
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration =
	    std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
	long time = duration.count();

	return time;

}

long parallelSequentialSearch(std::vector<int> d_set, int search)
{

	auto start = std::chrono::high_resolution_clock::now();

	int i = 0;
	#pragma omp parallel private(i) shared(d_set)
	#pragma omp parallel for schedule(static, 10000)
	for (i = 0; i < 1000; i++) {

		if (search == d_set.at(i)) {

			#pragma omp cancel for

		}
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration =
	    std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
	long time = duration.count();

	return time;
}

/*
int main()
{

	std::vector<int> v;

	for(int i = 0; i < 5000000; i++) {
		v.push_back(i);
	}

	long c = sequentialSearch(v, 678);
	long d = parallelSequentialSearch(v,678);

	std::cout << "sequentialSearch(): " << c
		  << "\nparallelSequential(): " << d
		  << std::endl;

	if(d<c) {

		std::cout <<"searched() successful!"<<std::endl;
	}
	else {

		std::cout <<"search failed!"<<std::endl;

	}

	return 0;

}
*/
