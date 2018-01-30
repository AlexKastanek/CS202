all: stack
stack: main.cpp stack.o
	g++ main.cpp stack.o -o stack
stack.o: stack.cpp
	g++ -c stack.cpp
clean:
	rm -rf *.o stack
