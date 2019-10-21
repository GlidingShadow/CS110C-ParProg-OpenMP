#include<iostream>
#include<omp.h>
#include<chrono>

using namespace std::chrono;

long parallelFor() {
	auto start = high_resolution_clock::now();
	#pragma omp parallel for schedule(static, 10000)
	for (unsigned i = 0; i < 5000000; ++i) {
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
  	long time = duration.count();
  	return time;
}

long nonParallelFor() {
	auto start = high_resolution_clock::now();
	for (unsigned i = 0; i < 5000000; ++i) {
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
  	long time = duration.count();
  	return time;
}

int main() {
	
  long b = nonParallelFor();
  long a = parallelFor();

 std::cout<<"parallelFor(): " << a <<"\nnonParallelFor(): " << b <<std::endl;

  if(a<b) {
    std::cout <<"parallelFor() successful!"<<std::endl;
  } else {
    std::cout <<"for() failed!"<<std::endl;
  }

	return 0;
}
