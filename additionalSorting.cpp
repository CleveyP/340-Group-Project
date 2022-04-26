// Stephen Martel
// Experimenting with additional sorting functions here
// Various booleans to help the sorting functions, and a bunch of sorting functions down below
// 4/21/2022

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "tsvReaderMergedFunction.cpp" // Include my tsv reader so it can use the variables from there

using namespace std;

// _____________ Revenue sorting booleans _____________

// Quick comparison of two revenue values for use in the sort by High to Low revenue sort function
bool boolHighRevenue(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue) > (struct2->revenue));
}

// Quick comparison of two revenue values for use in the sort by Low to High revenue sort function
bool boolLowRevenue(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue) < (struct2->revenue));
}

/*





*/

// _____________ Profit (revenue - budget) sorting booleans _____________

// Quick comparison of two struct's profit (revenue - budget) values for use by the sort high to low profit function
bool boolHighProfit(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue - struct1->budget) > (struct2->revenue - struct2->budget));
}

// Quick comparison of two struct's profit (revenue - budget) values for use by the sort low to high profit function
bool boolLowProfit(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return ((struct1->revenue - struct1->budget) < (struct2->revenue - struct2->budget));
}

/*





*/

// _____________ Release date sorting booleans _____________

// Quick comparison of two release date values for use in the sort by High to Low sort function
bool boolDescendingYears(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->releaseDate > struct2->releaseDate;
}

// Quick comparison of two release date values for use in the sort by Low to High sort function
bool boolAscendingYears(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->releaseDate < struct2->releaseDate;
}

/*





*/

// _____________ Rating value sorting booleans _____________

// Quick comparison of two rating values for use in the sort by High to Low sort function
bool boolDescendingRatings(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->rating > struct2->rating;
}

// Quick comparison of two rating values for use in the sort by Low to High sort function
bool boolAscendingRatings(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->rating < struct2->rating;
}

/*





*/

// _____________ Popularity value (revenue * rating) sorting booleans _____________

// Quick comparison of two Popularity values for use in the sort by High to Low sort function
bool boolDescendingPopularity(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return (struct1->revenue * struct1->rating) > (struct2->revenue * struct2->rating);
}

// Quick comparison of two Popularity values for use in the sort by Low to High sort function
bool boolAscendingPopularity(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return (struct1->revenue * struct1->rating) < (struct2->revenue * struct2->rating);
}

/*





*/

// _____________ Runtime value sorting booleans _____________

// Quick comparison of two runtime values for use in the sort by High to Low sort function
bool boolDescendingRuntime(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->runtime > struct2->runtime;
}

// Quick comparison of two runtime values for use in the sort by Low to High sort function
bool boolAscendingRuntime(combinedMovieStruct *&struct1, combinedMovieStruct *&struct2)
{
    return struct1->runtime < struct2->runtime;
}

/*





*/

// _____________ Actual sorting functions _____________

// ___Revenue sorting ___

// Sorts an input movie struct vector by revenue with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingRevenueSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), boolHighRevenue);

    // Return the sorted vector of structs
    return inputVector;
}

// Sorts an input movie struct vector by revenue with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingRevenueSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), boolLowRevenue);

    // Return the sorted vector of structs
    return inputVector;
}

/*





*/

// ___Profit sorting ___
// Sorts an input movie struct vector by profit value (revenue - budget) with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingProfitSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), boolHighProfit);

    // Return the sorted vector of structs
    return inputVector;
}

// Sorts an input movie struct vector by profit value (revenue - budget) with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingProfitSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), boolLowProfit);

    // Return the sorted vector of structs
    return inputVector;
}

/*





*/

// ___Release year sorting ___

// Sorts an input movie struct vector by release date year with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingReleaseYearSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), boolDescendingYears);

    // Return the sorted vector of structs
    return inputVector;
}

// Sorts an input movie struct vector by release date year with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingReleaseYearSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), boolAscendingYears);

    // Return the sorted vector of structs
    return inputVector;
}

/*





*/

// ___ Rating sorting ___

// Sorts an input movie struct vector by rating value with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingRatingsSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), boolDescendingRatings);

    // Return the sorted vector of structs
    return inputVector;
}

// Sorts an input movie struct vector by rating value with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingRatingsSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), boolAscendingRatings);

    // Return the sorted vector of structs
    return inputVector;
}

/*





*/

// ___ Popularity (Revenue * rating) sorting ___

// Sorts an input movie struct vector by popularity value (revenue * rating) with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingPopularitySort(vector<combinedMovieStruct *> &inputVector)
{

    sort(inputVector.begin(), inputVector.end(), boolDescendingPopularity);

    // Return the sorted vector of structs
    return inputVector;
}

// Sorts an input movie struct vector by popularity value (revenue * rating) with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingPopularitySort(vector<combinedMovieStruct *> &inputVector)
{
    sort(inputVector.begin(), inputVector.end(), boolAscendingPopularity);

    // Return the sorted vector of structs
    return inputVector;
}

/*




*/

// ___Runtime sorting ___

// Sorts an input movie struct vector by runtime with a sorting type of high to low (descending)
vector<combinedMovieStruct *> descendingRuntimeSort(vector<combinedMovieStruct *> inputVector)
{

    sort(inputVector.begin(), inputVector.end(), boolDescendingRuntime);

    // Return the sorted vector of structs
    return inputVector;
}

// Sorts an input movie struct vector by runtime with a sorting type of low to high (ascending)
vector<combinedMovieStruct *> ascendingRuntimeSort(vector<combinedMovieStruct *> inputVector)
{
    sort(inputVector.begin(), inputVector.end(), boolAscendingRuntime);

    // Return the sorted vector of structs
    return inputVector;
}