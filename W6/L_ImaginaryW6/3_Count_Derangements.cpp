#include<bits/stdc++.h>
using namespace std;

int solveRE(int n){
    //Base Case
    if(n == 1) return 0;
    if(n == 2) return 1;

    int ans = (n-1) * (solveRE(n-1) + solveRE(n-2));
    return ans;
}

int main(){
    int n = 4;  
    cout<<solveRE(n); //9 Expected
    return 0;
}