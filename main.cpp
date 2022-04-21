/*
Stephen Martel
4/20/2022
Combining my existing credits.tsv and movies.tsv
TSV File reader for the movies tsv file

*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

#include "tsvReaderMergedFunction.cpp"

int main()
{
    vector<combinedMovieStruct *> storage = createVectorOfStructs();
    
    // Loop to print out movie titles along with their director, genres, and actors list
            int howMany = 400;
            for (int outerCount = 0; outerCount < howMany; outerCount++)
            {

                // Print movie titles
                cout << storage.at(outerCount)->movieTitle << endl;

                // Print director name
                cout << "Director: " << storage.at(outerCount)->director << endl
                     << endl;

                // Print genres
                cout << "Genres: ";
                for (int i = 0; i < storage.at(outerCount)->genres.size(); i++)
                {
                    cout << storage.at(outerCount)->genres.at(i) << ", ";
                }
                cout << endl;

                // Print cast names
                cout << endl
                     << "Cast: " << endl;
                for (int i = 0; i < storage.at(outerCount)->cast.size(); i++)
                {
                    cout << storage.at(outerCount)->cast.at(i) << endl;
                }
                cout << endl;
            }


}