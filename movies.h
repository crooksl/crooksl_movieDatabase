// Lizette Crooks
// perm #4087193
// 3/2/22

/* TODO:
    1. create class Movie
    2. define constructors, destructors, etc
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;


class Movie {
    public:
        Movie(string mv = "", int sc = 0): movie(mv), score(sc) {}
        ~Movie();
        string getMovie() const;
        int getScore() const;
        void setMovie(string newSuit);
        void setScore(int newNumber);
        
    private:
        string movie;
        int score;
};


#endif