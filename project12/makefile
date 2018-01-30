all: test
test: mainDriver.cpp inheritance.o
	g++ mainDriver.cpp inheritance.o -o test
inheritance1.o: inheritance.cpp
	g++ -c inheritance.cpp
clean:
	rm -rf *.o inheritance
