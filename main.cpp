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

#include "tsvReaderMergedFunction.cpp"  // Include the way to convert the database files into a usable vector of structs
#include "actorFreqCounter.cpp"

int main()
{
    // Store the primary struct resulting from the conversion of the two tsv files into a variable for use in functions later
    vector<combinedMovieStruct *> primaryStructVector = createPrimaryVectorOfStructs();

    // Create the list of all actors in all movies for use in the actor frequency counter functions
    vector<string> megaCastList = constructMegaCastList(primaryStructVector);

    vector<Actor> resultOfSort = sortedActorFreqVec(megaCastList);
    printFreqVec(resultOfSort);


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