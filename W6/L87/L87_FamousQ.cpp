#include<iostream>
using namespace std;

//Famous interview question
int* solve(){
    int a = 52;
    int* ans = &a;
    return ans;
}

int main(){

    int* p = solve();
    cout<<*p<<endl; 
    
    //what will be the output?
    //Note that this code represents BAD programming practice.

    return 0;
}