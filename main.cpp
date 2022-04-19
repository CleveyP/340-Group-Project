// main file for movies group project for 340
#include "functions.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fileIn;
    fileIn.open("csvs//tmdb_5000_credits.csv");
    if (!fileIn.is_open()) {
        cout << "failed" << endl;
    }
    else{
        //Not functioning correctly, only printing out "movie_id,title,cast,crew"
        string fileNum1;
        fileIn >> fileNum1;
        cout << fileNum1 << endl;
    }
    return 0;
}
