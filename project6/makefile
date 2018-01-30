all: Agency
Agency: testDriver.cpp Agency.o
	g++ testDriver.cpp Agency.o -o Agency
Agency.o: Agency.cpp
	g++ -c Agency.cpp
clean:
	rm -rf *.o Agency
