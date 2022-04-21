
// Ronnie Huang + Stephen Martel
// Original copied over from Ronnie Huang's discord messages and then modified
// 4/21/2022

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Actor{
    public:
    string actorName;
    int frequency;
};

void add_Actors(vector<string> castVec, vector<Actor> & actorVector){
    Actor adding;
    int location = -1;
    //You're given a list of all the actors in appearances in "list", now you add them to "inputs"
    //Look through "list", while getting the string (being the name)
    for(int i = 0; i < castVec.size(); i++){
        //Go Through the entire "inputs" and its "theName"
        for (int j = 0; j < actorVector.size(); j++){
            if (castVec.at(i) == actorVector.at(j).actorName){
                location = j;
            }
        }
        //If it appears, increase "frequency" by 1
        if (location != -1){
            actorVector.at(location).frequency++;
        }
        //If it doesn't, add a new one there with "frequency" being 1
        else{
            adding.frequency = 1;
            adding.actorName = castVec.at(i);
            actorVector.push_back(adding);
        }
        location = -1;
    }
}

void sortHighToLowFreq(vector<Actor> & inputVector) {
    vector<Actor> sortedByFreq;
    Actor helping;
    //int highest = -1;    This was here originally but is unused
    int position = -1;
    for(int i = 0; i < inputVector.size(); i++){
        int highest = -1;
        for(int j = 0; j < inputVector.size(); j++){
            if (inputVector.at(j).frequency > highest){
                highest = inputVector.at(j).frequency;
                position = j;
            }
        }
        helping.frequency = highest;
        helping.actorName = inputVector.at(position).actorName;
        sortedByFreq.push_back(helping);
        inputVector.at(position).frequency = -1;
        highest = -1;
        position = -1;
    }
    inputVector.erase(inputVector.begin(), inputVector.end());
    inputVector = sortedByFreq;
}

 // Took the existing print loop out of main and made it a function
 // Also changed the print statements output and made them conditional
void printFreqVec(vector<Actor> actorVec){
    for (int i = 0; i < actorVec.size(); i++){
        /* Singular appearances were clogging up the log
        if(actorVec.at(i).frequency == 1){ // Print statement for a singular appearance
            cout << actorVec.at(i).actorName << " starred in: " << actorVec.at(i).frequency << " film" << endl;
        }
        */
        if(actorVec.at(i).frequency > 1){ // Print statement for multiple appearances
            cout << actorVec.at(i).actorName << " starred in: " << actorVec.at(i).frequency << " films" << endl;
        }
        
    }
}

// The previous main function's order of calling the other functions in here
// First creates a new empty vector of actor classes
// Then extracts each actor from the input cast vector and adds them to the vector of actor types
// Then sorts that populated vector of actor types by frequency value, highest first 
// Then returns the sorted vector
vector<Actor> sortedActorFreqVec(vector<string> inputMegaCastVec){
    // Empty vector of actors to store the results of add_Actors
    vector<Actor> actorFreqVec;
    add_Actors(inputMegaCastVec, actorFreqVec);
    sortHighToLowFreq(actorFreqVec);
    return actorFreqVec;
}

/*
  // Old main function for testing purposes.
int main()
{

    //This contains all the names of the actors, should be removed later
    vector <string> inputMegaCastVec;
    inputMegaCastVec.push_back("Azi");
    inputMegaCastVec.push_back("Cleveland");
    inputMegaCastVec.push_back("ddanime");
    inputMegaCastVec.push_back("The Senate");
    inputMegaCastVec.push_back("Azi");
    inputMegaCastVec.push_back("Yueling Liu");
    inputMegaCastVec.push_back("ddanime");
    inputMegaCastVec.push_back("CLTurtle");
    inputMegaCastVec.push_back("Azi");

    vector<Actor> resultOfSort = sortedActorFreqVec(inputMegaCastVec);
    printFreqVec(resultOfSort);

    return 0;
}
*/