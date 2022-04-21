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


int main()
{
    // Store the primary struct resulting from the conversion of the two tsv files into a variable for use in functions later
    vector<combinedMovieStruct *> primaryStructVector = createPrimaryVectorOfStructs();

    
    // Create a vector of structs consisting of only movies within the year range 1990 - 1999
    vector<combinedMovieStruct *> ninetiesMoviesVec = limitedYearsStructVec(primaryStructVector, 1990, 1999);

    /* Earlier testing
    // Create the list of all actors in the above nineties movies struct vector
    vector<string> megaCastList = constructMegaCastList(ninetiesMoviesVec);

    // Print all release years in the nineties movies vector to see if it worked
    for (size_t currentIndex = 0; currentIndex < ninetiesMoviesVec.size(); currentIndex++)
    {
        cout << ninetiesMoviesVec.at(currentIndex)->movieTitle << ": " << ninetiesMoviesVec.at(currentIndex)->releaseDate << endl;
    }
    
    // Print the frequency list of all actors within the year range above
    vector<Actor> resultOfSort = sortedActorFreqVec(megaCastList);
    printFreqVec(resultOfSort);

    // Previous revenue sorting testing
    vector<combinedMovieStruct *> ninetiesMoviesVecByRevenue = ascendingRevenue(ninetiesMoviesVec);
    for (size_t currentIndex = 0; currentIndex < ninetiesMoviesVecByRevenue.size(); currentIndex++)
    {
        cout << fixed << setprecision(0) << ninetiesMoviesVecByRevenue.at(currentIndex)->movieTitle << ": " << ninetiesMoviesVecByRevenue.at(currentIndex)->revenue << endl;
    }

    */

    vector<combinedMovieStruct *> ninetiesMoviesVecByRevenue = descendingRevenue(ninetiesMoviesVec);
    

    // Resize the 90's movies by revenue to only be the first 20 movies in that vector
    // Then build a cast list out of all actors in those top 20 movies by revenue
    // Then sort that list by frequency
    // Then print out that sorted list
    ninetiesMoviesVecByRevenue.resize(30);
    vector<string> ninetiesCastList = constructMegaCastList(ninetiesMoviesVecByRevenue);
    vector<Actor> sortedNinetiesCast = sortedActorFreqVec(ninetiesCastList);
    printFreqVec(sortedNinetiesCast);
    

   /* Profit sorting testing
    vector<combinedMovieStruct *> ninetiesMoviesVecByRevenue = descendingProfit(ninetiesMoviesVec);
    for (size_t currentIndex = 0; currentIndex < ninetiesMoviesVecByRevenue.size(); currentIndex++)
    {
        cout << fixed << setprecision(0) << ninetiesMoviesVecByRevenue.at(currentIndex)->movieTitle << ": " << (ninetiesMoviesVecByRevenue.at(currentIndex)->revenue - ninetiesMoviesVecByRevenue.at(currentIndex)->budget) << endl;
    }
    */


/*
    // Testing the mega cast list printing all actor freqs of all movies

    // Create the list of all actors in all movies for use in the actor frequency counter functions
    vector<string> megaCastList = constructMegaCastList(primaryStructVector);

    vector<Actor> resultOfSort = sortedActorFreqVec(megaCastList);
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