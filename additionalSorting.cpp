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
bool compareRevenue(combinedMovieStruct* &struct1Rev, combinedMovieStruct* &struct2Rev)
{
    return ((struct1Rev->revenue) > (struct2Rev->revenue));
}

vector<combinedMovieStruct *> sortHighToLowRevenue(vector<combinedMovieStruct *> inputVector) {
    // Create a new struct which will be the sorted version returned at the end
    vector<combinedMovieStruct *> sortedByRevenue;

    sort(inputVector.begin(), inputVector.end(), compareRevenue);

    return inputVector;
}
