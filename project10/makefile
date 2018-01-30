all: listnode
listnode: mainDriver.cpp listnode.o
	g++ mainDriver.cpp listnode.o -o listnode
listnode1.o: listnode.cpp
	g++ -c listnode.cpp
clean:
	rm -rf *.o listnode
