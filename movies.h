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
        Movie(string mv = "", double sc = 0.0): movie(mv), score(sc) {}
        ~Movie();

        string getMovie() const;
        double getScore() const;

        void setMovie(string newMovie);
        void setScore(double newScore);

        bool friend operator==(const Movie& m1, const Movie& m2);
        bool friend operator<(const Movie& m1, const Movie& m2);
        bool friend operator>(const Movie& m1, const Movie& m2);
        
    private:
        string movie;
        double score;
};

class myFunctor{
    public:
        bool operator()(Movie a, Movie b){
            if (a.getScore() == b.getScore()) {
                return a.getMovie() > b.getMovie();
            }
            else {
                return a.getScore() < b.getScore();
            }
        }
};


#endif