#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;



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
            int findIndex = 0;
            while (convertThis.find("\"name\": \"", findIndex) != std::string::npos) // While there are still ""name": " in the string (meaning more actors to add)
            {
                cout << "AAAAAAAHHHHH" << endl;
                int stringIndex = convertThis.find("\"name\": \"", findIndex);
                char nextChar = 'a';
                string foundName = "";
                int nextCharIndex = stringIndex;
                while(nextChar != '\"'){
                    nextChar = convertThis.at(nextCharIndex + 1); // The next char is the next character after the index found in the find() function initially
                    foundName.push_back(nextChar); // Add each char in the string until a quotation is reached, meaning the end of the actor name
                    nextCharIndex++; // Increment the current index by 1 to get each subsequent letter in the actor's name, if there are more
                }
                newArray.push_back(foundName); // Add the completed actor name to the newly forming array
            }
            cout << "cast conversion" << endl; // debug print line
            return newArray;
        }
        else if (conversionType == "crew")
        {
            cout << "crew conversion" << endl; // debug print line
        }
    }
    return newArray;
}

int main(){

    string testCastString = "\"id\": 15853, \"name\": \"Wes Studi\", \"order\": 8}, {\"cast_id\": 10, \"character\": \"Tsu'Tey\", \"credit_id\": \"52fe48009251416c750ac9e9\", \"gender\": 2, \"id\": 10964, \"name\": \"Laz Alonso\", \"order\": 9}";
    vector<string> storageVector = convertStringToArray(testCastString, "cast");
    



}