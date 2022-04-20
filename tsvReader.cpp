
/*
Stephen Martel
4/19/2022
WIP TSV File reader
Current can read the file properly up until it reaches a line with an empty cell like Jurassic world

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
    string movieTitle = "";     // col 1 movie title
    int revenue = 0;            // col 2 movie revenue
    int budget = 0;             // col 3 movie budget
    vector<string> genres = {}; // col 4 movie's genres
    string releaseDate = "";    // col 5 movie's release date TO DO: YEAR ONLY for release date
    double rating = 0;          // col 6 movie average rating
    int voteCount = 0;          // col 7 store number of votes towards the rating?
};

// Struct for storing Credits.tsv data
// TO DO: Convert existing cast and crew into a vector that only has the relevant info
// FOR CAST: Only actor names, will need to be a vector
// For CREW: Probably only director name, could be a string instead
struct creditsStruct
{
    string title = ""; // col 1    Stores movie title
    string cast = "";  // col 2    Stores movie cast array
    string crew = "";  // col 3    Stores movie crew array
};

// Test function to split an input line by a given delimiter
vector<string> delimitThis(const string &lineToSplit, char delimiter)
{
    // cout << "Starting delimiting" << endl;  debug line
    int currentCol = 1;
    stringstream stringStream(lineToSplit);
    string currentStringData;
    vector<string> lineToWordsVector;

    while (getline(stringStream, currentStringData, delimiter))
    {
        lineToWordsVector.push_back(currentStringData); // Append the current string data to the vector made up of the current line
        currentCol++;
        // cout << "pushed back" << endl;
        // cout << currentStringData << endl;
        // cout << dataValue << endl
        //     << endl;
        currentStringData = ""; // Reset the current string data to empty for the next run-through
    }
    return lineToWordsVector; // Return the completed vector
}

// WIP function to extract only the useful portions of a vector so we don't have all the junk data
vector<string> convertStringToArray(string convertThis, string conversionType)
{
    vector<string> newArray = {};
    // Takes in a string to convert to an array
    // and a string that identifies which type of string this array is supposed to be
    if (convertThis.size() > 0)
    { // Failsafe to only run the function if the given string is not empty
        if (conversionType == "cast")
        {
            cout << "cast conversion" << endl; // debug print line
        }
        else if (conversionType == "crew")
        {
            cout << "crew conversion" << endl; // debug print line
        }
    }
    return newArray;
}

int main()
{
    ifstream inputFile;
    inputFile.open("./TSV Files/credits.tsv");
    string currentLine; // String that stores the current line
    int rowNum = 1;     // Int that tracks the current row number
    string colLabels;   // String that stores the not-so-useful first line which has the column labels
    vector<string> currentLineVector;

    if (!inputFile)
    { // If there is no input file... (it didn't open) then display an error message
        cout << "The file did not open correctly, exiting the program";
        return -1;
    }
    else
    {                                    // If the file opened successfully
        getline(inputFile, currentLine); // stores the first line which has the column labels in it
        // ______________________________________________________________________________________

        vector<creditsStruct *> vectorOfRowVectors; // The big vector holding all of the various row structs
        int i = 0;                                  // debugging int to find out which line this might break on

        while (!inputFile.eof()) // While not at the end of the file...
        {
            /* debugging lines
            cout << inputFile.eof() << endl;
            cout << "while loop" << endl;
            */

            getline(inputFile, currentLine);                    // Get the current row from the document
            currentLineVector = delimitThis(currentLine, '\t'); // Call the delimiter function to split this line up into columns

            // TO DO:
            // check the length of current line vector if length is 1 store title and continue, if length is 2 string find for department to determine if the 1 array is cast or crew
            // store it in the correct one, let other one stay uninitalized empty array

            creditsStruct *newRowStruct = new creditsStruct;
            (*newRowStruct).title = currentLineVector.at(0); // Save the movie title data

            // Only store cast data if it exists and it's actually the cast data, checked if it contains "character" which is exclusive to cast
            if (currentLineVector.size() >= 2 && currentLineVector.at(1).find("character") != std::string::npos)
            {
                convertStringToArray(currentLineVector.at(1), "cast");
                (*newRowStruct).cast = currentLineVector.at(1); // Save the movie cast data
            }

            // Only store crew data if it exists and it's actually the crew data (checked by if it contains department which is exclusive to crew, != npos means it's in there somewhere)
            if (currentLineVector.size() >= 3 && currentLineVector.at(2).find("department") != std::string::npos)
            {
                convertStringToArray(currentLineVector.at(2), "crew");
                (*newRowStruct).crew = currentLineVector.at(2); // Save the movie crew data
            }

            vectorOfRowVectors.push_back(newRowStruct); // Save this struct in the big vector of row structs

            cout << i << endl; // Debugging line to find out how many times this runs all the way to the end of this loop
            i++;
        }

        cout << endl;
        // Print elements of the structs to see if this works
        // cout << vectorOfRowVectors.at(0)->title << endl;
        // cout << vectorOfRowVectors.at(0)->cast << endl;
        // cout << vectorOfRowVectors.at(0)->crew << endl;
        // Testing printing loop, change increment to however many to print out
        for (int increment = 0; increment < 5; increment++)
        {
            cout << vectorOfRowVectors.at(increment)->title << endl;
        }
    }

    return 0;
}