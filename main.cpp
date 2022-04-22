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
    vector<combinedMovieStruct *> ninetiesMoviesVecByRevenue = ascendingRevenueSort(ninetiesMoviesVec);
    for (size_t currentIndex = 0; currentIndex < ninetiesMoviesVecByRevenue.size(); currentIndex++)
    {
        cout << fixed << setprecision(0) << ninetiesMoviesVecByRevenue.at(currentIndex)->movieTitle << ": " << ninetiesMoviesVecByRevenue.at(currentIndex)->revenue << endl;
    }

    */

    vector<combinedMovieStruct *> ninetiesMoviesVecByRevenue = descendingRevenueSort(ninetiesMoviesVec);
    

    // Resize the 90's movies by revenue to only be the first 30 movies in that vector
    // Then build a cast list out of all actors in those top 30 movies by revenue
    // Then sort that list by frequency
    // Then print out that sorted list
    ninetiesMoviesVecByRevenue.resize(30);
    vector<string> ninetiesCastList = constructMegaCastList(ninetiesMoviesVecByRevenue);
    vector<Actor> sortedNinetiesCast = sortedActorFreqVec(ninetiesCastList);
    printFreqVec(sortedNinetiesCast);
    
    /*
    cout << "Now printing those top 30 movies by revenue by descending release date: " << endl;
    vector<combinedMovieStruct *> ninetiesMoviesTop30ByYear = descendingYearSort(ninetiesMoviesVecByRevenue);
    for (size_t i = 0; i < ninetiesMoviesTop30ByYear.size(); i++)
    {
        cout << ninetiesMoviesTop30ByYear.at(i)->movieTitle << ": " << ninetiesMoviesTop30ByYear.at(i)->releaseDate << endl;
    }
    */

    // Debugging genre counter
    // For the length of the overall struct vector...
    for (size_t i = 0; i < ninetiesMoviesVecByRevenue.size(); i++)
    {
        // Print the movie title at the current index in the struct vector
        cout << ninetiesMoviesVecByRevenue.at(i)->movieTitle << ": ";
        
        // For the length of the current index genre vector...
        for (size_t j = 0; j < ninetiesMoviesVecByRevenue.at(i)->genres.size(); j++)
        {
            // Print out each genre in that genre vector
            cout << ninetiesMoviesVecByRevenue.at(i)->genres.at(j) << ", ";
        }
        
        cout << endl;
    }

    vector<string> ninetiesTopGenres = constructMegaGenreList(ninetiesMoviesVecByRevenue);
    cout << "\n \n Beginning genres printing: \n";
    for (size_t i = 0; i < ninetiesTopGenres.size(); i++)
    {
        cout << ninetiesTopGenres.at(i) << ", ";
    }

     cout << "\n\nSize of ninetiesTopGenres before: " << ninetiesTopGenres.size() << endl;
    vector<Genre> sortedNinetiesGenres = sortGenreFreqVec(ninetiesTopGenres);
    cout << "Size of ninetiesTopGenres after: " << ninetiesTopGenres.size() << endl;

    cout << "Number of different Genres found: " << sortedNinetiesGenres.size()<< endl << endl;
    printFreqVec(sortedNinetiesGenres);
    
    



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