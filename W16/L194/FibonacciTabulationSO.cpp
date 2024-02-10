#include<iostream>
#include<vector>
using namespace std;

/**********************Fibonacci using Top Down DP [LeetCode : https://leetcode.com/problems/fibonacci-number/description/]******************/

//TC : O(n)

//Tabulation method Space Optimised
//Leaving Steps as before for comparison with normal Tabulation
int solveUsingTabulationSpaceOptimised(int n){
    //Step 1 : create dp array
    // vector<int> dp(n+1, -1); 

    //Step 2 : Fill initial data
    int prev = 0; 
    if(n == 0) return prev;
    int curr = 1;
    if(n == 1) return curr; //Ye Separately handle krna pda

    //Step 3 : Fill rest of dp array
    int ans;
    for(int k = 2; k <= n; k++){
        ans = curr + prev;

        //Update prev & curr
        prev = curr;
        curr = ans;
    }

    return ans;
}

int fib(int n) {
    //Tabulation Method
    int ans = solveUsingTabulationSpaceOptimised(n);
    return ans;
}

int main(){
   
return 0;
}