
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

// Placeholder struct for movie data
struct movieStruct
{
    string movieTitle = "";     // col 1 movie title
    double revenue = 0;            // col 2 movie revenue
    int budget = 0;             // col 3 movie budget
    vector<string> genres = {}; // col 4 movie's genres
    int runtime = 0;
    int releaseDate = 0;        // col 5 movie's release date TO DO: YEAR ONLY for release date
    double rating = 0;          // col 6 movie average rating
    int voteCount = 0;          // col 7 store number of votes towards the rating?
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
        if (conversionType == "cast" || conversionType == "genre")
        {
            string susString = "name\": \""; // Searching for this
            vector<string> newArray = {};    // An empty array which will eventually hold the actors names and will be returned

            // Find all occurrences of sus string (in this case it's name)
            size_t foundIndex = convertThis.find(susString);
            while (foundIndex != string::npos) // Continue until there are no more sus strings to be found
            {
                // cout << "Next found starting index is " << foundIndex << endl; debug line

                // A couple variables with placeholder values,
                char nextChar = 'a';
                string foundName = "";

                // A copy of the found index, which can be modified safely
                int nextCharIndex = foundIndex;
                while (nextChar != ',' && nextChar != ']') // A comma marks the end of the actor or genre name, so we stop there
                {
                    nextChar = convertThis.at(nextCharIndex + 8); // The next char is the next character after the index found in the find() function +8 to get past the found word and the quotes and spaces..
                    foundName.push_back(nextChar);                // Add each char in the string until a quotation is reached, meaning the end of the actor or genre name
                    nextCharIndex++;                              // Increment the current index by 1 to get each subsequent letter in the actor or genre name, if there are more
                }
                foundName.pop_back(); // Delete the comma
                foundName.pop_back(); // Delete the quotes
                if (conversionType == "genre")
                {
                    foundName.pop_back(); // Genre has an extra quote so remove that
                }

                // cout << "pushing back: " << foundName << endl; Debug line to output the name being added to the new array
                newArray.push_back(foundName);                            // Add the completed actor or genre name to the newly forming array
                foundIndex = convertThis.find(susString, foundIndex + 8); // +8 because that's the length of "name\": \"" excluding the escape characters \     "
            }
            return newArray;
        }
    }
    return newArray;
}

int main()
{
    ifstream inputFile;
    inputFile.open("./TSV Files/movies.tsv");
    string currentLine; // String that stores the current line
    int rowNum = 1;     // Int that tracks the current row number
    string colLabels;   // String that stores the not-so-useful first line which has the column labels
    vector<string> currentRowVector;

    if (!inputFile)
    { // If there is no input file... (it didn't open) then display an error message
        cout << "The movies file did not open correctly, exiting the program";
        return -1;
    }
    else
    {                                    // If the file opened successfully
        getline(inputFile, currentLine); // stores the first line which has the column labels in it
        // ______________________________________________________________________________________

        vector<movieStruct *> vectorOfMovieRowVectors; // The big vector holding all of the various row structs
        int i = 0;                                     // debugging int to find out which line this might break on

        while (!inputFile.eof()) // While not at the end of the file...
        {
            /* debugging lines
            cout << inputFile.eof() << endl;
            cout << "while loop" << endl;
            */

            getline(inputFile, currentLine);                    // Get the current row from the document
            currentRowVector = delimitThis(currentLine, '\t'); // Call the delimiter function to split this line up into columns

            // TO DO:
            // CONVERT THIS WHOLE THING TO WORK FOR MOVIES TSV

            movieStruct *newRowStruct = new movieStruct;
            (*newRowStruct).movieTitle = currentRowVector.at(0); // Save the movie title data
            // cout << "Movie title data saved" << endl;     DEBUG LINE


            //cout << currentLineVector.at(0) << "  Revenue: " << currentLineVector.at(1) << endl;
            (*newRowStruct).revenue = std::stod(currentRowVector.at(1)); // Save the movie revenue data, supposedly stoi converts string to int

            //cout << currentLineVector.at(0) << "  Budget: " << currentLineVector.at(2) << endl;
            (*newRowStruct).budget = std::stoi(currentRowVector.at(2)); // Save the movie budget data, supposedly stoi converts string to int

            // Only store genre data if it exists and it's actually the genre data, checked if it contains "[{\"" which is exclusive to genre within the movies.tsv file
            if (currentRowVector.size() >= 4 && currentRowVector.at(3).find("[{\"") != std::string::npos)
            {
                // cout << "Before saving" << endl; DEBUG LINE
                (*newRowStruct).genres = convertStringToArray(currentRowVector.at(3), "genre"); // Save the movie genre data after is has been converted from a string to array
            }
            // __________________________________________________________________________

            // If there is a release date (tested by having a length greater than or equal to 4)
            
            if(currentRowVector.at(4).size() >= 4){
            //cout << currentLineVector.at(0) << "  Release Date: " << std::stoi(currentLineVector.at(4).substr(0, 4)) << endl; 
            (*newRowStruct).releaseDate = std::stoi(currentRowVector.at(4).substr(0, 4)); // Save the first 4 numbers of release date, supposedly stoi converts string to int
            }
            
            // Movie runtime is usually longer than 0 minutes so check if that's true first
            if(currentRowVector.at(5).size() >= 1){
            //cout << currentLineVector.at(0) << "  Runtime: " << std::stoi(currentLineVector.at(5)) << endl; 
            (*newRowStruct).runtime = std::stoi(currentRowVector.at(5).substr(0, 5)); // Save the first 4 numbers of release date, supposedly stoi converts string to int
            }

            // If there is a rating value, it should have a length greater than or equal to 1, if so, store it
            if(currentRowVector.at(6).size() >= 1){
            //cout << currentLineVector.at(0) << "  Rating: " << std::stod(currentLineVector.at(6)) << endl;
            (*newRowStruct).rating = std::stod(currentRowVector.at(6)); // Save the rating as a double, supposedly stod converts string to double
            }
            

            // If there is a vote count value, it should have a length greater than or equal to 1, if so, store it
            if(currentRowVector.at(7).size() >= 1){
            //cout << currentLineVector.at(0) << "  Vote Count: " << std::stoi(currentLineVector.at(7)) << endl; 
            (*newRowStruct).voteCount = std::stoi(currentRowVector.at(7)); // Save the vote count as int, supposedly stoi converts string to int
            }
            

            vectorOfMovieRowVectors.push_back(newRowStruct); // Save this struct in the big vector of row structs

            // cout << i << endl; // Debugging line to find out how many times this runs all the way to the end of this loop
            i++;
        }

        cout << endl;
        // Print elements of the structs to see if this works
        // cout << vectorOfRowVectors.at(0)->title << endl;
        // cout << vectorOfRowVectors.at(0)->cast << endl;
        // cout << vectorOfRowVectors.at(0)->crew << endl;
        
        // Testing printing loop, change increment to however many to print out
        /*
        int howManYEE = 20;
        cout << endl << "Printing the first " << howManYEE << " movie revenues..." << endl;
        for (int increment = 0; increment < howManYEE; increment++)
        {
            cout << vectorOfMovieRowVectors.at(increment)->movieTitle << " Revenue: " << vectorOfMovieRowVectors.at(increment)->revenue << endl;
        }

        double avatar = vectorOfMovieRowVectors.at(0)->revenue;
        double pirates = vectorOfMovieRowVectors.at(1)->revenue;
        bool testBool = (avatar > pirates);
        cout << endl << "TestBool result says: " << testBool << endl;
        */
        

        
        // Test loop to print out movie titles along with their genres list
        int howMany = 15;
        for (int increment = 0; increment < howMany; increment++)
        {
            cout << vectorOfMovieRowVectors.at(increment)->movieTitle << endl;
            for (int i = 0; i < vectorOfMovieRowVectors.at(increment)->genres.size(); i++)
            {
                cout << vectorOfMovieRowVectors.at(increment)->genres.at(i) << endl;
            }
            cout << endl;
        }
        

        /*
        cout << endl << "Printing the first " << "all" << " director names...";
            // Test loop to print out the first 10 directors
                for (int increment = 0; increment < vectorOfMovieRowVectors.size(); increment++)

                {
                    cout << vectorOfMovieRowVectors.at(increment)->revenue << endl;
                }
                */
    }

    return 0;
}