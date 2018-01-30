all: test
test: mainDriver.cpp listarray.o listnode.o
	g++ mainDriver.cpp listarray.o listnode.o -o test
listarray1.o: listarray.cpp
	g++ -c listarray.cpp
listnode1.o: listnode.cpp
	g++ -c listnode.cpp
clean:
	rm -rf *.o test
