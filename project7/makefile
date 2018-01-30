all: Polynomial
Polynomial: testDriver.cpp Polynomial.o
	g++ testDriver.cpp Polynomial.o -o Polynomial
Polynomial.o: Polynomial.cpp
	g++ -c Polynomial.cpp
clean:
	rm -rf *.o Polynomial
