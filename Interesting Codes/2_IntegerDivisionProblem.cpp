#include<iostream>
using namespace std;

/************See how integer division F things up********************************************/
int main(){ 

    //Problem : we want to perform 5 x (5 + 1) divided by 2. So Ans = 15
    int N = 5;
    int a = (N/2)*(N+1); // gives 12 due to rounding in integer division
    int b = (N*(N+1))/2; // 15
    cout<<a<<endl
        <<b<<endl;

    //Solution : Explicit Type Casting
    int c = (double(N)/2)*(N+1); //15
    cout<<c<<endl;

return 0;
}