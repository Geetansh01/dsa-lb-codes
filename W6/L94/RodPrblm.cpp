#include<iostream>
#include<limits.h>
using namespace std;

//Similar to Coin Change Problem (L94). See that in NoteBook

int solve(int n, int x, int y, int z){
    //base case
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
    }

    //1 case solve kro
    int a = solve(n-x, x, y, z)+1;
    int b = solve(n-y, x, y, z)+1;
    int c = solve(n-z, x, y, z)+1;

    int ans = max(a, max(b,c));
    return ans;
}

int main(){
    // // Test Case Set 1
    // int n = 8;
    // int x = 3;
    // int y = 3;
    // int z = 3;

    // Test Case Set 2
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(n,x,y,z);
    if(ans < 0){
        ans = 0;
    }
   
   cout<<"Answer : "<<ans<<endl;
return 0;
}