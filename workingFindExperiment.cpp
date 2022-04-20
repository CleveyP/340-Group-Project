// Original from GeeksForGeeks
// Modified to try and get it to work for our project

// CPP program to demonstrate working of string
// find to search a string
#include <iostream>
#include <string>
#include <vector>
  
using namespace std;
  
int main()
{
    string convertThis = "\"id\": 15853, \"name\": \"Wes Studi\", \"order\": 8}, {\"cast_id\": 10, \"character\": \"Tsu'Tey\", \"credit_id\": \"52fe48009251416c750ac9e9\", \"gender\": 2, \"id\": 10964, \"name\": \"Laz Alonso\", \"order\": 9} , \"id\": 10964, \"name\": \"John Cena\", \"order\": 9} , \"id\": 10964, \"name\": \"Spibbidy Boppity\", \"order\": 9}";
    string susString = "name\": \""; // Searching for this
    vector<string> newArray = {};
  
    // Find all occurrences of sus string (in this case it's name)
    //found = str.find(str1, found+8); // +8 because that's the length of "name\": \"" excluding the escape characters \     "
    size_t foundIndex = convertThis.find("name\": \"");
    while (foundIndex != string::npos){
        cout << "Next found starting index is " << foundIndex << endl;

        int stringIndex = foundIndex;
        char nextChar = 'a';
        string foundName = "";
        int nextCharIndex = stringIndex;
        while(nextChar != ','){
                    nextChar = convertThis.at(nextCharIndex + 8); // The next char is the next character after the index found in the find() function +8 to get past the found word and the quotes and spaces..
                    foundName.push_back(nextChar); // Add each char in the string until a quotation is reached, meaning the end of the actor name
                    nextCharIndex++; // Increment the current index by 1 to get each subsequent letter in the actor's name, if there are more
                }
            foundName.pop_back(); // Delete the comma
            foundName.pop_back(); // Delete the quotes
            newArray.push_back(foundName); // Add the completed actor name to the newly forming array
            foundIndex = convertThis.find(susString, foundIndex+8); // +8 because that's the length of "name\": \""
    }
        
    for(int i = 0; i < newArray.size(); i++){
        cout << newArray.at(i) << endl;
    }

  
    return 0;
}