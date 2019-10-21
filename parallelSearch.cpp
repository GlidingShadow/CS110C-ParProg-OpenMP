#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <chrono>
#include <vector>

#include "proto-demos.hpp"

using namespace std::chrono;


long sequentialSearch(std::vector<int> v, int a)
{

	bool exists = false;

	auto start = high_resolution_clock::now();

	for (int i = 0; i < v.size(); i++) {

		if (a == v.at(i)) {

			exists = true;

		}
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	long time = duration.count();

	return time;

}

long parallelSequentialSearch(std::vector<int> v, int a)
{

	bool exists = false;

	auto start = high_resolution_clock::now();

	int i = 0;
	#pragma omp parallel private(i) shared(exists)
	#pragma omp parallel for schedule(static, 10000)
	for (i = 0; i < 1000; i++) {

		if (a == v.at(i)) {

			exists = true;

		}

	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	long time = duration.count();

	return time;
}

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
