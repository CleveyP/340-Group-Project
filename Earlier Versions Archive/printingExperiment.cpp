#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int runtime = 150;
    double revenue = 509034560;
    cout << endl;
    cout << "Precision: 2 " << fixed << setprecision(2) << "$" << revenue/runtime << " per minute" << endl;
    cout << "Precision: 0 " << fixed << setprecision(0) << "$" << revenue/runtime << " per minute" << endl;
    cout << endl;
    return 0;
}
