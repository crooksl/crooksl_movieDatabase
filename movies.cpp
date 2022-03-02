// Lizette Crooks
// perm #4087193
// 3/2/22

#include <iostream>
using namespace std;

#include "movies.h"

// destructor
Movie::~Movie() {}

// getters
string Movie::getMovie() const {
    return movie;
}

int Movie::getScore() const {
    return score;
}

// setters
void Movie::setMovie(string newMovie) {
    movie = newMovie;
}

void Movie::setScore(int newScore) {
    score = newScore;
}
