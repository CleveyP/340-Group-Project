// Stephen Martel
// Experimenting with additional sorting functions here
// 4/21/2022

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "tsvReaderMergedFunction.cpp" // Include my tsv reader so it can use the variables from there

using namespace std;

// _____________ Revenue sorting booleans _____________

// Quick comparison of two revenue values for use in the sort by High to Low revenue sort function
bool highRevBool(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue) > (struct2->revenue));
}

// Quick comparison of two revenue values for use in the sort by Low to High revenue sort function
bool lowRevBool(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue) < (struct2->revenue));
}

/*





*/

// _____________ Profit (revenue - budget) sorting booleans _____________

// Quick comparison of two struct's profit (revenue - budget) values for use by the sort high to low profit function
bool highProfitBool(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue - struct1->budget) > (struct2->revenue - struct2->budget));
}

// Quick comparison of two struct's profit (revenue - budget) values for use by the sort low to high profit function
bool lowProfitBool(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue - struct1->budget) < (struct2->revenue - struct2->budget));
}

/*





*/

// _____________ Release date sorting booleans _____________

// Quick comparison of two release date values for use in the sort by High to Low sort function
bool descendingYears(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->releaseDate > struct2->releaseDate;
}

// Quick comparison of two release date values for use in the sort by Low to High sort function
bool ascendingYears(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->releaseDate < struct2->releaseDate;
}

/*





*/

// _____________ Rating value sorting booleans _____________

// Quick comparison of two rating values for use in the sort by High to Low sort function
bool descendingRatings(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->rating > struct2->rating;
}

// Quick comparison of two rating values for use in the sort by Low to High sort function
bool ascendingRatings(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->rating < struct2->rating;
}

/*





*/

// _____________ Popularity value (revenue * rating) sorting booleans _____________

// Quick comparison of two Popularity values for use in the sort by High to Low sort function
bool descendingPopularity(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return (struct1->revenue * struct1->rating) > (struct2->revenue * struct2->rating);
}

// Quick comparison of two Popularity values for use in the sort by Low to High sort function
bool ascendingPopularity(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return (struct1->revenue * struct1->rating) < (struct2->revenue * struct2->rating);
}

/*





*/

// _____________ Actual sorting functions _____________

// ___Revenue sorting ___

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingRevenueSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), highRevBool);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingRevenueSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), lowRevBool);

    // Return the sorted vector of structs'
    return inputVector;
}

/*





*/

// ___Profit sorting ___
// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingProfitSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), highProfitBool);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingProfitSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), lowProfitBool);

    // Return the sorted vector of structs'
    return inputVector;
}

/*





*/

// ___Release year sorting ___

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingYearSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), descendingYears);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingYearSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), ascendingYears);

    // Return the sorted vector of structs'
    return inputVector;
}

/*





*/

// ___ Rating sorting ___

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingRatingsSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), descendingRatings);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingRatingsSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), ascendingRatings);

    // Return the sorted vector of structs'
    return inputVector;
}

/*





*/

// ___ Popularity (Revenue * rating) sorting ___

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingPopularitySort(vector<combinedMovieStruct *> &inputVector)
{

    sort(inputVector.begin(), inputVector.end(), descendingPopularity);

    // Return the sorted vector of structs'
    return inputVector;
}

// Calls the sort function with starting point of the beginning of the vector of structs and ending at the end of it, with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingPopularitySort(vector<combinedMovieStruct *> &inputVector)
{
    sort(inputVector.begin(), inputVector.end(), ascendingPopularity);

    // Return the sorted vector of structs'
    return inputVector;
}