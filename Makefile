# A list of files to use during compilation
# Remember to update for each file added
srcfiles = o-mp.cpp parallelFor.cpp parallelSearch.cpp

objfiles = o-mp.o parallelFor.o parallelSearch.o

all : $(srcfiles)
	g++ -c $^ -fopenmp

build : $(objfiles)
	g++ -o o-mp.out $^ -fopenmp

buildtest : $(objfiles)
	g++ -o o-mp_test.out $^ -fopenmp
