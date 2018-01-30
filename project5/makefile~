all: test
test: testDriver.cpp String.o
	g++ testDriver.cpp String.o -o test
string.o: String.cpp
	g++ -c String.cpp
clean:
	rm -rf *.o test
