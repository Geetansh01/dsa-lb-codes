#include<iostream>
using namespace std;

int main(){
    //Reference variable for pointers themselves
    int a = 10;
    int* p = &a;
    int*& b = p;

    cout<<*b<<endl;

    return 0;
}