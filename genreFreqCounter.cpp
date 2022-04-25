
// Stephen Martel
// Modified version of actorFreqCounter designed to work with genres instead
// 4/21/2022

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Genre
{
    string genreName;
    int frequency;
};

// Function to add add each genre in the vector of genre strings to a Genre struct, and increase the frequency of it each time it appears, if it only appears once, then frequency is set to 1
void add_Genres(vector<string> genreStringVec, vector<Genre> &genreStructVector)
{
    /*Debugging lines
    cout << "supposedly adding genres" << endl;
    cout << "input string vector size = " << genreStringVec.size() << endl;
    cout << "input Struct vector size = " << genreStructVec.size() << endl;
    */

    // Create a Genre struct to hold the genre name and frequency
    Genre currentGenre;
    bool hasAppeared = false;

    // For the length of the vector of genre strings...
    for (int stringVecIndex = 0; stringVecIndex < genreStringVec.size(); stringVecIndex++)
    {
        // For the length of the vector of genre objects
        for (int structIndex = 0; structIndex < genreStructVector.size(); structIndex++)
        {
            // If there is a genre with this name already in the vector of structs, then increment its frequency by 1
            if (genreStringVec.at(stringVecIndex) == genreStructVector.at(structIndex).genreName)
            {
                hasAppeared = true;
                // This genre has appeared already so increment the frequency by 1
                genreStructVector.at(structIndex).frequency++;
            }
        }
        // If this genre has not yet been created, create a new Genre struct with a starting frequency of 1 and a genre name equal to the string at this index
        if (hasAppeared == false)
        {
            currentGenre.frequency = 1;
            currentGenre.genreName = genreStringVec.at(stringVecIndex);
            genreStructVector.push_back(currentGenre);
        }
        // Reset hasAppeared back to false for when this loops back around
        hasAppeared = false;
    }
}

/*






Sorting method using the sort from algorithm
*/

// Quick comparison of two frequency values for use in the sort function
bool greaterGenreFreq(Genre &genre1, Genre &genre2)
{
    // Compares the frequency of one genre to another:     is left > right
    return (genre1.frequency > genre2.frequency);
}

// Sort the vector of genres by highest frequency
vector<Genre> genreHighFreqSort(vector<Genre> inputVector)
{
    // Sort by highest frequency and then return it
    sort(inputVector.begin(), inputVector.end(), greaterGenreFreq);
    return inputVector;
}
// ______________________________________________

// A function to print a vector of genre structs
void printFreqVec(vector<Genre> genreVec)
{
    for (int i = 0; i < genreVec.size(); i++)
    {
        if (genreVec.at(i).frequency == 1)
        { // Print statement for a singular appearance
            cout << genreVec.at(i).genreName << " : " << genreVec.at(i).frequency << " film" << endl;
        }

        if (genreVec.at(i).frequency > 1)
        { // Print statement for multiple appearances
            cout << genreVec.at(i).genreName << ": " << genreVec.at(i).frequency << " films" << endl;
        }
    }
}

// Sorts the populated vector of genre types by frequency value, highest first
// Then returns the sorted vector
vector<Genre> generateGenreFreqVec(vector<string> inputMegaGenreVec)
{
    // Empty vector of genres to store the results of add_Genres
    vector<Genre> genreFreqVec; // First creates a new empty vector of genre classes

    add_Genres(inputMegaGenreVec, genreFreqVec); // Then extracts each genre from the input cast vector and adds them to the vector of genre types

    genreFreqVec = genreHighFreqSort(genreFreqVec);
    return genreFreqVec;
}
