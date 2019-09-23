# A list of files to use during compilation
# Remember to update for each file added
srcfiles = o-mp.cpp

objfiles = o-mp.o

all : $(srcfiles)
	g++ -c $^

build : $(objfiles)
	ld -o o-mp $^

buildtest : $(objfiles)
	ld -o o-mp_test $^
