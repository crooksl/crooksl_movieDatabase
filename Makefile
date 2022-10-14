# Lizette Crooks
# 3/2/22

CXX = g++
CXXFLAGS = --std=c++11 -g

runMovies: movies.o main.o
	${CXX}  ${CXXFLAGS} movies.o main.o -o runMovies

movies.o:
	${CXX}  ${CXXFLAGS} -c movies.cpp

main.o:
	${CXX}  ${CXXFLAGS} -c main.cpp

clean:
	rm -f *.o runMovies