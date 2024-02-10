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
// int solveUsingMem(int n, vector<int>& dp){
//     //Base Case
//     if(n == 0 || n == 1){
//         return n;
//     }

//     //Step 3 : is ans already stored in dp array then don't recalculate, return from dp array
//     if(dp[n] != -1){
//         return dp[n];
//     }

//     //Recursive Relation
//     //Step 2 : store and return answer using dp array
//     dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
//     return dp[n];
// }

//Tabulation method
int solveUsingTablulation(int n){
    //Step 1 : create dp array
    vector<int> dp(n+1, -1); //dp[n] gives nth term of fibonacci series

    //Step 2 : Fill initial data
    dp[0] = 0; 
    if(n == 0) return dp[0]; //Separately handling case for n = 0, in that case dp[1] is out-of-bound, to yhi se return kr jao
    dp[1] = 1;

    //Step 3 : Fill rest of dp array
    //Remaining indexes  : 2 to n
    for(int k = 2; k <= n; k++){
        //REMEMBER : below formula can be copied from the Recursive Relation present after Step 3 of (RE + memoization) based soln 
        //After copy paste, remember to remove RE behavior i.e "solveUsingMem(n-1, dp)" becomes "dp[k-1]"
        
        //So, you can follow below substeps:
        //subStep1 : copy paste Recursive Relation
        //subStep2 : replace recursive calls with dp array
        //subStep3 : make sure dp array is using looping variables (here k)
        dp[k] = dp[k-1] + dp[k-2];
    }

    //Return answer
    //What is to be returned ? : (RE + memoization) approach me jiski call this vhi return kro ("n" ke liye call thi so dp[n] return kro)
    return dp[n];
}

int fib(int n) {
    //Pain RE 
    // int ans = solveUsingRE(n);
    // return ans;

    //(RE + memoization)
    //Step 1 : Create DP array
    // vector<int> dp(n+1, -1);
    // int ans = solveUsingMem(n, dp);
    // return ans;

    //Tabulation Method
    int ans = solveUsingTablulation(n);
    return ans;
}

int main(){
   
return 0;
}