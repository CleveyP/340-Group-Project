/*
Stephen Martel
4/21/2022

New main file for consolidating the existing and upcoming functions into one main

*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

#include "actorFreqCounter.cpp"
#include "additionalSorting.cpp" // Additional sorting also includes tsvReaderMergedFunction: which is the way to convert the database files into a usable vector of structs
#include "genreFreqCounter.cpp"
#include "programFunctionality.cpp"

int main()
{
    // Store the primary struct resulting from the conversion of the two tsv files into a variable for use in functions later
    vector<combinedMovieStruct *> primaryStructVector = createPrimaryVectorOfStructs();
    cout << "Primary struct vector is complete" << endl;
    cout << "\nWelcome to the movie database processor" << endl;
    cout << "This database ranges from 1916 to 2017, note that some years in this database have no movies." << endl;
    cout << "To begin, first enter a starting year" << endl
         << endl;

    string userInput = "";
    int startingYear = 0;
    int endingYear = 0;
    vector<combinedMovieStruct *> yearRangeVec = {};
    bool stillRunning = true;

    // Request the input year range via function
    requestYearRange(startingYear, endingYear);

    // Create a new struct limited to the input year range
    applyYearRange(primaryStructVector, yearRangeVec, startingYear, endingYear);


    while (stillRunning)
    {
        // Print the main menu and ask for an input
        displayMainMenu();
        cin >> userInput;

        if (userInput == "1" || userInput == "2" || userInput == "3" || userInput == "4" || userInput == "5")
        {
            if (userInput == "1") // Most common actors in the highest grossing movies from this period
            {
                cout << "You have chosen: Most common actors in the highest grossing movies from " << startingYear << " to " << endingYear << endl;
                // Run a sort by descending revenue on the year-limited vector
                yearRangeVec = descendingRevenueSort(yearRangeVec);

                // Resize that newly revenue-sorted vector to the user input
                int resizeTo = 0;
                cout << "How many movies would you like to include actors from?" << endl;
                while (resizeTo < 5)
                {
                    cout << "Enter a count from 5 to " << yearRangeVec.size() << " : ";
                    cin >> resizeTo;
                }

                yearRangeVec.resize(resizeTo);

                // Construct a vector of all cast members in those movies and store them in topCastList
                vector<string> topCastList = constructMegaCastList(yearRangeVec);

                // Generate a vector of structs that contains actor name and frequency and then sort it high to low
                vector<Actor> topCastCount = generateActorFreqVec(topCastList);
                topCastCount = highFreqSort(topCastCount);

                // If the cast list was empty then print a message for that
                if (topCastCount.size() == 0)
                {
                    cout << "There were no actors in your chosen year range" << endl;
                }
                else
                {
                    cout << "\nMost common actors in the highest grossing movies from " << startingYear << " to " << endingYear << endl;
                    cout << "If this is blank, then that means that no actors starred in more than 1 film in your year range\n" << endl;
                    printFreqVec(topCastCount);
                }
                // End of Most common actors in the highest grossing movies from this period
            }

            else if (userInput == "2")
            {
                cout << "You have chosen: Which genres of movies were most popular during this time period?" << endl;
                // Run a sort by descending revenue on the year-limited vector
                yearRangeVec = descendingRevenueSort(yearRangeVec);

                // Resize that newly revenue-sorted vector to the user input
                int resizeTo = 0;
                cout << "How many movies would you like to include genres from?" << endl;
                while (resizeTo < 5)
                {
                    cout << "Enter a count from 5 to " << yearRangeVec.size() << " : ";
                    cin >> resizeTo;
                }

                yearRangeVec.resize(resizeTo);

                // Construct a vector of all genres in those movies and store them in topGenreList
                vector<string> topGenreList = constructMegaGenreList(yearRangeVec);

                // Generate a vector of structs that contains genre name and frequency and then sort it high to low
                vector<Genre> topGenreCount = generateGenreFreqVec(topGenreList);
                topGenreCount = genreHighFreqSort(topGenreCount);

                // If the cast list was empty then print a message for that
                if (topGenreCount.size() == 0)
                {
                    cout << "There were no movies with genres in your chosen year range" << endl;
                }
                else
                {
                    cout << "\nMost common genre categories of the highest grossing movies from " << startingYear << " to " << endingYear << endl;
                    cout << "If this is blank, then that means that no films had genre data for your year range\n" << endl;
                    printFreqVec(topGenreCount);
                }
                // End of Most common genres in the highest grossing movies from this period
            }
            else if (userInput == "3")
            {
                cout << "Test input 3" << endl;
            }
            else if (userInput == "4") // The user wants to change the year range
            {
                cout << "You have chosen to change your year range." << endl;
                startingYear = 0;
                endingYear = 0;
                // Repeatedly ask for year inputs
                requestYearRange(startingYear, endingYear);

                // Generate a new year range vector in the new year range
                applyYearRange(primaryStructVector, yearRangeVec, startingYear, endingYear);
                cout << "New year range " << startingYear << " to " << endingYear << " applied." << endl;
                // end of change year range
            }
            else if (userInput == "5")
            {
                cout << "Ending the program!" << endl;
                stillRunning = false; // stops this program from running
            } // end of exit program option
            // Reset user input back to blank so it doesn't keep going.
            userInput = "";
        }
        else
        {
            cout << "Your input was invalid. Please enter a number from 1 - 5: ";
        }

    } // While !exit loop

    /*
        for (size_t i = 0; i < yearRangeVec.size(); i++)
        {
            cout << yearRangeVec.at(i)->movieTitle << ": " << yearRangeVec.at(i)->releaseDate << endl;
        }
    */

    /*
        cout << "Limiting the database to " << startingYear << " - " << endingYear << endl;
        yearRangeVec = limitYearRangeOfStructVec(primaryStructVector, startingYear, endingYear);
        cout << "Database year range applied" << endl;
        */

    /* Earlier testing
        // Create the list of all actors in the above nineties movies struct vector
        vector<string> megaCastList = constructMegaCastList(ninetiesMoviesVec);

        // Print all release years in the nineties movies vector to see if it worked
        for (size_t currentIndex = 0; currentIndex < ninetiesMoviesVec.size(); currentIndex++)
        {
            cout << ninetiesMoviesVec.at(currentIndex)->movieTitle << ": " << ninetiesMoviesVec.at(currentIndex)->releaseDate << endl;
        }

        // Print the frequency list of all actors within the year range above
        vector<Actor> resultOfSort = generateActorFreqVec(megaCastList);
        printFreqVec(resultOfSort);

        // Previous revenue sorting testing
        vector<combinedMovieStruct *> ninetiesMoviesVecByRevenue = ascendingRevenueSort(ninetiesMoviesVec);
        for (size_t currentIndex = 0; currentIndex < ninetiesMoviesVecByRevenue.size(); currentIndex++)
        {
            cout << fixed << setprecision(0) << ninetiesMoviesVecByRevenue.at(currentIndex)->movieTitle << ": " << ninetiesMoviesVecByRevenue.at(currentIndex)->revenue << endl;
        }






        */

    /* Profit sorting testing
     vector<combinedMovieStruct *> ninetiesMoviesVecByRevenue = descendingProfitSort(ninetiesMoviesVec);
     for (size_t currentIndex = 0; currentIndex < ninetiesMoviesVecByRevenue.size(); currentIndex++)
     {
         cout << fixed << setprecision(0) << ninetiesMoviesVecByRevenue.at(currentIndex)->movieTitle << ": " << (ninetiesMoviesVecByRevenue.at(currentIndex)->revenue - ninetiesMoviesVecByRevenue.at(currentIndex)->budget) << endl;
     }
     */

    /*
        // Testing the mega cast list printing all actor freqs of all movies

        // Create the list of all actors in all movies for use in the actor frequency counter functions
        vector<string> megaCastList = constructMegaCastList(primaryStructVector);

        vector<Actor> resultOfSort = generateActorFreqVec(megaCastList);
        printFreqVec(resultOfSort);
    */

    /*
        // Loop to print out movie titles along with their director, genres, and actors list
                int howMany = 400;
                for (int outerCount = 0; outerCount < howMany; outerCount++)
                {

                    // Print movie titles
                    cout << primaryStructVector.at(outerCount)->movieTitle << endl;

                    // Print director name
                    cout << "Director: " << primaryStructVector.at(outerCount)->director << endl
                         << endl;

                    // Print genres
                    cout << "Genres: ";
                    for (int i = 0; i < primaryStructVector.at(outerCount)->genres.size(); i++)
                    {
                        cout << primaryStructVector.at(outerCount)->genres.at(i) << ", ";
                    }
                    cout << endl;

                    // Print cast names
                    cout << endl
                         << "Cast: " << endl;
                    for (int i = 0; i < primaryStructVector.at(outerCount)->cast.size(); i++)
                    {
                        cout << primaryStructVector.at(outerCount)->cast.at(i) << endl;
                    }
                    cout << endl;
                }
                */
}