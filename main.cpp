// main file for movies group project for 340
#include <iostream>
#include <fstream>
using namespace std;

    int main()
    {
        ifstream inputFile;
        inputFile.open("tmdb_5000_credits.csv");
        if(!inputFile){
            cout<<"It didnt open properly";
        }else{
            string testLine;
            inputFile >> testLine;
            cout<<"the first line from file is: "<<testLine;
        }
        return 0;
    }