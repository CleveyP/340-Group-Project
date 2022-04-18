
/*
Stephen Martel
4/18/2022
WIP CSV File reader
Current can read the file properly but the delimiter is messed up

*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>


using namespace std;


// Placeholder struct for movie data
struct movieStructTest
{
  int budget = 0; // aka col 1
  vector<string> genres; // aka col 2
  string releaseDate; // aka col 12
  int revenue; // aka col 13
  string movieName; // aka col 18 title
  double rating; // aka col 19 vote avg
};


// Placeholder struct for movie credits data
struct creditsStruct
{
    string movieID; // col 1
    string title; // col 2
    string cast; // col 3
    string crew; // col 4
};


// Test method to split an input line by a given delimiter
vector<string> delimitThis (const string &splitThis, char delimiter) {
    
    int currentCol = 1;
    stringstream stringStream (splitThis);
    string dataValue;
    vector<string> splitVector;

    while (getline (stringStream, dataValue, delimiter)) {
        splitVector.push_back (dataValue);
        currentCol++;
    }
    return splitVector;
}


int main()
{
    ifstream inputFile;
    inputFile.open("./CSV Files/tmdb_5000_credits.csv");
    string currentLine; // String that stores the current line
    int lineNum = 1; // Int that tracks the current line number
    string colLabels; // String that stores the not-so-useful first line which has the column labels
    vector<string> currentLineVector;
    

    creditsStruct firstCredits;


    if(!inputFile){ // If there is no input file... (it didn't open)
        cout << "The file did not open correctly, exiting the program";
        return -1;
    }
    else{ // If the file opened successfully
        // (!inputFile.eof())
        getline(inputFile, currentLine); // stores the first line which has the column labels in it
        // ______________________________________________________________________________________

        


        getline(inputFile, currentLine);
        cout << "The first line from the opened file is ... : " << endl << currentLine << endl;
        currentLineVector = delimitThis(currentLine, ',');
        firstCredits.movieID = currentLineVector.at(0);
        firstCredits.title = currentLineVector.at(1);
        firstCredits.cast = currentLineVector.at(2);
        firstCredits.cast = currentLineVector.at(3);

        cout << "The first line movie ID is: " << firstCredits.movieID << endl;
        cout << "The first line title is: " << firstCredits.title << endl;
        cout << "The first line cast is: " << firstCredits.cast << endl;

        /*
        getline(inputFile, currentLine);
        cout << "The second line from the opened file is ... : " << endl << currentLine << endl;
        */

    }

    return 0;
}