/*
Stephen Martel
4/24/2022

A file that holds functions that allows this to run as a program that can take inputs

*/

#include <iostream>

using namespace std;



// This function will request a year range from a user repeatedly until they give a correct input, or the program crashes when they put in a letter...

void requestYearRange(int &startingYear, int &endingYear)
{
    // Get a proper starting year
    while (startingYear < 1916 || startingYear > 2017) // While the input is outside the valid range, rerun this until it is
    {
        cout << "Enter a starting year between 1916 and 2017: ";
        cin >> startingYear; // Insert user input into starting year variable
    }

    // Get a proper ending year
    while (endingYear < startingYear || endingYear > 2017) // While the input is outside the valid range or less than the starting year, keep asking for an input until it is
    {
        cout << "Enter an ending year from " << startingYear << " to 2017: ";
        cin >> endingYear; // Insert user input into ending year variable
    }
        //cout << "\nYear range designated as: " << startingYear << " to " << endingYear << endl << endl;    

}

// Take in the struct to draw from first, and a second to save to. Also take in two ints, the first being the starting year, the second being the ending year
// Save a new vector that is filled with structs in the given year range from the first input vector (primary).
void applyYearRange(vector<combinedMovieStruct *> primaryStructVector, vector<combinedMovieStruct *> &newYearRangeVec, int startingYear, int endingYear){
    cout << "Limiting the database to year range: " << startingYear << " to " << endingYear << endl;
    newYearRangeVec = limitYearRangeOfStructVec(primaryStructVector, startingYear, endingYear);
    cout << "Database year range applied" << endl << endl;
}


// This function will print the list of options
void displayMainMenu(){
    cout << "\nMain Menu" << endl;
    cout << "__________" << endl;

    cout << "1  Most common actors in the highest grossing movies from this period?" << endl;
    cout << "2  Which genres of movies were most popular during this time period?" << endl;
    cout << "3  Additional Sorting Options! (Revenue, Profit, Release Year, Rating, Popularity)" << endl;
    cout << "4  Choose a new year range" << endl;
    cout << "5  Quit - Exit - GET ME OUT OF HERE!" << endl;
    cout << "\nWhat would you like to do? Enter number (1-5): ";

    
}

// This function will print the alternative sorting menu (accessed via option 3 on main menu)
void displayAltMenu(){
    cout << "\nWelcome to the alternative sorting option menu.\n" << endl;
    cout << "1  Revenue" << endl;
    cout << "2  Profit - (Budget minus Revenue)" << endl;
    cout << "3  Release date (by year)" << endl;
    cout << "4  Rating" << endl;
    cout << "5  Popularity - (Revenue times Rating)" << endl;
    cout << "6  Back to main menu" << endl;
    cout << "\nWhat would you like to do? Enter number (1-6): ";

}
