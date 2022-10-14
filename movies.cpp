// Lizette Crooks
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

double Movie::getScore() const {
    return score;
}

// setters
void Movie::setMovie(string newMovie) {
    movie = newMovie;
}

void Movie::setScore(double newScore) {
    score = newScore;
}

// overloaded operators
bool operator==(const Movie& m1, const Movie& m2) {
    if (m1.getMovie() == m2.getMovie() && m1.getScore() == m2.getScore()) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(const Movie& m1, const Movie& m2) {
    if (m1.getMovie() < m2.getMovie()) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(const Movie& m1, const Movie& m2) {
    if (m1.getMovie() > m2.getMovie()) {
        return true;
    }
    else {
        return false;
    }
}

