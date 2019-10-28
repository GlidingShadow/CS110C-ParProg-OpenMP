# A list of files to use during compilation
# Remember to update for each file added

omphead = o-mp-headers

srcfiles = main.cpp $(omphead)/parallelFor.cpp $(omphead)/parallelSearch.cpp

objfiles = main.o $(omphead)/parallelFor.o $(omphead)/parallelSearch.o

all : $(srcfiles)
	g++ -c main.cpp -fopenmp
	g++ -c $(omphead)/parallelFor.cpp -o $(omphead)/parallelFor.o -fopenmp
	g++ -c $(omphead)/parallelSearch.cpp -o $(omphead)/parallelSearch.o -fopenmp

build : $(objfiles)
	g++ -o o-mp.out $^ -fopenmp

buildtest : $(objfiles)
	g++ -o o-mp_test.out $^ -fopenmp
