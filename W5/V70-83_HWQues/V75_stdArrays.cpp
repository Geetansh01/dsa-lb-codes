#include<iostream>
#include<array>
using namespace std;

/*
Q75 uses std::arrays
This is a demonstration of using them
*/

std::array<int, 3> rot(){
    std::array<int, 3> a = {1,2,3};
    return a;
}

//Below code is WRONG
// int* rot(){
//     int a[] = {1,2,3};
//     return a;
// }

int main(){
    std::array<int, 3> b = rot();
    cout<<b[0];
return 0;
}