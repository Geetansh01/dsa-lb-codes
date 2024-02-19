#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/****Guess Number Higher or Lower II [Interview][LeetCode : https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/]******/

int solveUsingRE(int start, int end){
    //Base case
    if(start > end){
        //Range se bahr
        return 0;
    }
    if(start == end){
        //Ek hi no. hai to 0 penalty
        return 0; 
    }

    int ans = INT_MAX;
    for(int i = start; i <= end; i++){
        ans = min(ans, i +  max(solveUsingRE(start, i-1), solveUsingRE(i+1, end)));
    }

    return ans;
}

int solveUsingMem(int start, int end, vector<vector<int> >& dp){
    //Base case
    if(start > end){
        //Range se bahr
        return 0;
    }
    if(start == end){
        //Ek hi no. hai to 0 penalty
        return 0; 
    }

    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int ans = INT_MAX;
    for(int i = start; i <= end; i++){
        ans = min(ans, i +  max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1, end, dp)));
    }

    dp[start][end] = ans;
    return dp[start][end];
}

//Tabulation
int solveUsingTab(int n){
    //taking (n+2) rows bcz Line 1 below will try to access row at index (n+1) (in this code --> "dp[i+1][end_index]")
    vector<vector<int> > dp(n+2, vector<int>(n+1, 0)); //row x col :: start x end

    //Fill initial data : already done by initialising dp with 0

    //RE+Mem ke code me start going from 1 to n so opposite here!
    for(int start_index = n; start_index >= 1; start_index--){
        for(int end_index = 1; end_index <= n; end_index ++){
                
            //Jb (start >= end) to uske liye loops nhi chlane (See Base Cases Above)
            if(start_index >= end_index){
                //Invalid range
                continue;
            }

            //So our logic only runs for (start < end)
            int ans = INT_MAX;
            for(int i = start_index; i <= end_index; i++){
                //__________Line 1
                ans = min(ans, i + max(dp[start_index][i-1], dp[i+1][end_index]) );
            }

            dp[start_index][end_index] = ans;
        }
    }

    return dp[1][n];
}

//TabulationSO
//Not Possible 

int getMoneyAmount(int n) {
    //Plain RE
    // int start = 1;
    // int end = n;
    // int ans = solveUsingRE(start, end);
    // return ans;

    //RE + mem
    // vector<vector<int> > dp(n+1, vector<int>(n+1, -1)); //row x col :: start x end
    // int start = 1;
    // int end = n;
    // int ans = solveUsingMem(start, end, dp);
    // return ans;

    //Tabulation
    int ans = solveUsingTab(n);
    return ans;

}
int main(){
   
return 0;
}