// Stephen Martel
// Experimenting with additional sorting functions here
// 4/21/2022

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "tsvReaderMergedFunction.cpp"  // Include my tsv reader so it can use the variables from there


using namespace std;


// _____________ Revenue sorting booleans _____________

// Quick comparison of two revenue values for use in the sort by High to Low revenue sort function
bool highRevBool(combinedMovieStruct* &struct1, combinedMovieStruct* &struct2)
{
    return ((struct1->revenue) > (struct2->revenue));
}

// Quick comparison of two revenue values for use in the sort by Low to High revenue sort function
bool lowRevBool(combinedMovieStruct* &struct1, combinedMovieStruct* &struct2)
{
    return ((struct1->revenue) < (struct2->revenue));
}

/*



*/

// _____________ Profit (revenue - budget) sorting booleans _____________

// Quick comparison of two struct's profit (revenue - budget) values for use by the sort high to low profit function
bool highProfitBool(combinedMovieStruct* &struct1, combinedMovieStruct* &struct2)
{
    return ((struct1->revenue - struct1->budget) > (struct2->revenue - struct2->budget));
}

// Quick comparison of two struct's profit (revenue - budget) values for use by the sort low to high profit function
bool lowProfitBool(combinedMovieStruct* &struct1, combinedMovieStruct* &struct2)
{
    return ((struct1->revenue - struct1->budget) < (struct2->revenue - struct2->budget));
}

// _____________ Actual sorting functions _____________

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingRevenue(vector<combinedMovieStruct *> inputVector) {
    
    sort(inputVector.begin(), inputVector.end(), highRevBool);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingRevenue(vector<combinedMovieStruct *> inputVector) {
    sort(inputVector.begin(), inputVector.end(), lowRevBool);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingProfit(vector<combinedMovieStruct *> inputVector) {
    
    sort(inputVector.begin(), inputVector.end(), highProfitBool);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingProfit(vector<combinedMovieStruct *> inputVector) {
    sort(inputVector.begin(), inputVector.end(), lowProfitBool);

    // Return the sorted vector of structs'
    return inputVector;
}