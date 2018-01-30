all: queue
queue: mainDriver.cpp queue1.o
	g++ mainDriver.cpp queue1.o -o queue
queue1.o: queue1.cpp
	g++ -c queue1.cpp
clean:
	rm -rf *.o queue
