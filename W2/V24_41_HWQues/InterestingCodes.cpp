#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int ans = pow(10, 2);
    cout<<ans<<endl;
    cout<<pow(10, 2)<<endl;

    /*
    Output by my compiler (As on 3 Aug 2023):
    99
    100

    1)pow() is a troublesome function to implement
    2)This output is compiler dependent, an online compiler gave:
        100
        100
    */
    return 0;
}