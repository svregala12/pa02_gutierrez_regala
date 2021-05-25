# Makefile complete

CXX_FLAG = --std=c++11 -g

all: runMovies tests

runMovies: main.o movies.o utility.o
	g++ $(CXX_FLAG) -o runMovies main.o movies.o utility.o

tests: tests.o movies.o utility.o
	g++ $(CXX_FLAG) -o tests tests.o movies.o utility.o

main.o: main.cpp 
	g++ -c $(CXX_FLAG) main.cpp

movies.o: movies.cpp utility.cpp
	g++ -c $(CXX_FLAG) movies.cpp utility.cpp

tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

clean:
	rm -f runMovies tests *.o