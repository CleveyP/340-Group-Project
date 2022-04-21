// Stephen Martel
// Experimenting with additional sorting functions here
// 4/21/2022

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "tsvReaderMergedFunction.cpp"  // Include my tsv reader so it can use the variables from there


using namespace std;



// Quick comparison of two revenue values for use in the sort by High to Low revenue sort function
bool greaterThanCompare(combinedMovieStruct* &struct1Rev, combinedMovieStruct* &struct2Rev)
{
    return ((struct1Rev->revenue) > (struct2Rev->revenue));
}

// Quick comparison of two revenue values for use in the sort by Low to High revenue sort function
bool lessThanCompare(combinedMovieStruct* &struct1Rev, combinedMovieStruct* &struct2Rev)
{
    return ((struct1Rev->revenue) < (struct2Rev->revenue));
}

vector<combinedMovieStruct *> sortHighToLowRevenue(vector<combinedMovieStruct *> inputVector) {
    // Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
    sort(inputVector.begin(), inputVector.end(), greaterThanCompare);

    // Return the sorted vector of structs'
    return inputVector;
}

vector<combinedMovieStruct *> sortLowToHighRevenue(vector<combinedMovieStruct *> inputVector) {
    // Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
    sort(inputVector.begin(), inputVector.end(), lessThanCompare);

    // Return the sorted vector of structs'
    return inputVector;
}
