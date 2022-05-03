// Winter'22
// Instructor: Diba Mirza
// Student name: Lizette Crooks
// perm #4087193
// 3/2/22

/* TODO:
Part 1:
  1. create set ✓
  2. read in file and store in set ✓
  3. print correctly ✓
Part 2:
  1. create max-heap priority queue ✓
  2. take in prefix and add to heap ✓
  3. print correctly ✓
Part 3:
  1. big-o analysis
*/

// lecture code about set: https://github.com/ucsb-cs24-w22/cs24-w22-lectures/tree/main/lect15
// lecture code about heap: https://github.com/ucsb-cs24-w22/cs24-w22-lectures/blob/main/lect16/pq.cpp

#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>

#include <iostream>
using namespace std;

#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 2){
    cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
    cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
    exit(1);
  }

  ifstream movieFile (argv[1]);

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[1];
    exit(1);
  }
  
// PART 1
// using set
set<Movie> mList;
Movie inMovie;

string line, movieName;
double movieRating;
// Read each file and store the name and rating
while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
  // string movieName and double movieRating

  inMovie.setMovie(movieName);
  inMovie.setScore(movieRating);
  
  mList.insert(inMovie);

}

movieFile.close();

if(argc == 2){
  //print all the movies in ascending alphabetical order of movie names
  for(auto inMovie: mList){
    cout.precision(1);
    cout << inMovie.getMovie() << ", " << fixed << inMovie.getScore() << endl;
  }

  return 0;
}


//PART 2
string bestMovie = "";

if (argc > 2) {

  priority_queue<Movie, vector<Movie>, myFunctor> pq;

  int numPrefix = argc;
  int currPrefix = 2;

  // overall m*( O(n + k*log(k)) + O(k*log(k) ) --> O(m*(n + 2klog(k)) --> O(m*n + m*k*log(k))
  while (currPrefix != numPrefix) {   // loop runs m times for # of prefixes
    
    set<Movie>::iterator current;
    current = mList.begin();
    set<Movie>::iterator lEnd;
    lEnd = mList.end();

    Movie maxMovie {" ", 0.0};

    int length = strlen(argv[currPrefix]);

    // overall, O(n + k*log(k))
    while (!(current == lEnd)) {    // O(n) - runs n times for # of movies in set
      if (current->getMovie().substr(0, length) == argv[currPrefix]) {
        if (current->getScore() > maxMovie.getScore()) {
          maxMovie.setMovie(current->getMovie());
          maxMovie.setScore(current->getScore());
        }
        pq.push(*current);    // O(k*log(k)) - priority queue push for a matching movie to prefix, occurs k times
      }
      current++;
    }

    if (pq.empty()) {
      cout << "No movies found with prefix " << argv[currPrefix] << endl;
    }

    if (!pq.empty()) {
      if (maxMovie.getScore() == 10) {
        bestMovie = bestMovie + "Best movie with prefix " + argv[currPrefix] + " is: " + maxMovie.getMovie() + " with rating " + to_string(maxMovie.getScore()).substr(0, 4) + "\n";
      }
      else {
        bestMovie = bestMovie + "Best movie with prefix " + argv[currPrefix] + " is: " + maxMovie.getMovie() + " with rating " + to_string(maxMovie.getScore()).substr(0, 3) + "\n";
      }
    }

    // overall, O(k*log(k))
    while(!pq.empty()){ // loop runs k times until empty
        cout << pq.top().getMovie() << ", " << fixed << setprecision(1) << pq.top().getScore() << endl;
        pq.pop();   // O(log(k)) - priority queue pop 
    }

    cout << endl;

    currPrefix++;
  }

}
    
cout << bestMovie;

return 0;

}


// PART 3
/* 
note: ignoring O(1) work

The overarching while loop, while(currPrefix != numPrefix), runs m times for # of prefixes
Within it, there are two other while loops:
  -loop 1, while(!(current == lEnd))
    the loop runs n times for # of movies in set
    does a push into a pq when match exists, O(log(k)), where k is # of successful matches
      - it does this k times so, O(k*log(k))
    so overall running time for loop 1 is O(n + k*log(k))
      -note: worst case we run loop n times and there are n matches
  -loop 2, while(!pq.empty())
    loop runs k times until empty
    does a pop from pq, O(log(k))
    so overall running time for loop 2 is O(k*log(k))
So the overall running time for part 2 is m*( O(n + k*log(k)) + O(k*log(k) ) 
--> O(m*(n + 2*k*log(k)) 
--> O(m*(n + k*log(k))

*/




bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
		  if(i==0 && line[0]=='"') continue;
		  if(line[i]=='"'){ i++; flag=true; continue;}
		  movieName += line[i];
	  }
  }
  
  movieRating = stod(tempRating);
  return true;
}