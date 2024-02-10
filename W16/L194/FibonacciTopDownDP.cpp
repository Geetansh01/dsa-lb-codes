#include<iostream>
#include<vector>
using namespace std;

/**********************Fibonacci using Top Down DP [LeetCode : https://leetcode.com/problems/fibonacci-number/description/]******************/

//TC : O(n)

//Plain RE
// int solveUsingRE(int n){
//     //Base Case
//     if(n == 0 || n == 1){
//         return n;
//     }

//     //Recursive Relation
//     int ans = solveUsingRE(n-1) + solveUsingRE(n-2);
//     return ans;
// }

//Top Down approach (RE + memoization)
int solveUsingMem(int n, vector<int>& dp){
    //Base Case
    if(n == 0 || n == 1){
        return n;
    }

    //Step 3 : is ans already stored in dp array then don't recalculate, return from dp array
    if(dp[n] != -1){
        return dp[n];
    }

    //Recursive Relation
    //Step 2 : store and return answer using dp array
    dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
    return dp[n];
}

int fib(int n) {
    // int ans = solveUsingRE(n);
    // return ans;

    //Step 1 : Create DP array
    vector<int> dp(n+1, -1);
    int ans = solveUsingMem(n, dp);
    return ans;
}

int main(){
   
return 0;
}