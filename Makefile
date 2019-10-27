# A list of files to use during compilation
# Remember to update for each file added

omphead = o-mp-headers

srcfiles = o-mp.cpp $(omphead)/parallelFor.cpp $(omphead)/parallelSearch.cpp

objfiles = o-mp.o $(omphead)/parallelFor.o $(omphead)/parallelSearch.o

all : $(srcfiles)
	g++ -c $^ -fopenmp

build : $(objfiles)
	g++ -o o-mp.out $^ -fopenmp

buildtest : $(objfiles)
	g++ -o o-mp_test.out $^ -fopenmp
