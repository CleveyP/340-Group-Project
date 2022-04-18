/*ZRespicio branch*/
// main file for movies group project for 340
#include "functions.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
    Read CSV.
    Get specific column from CSV.
    Extract data from CSV and load into vector.
    Read vector, determine duplicates.
    - If found remove, create instance of original and incrememnt by 1.
    Print out table rankings.
    Library to generate charts(?)
*/

int main()
{
    ifstream fileIn; 
    fileIn.open("../tmdb_5000_movies.csv"); //Read CSV.

    if (!fileIn) {
        cerr << "The file cannot be opened. It either is misspelled or missing." << endl;
    }
    else{
        //Not functioning correctly, only printing out "movie_id,title,cast,crew"
        string fileNum1;
        fileIn >> fileNum1;
        cout << fileNum1 << endl;
    }
    return 0;
}
