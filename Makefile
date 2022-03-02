# Lizette Crooks
# perm 4087193
# 3/2/22

CXX = g++
CXXFLAGS = --std=c++11 -g

runMovies: movies.o main.o
	${CXX}  ${CXXFLAGS} movies.o main.o -o runMovies

clean:
	rm -f *.o runMovies