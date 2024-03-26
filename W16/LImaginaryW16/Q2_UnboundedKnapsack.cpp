#include<bits/stdc++.h>
using namespace std;

int solveUsingRE(int index, int N, int W, int val[], int wt[]){
    //BC
    if(W == 0)return 0;
    if(index >= N)return 0;
    
    int maxVal = 0;
    //Include current item in knapsack if you can
    int include = INT_MIN;
    if(W - wt[index] >= 0){
        include = val[index] + solveUsingRE(index, N, W - wt[index], val, wt);
    }

    //Exclude current item in knapsack
    int exclude = solveUsingRE(index + 1, N, W, val, wt);
    
    maxVal = max(include, exclude);
    return maxVal;
}

int solveUsingMem(int index, int N, int W, int val[], int wt[], vector<vector<int> >& dp){
    //BC
    if(W == 0)return 0;
    if(index >= N)return 0;
    ;
    if(dp[index][W] != -1){
        return dp[index][W];
    }
    
    int maxVal = 0;
    //Include current item in knapsack if you can
    int include = INT_MIN;
    if(W - wt[index] >= 0){
        include = val[index] + solveUsingMem(index, N, W - wt[index], val, wt, dp);
    }

    //Exclude current item in knapsack
    int exclude = solveUsingMem(index + 1, N, W, val, wt, dp);
    
    maxVal = max(include, exclude);
    dp[index][W] = maxVal;
    
    return dp[index][W];
}

int knapSack(int N, int W, int val[], int wt[])
{
    int maxVal = 0;
    
    //Plain RE
    // int index = 0;
    // maxVal = solveUsingRE(index, N, W, val, wt);

    //Plain Mem
    int index = 0;
    vector<vector<int> > dp(N + 1, vector<int>(W + 1, -1));
    maxVal = solveUsingMem(index, N, W, val, wt, dp);
    
    return maxVal;
    
}

int main(){
   
return 0;
}