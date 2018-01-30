all: stack
stack: mainDriver.cpp stack1.o
	g++ mainDriver.cpp stack1.o -o stack
stack1.o: stack1.cpp
	g++ -c stack1.cpp
clean:
	rm -rf *.o stack
