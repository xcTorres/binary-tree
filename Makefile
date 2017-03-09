test : bst.o
	g++ -o test bst.o

bst.o:bst.cpp bst.h
	g++ -std=c++11 -c bst.cpp
clean:
	rm test bst.o -rf