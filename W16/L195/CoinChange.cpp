#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/****Coin Change [Interview] [LeetCode : https://leetcode.com/problems/coin-change/]******/

//For TC, SC, see Tabulation solution below

//Plain RE
int solveUsingRE(vector<int>& coins, int amount){
    //Base Case
    if(amount == 0){
        return 0;
    }

    //Recursive Relation
    int minCoinCnt = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        //Find ans using ith coin
        //Call RE only for valid amounts i.e >= 0 wale amounts
        if(amount - coins[i] >= 0){
            int RecursionKaAns = solveUsingRE(coins, amount-coins[i]);
            //If a valid answer receieved from RE
            if(RecursionKaAns != INT_MAX){
                int ans = 1 + RecursionKaAns;
                minCoinCnt = min(minCoinCnt, ans);
            }
        }
    }

    return minCoinCnt;
}

//RE + Mem
int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp){
    //Base Case
    if(amount == 0){
        return 0;
    }

    //If answer already in dp[]
    if(dp[amount] != -1){
        return dp[amount];
    }

    //Recursive Relation
    int minCoinCnt = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        //Find ans using ith coin
        //Call RE only for valid amounts i.e >= 0 wale amounts
        if(amount - coins[i] >= 0){
            //WARNING : Bhule ga tu, remember to change name of function when copying code from plain RE code
            int RecursionKaAns = solveUsingMem(coins, amount-coins[i], dp);
            //If a valid answer receieved from RE
            if(RecursionKaAns != INT_MAX){
                int ans = 1 + RecursionKaAns;
                minCoinCnt = min(minCoinCnt, ans);
            }
        }
    }

    dp[amount] = minCoinCnt;
    return dp[amount];
}

//Tabulation
//TC : O(amount * N) ; N = No. of Coins {Bcz of nested for() loops below}
//SC : O(amount) {Bcz Of DP Array}
//Same TC, SC for (RE + Mem), but easier to calculate in Tabulation's code
int solveUsingTab(vector<int>& coins, int amount){
    //Step 1
    int n = amount;
    vector<int> dp(n+1, -1);
    
    //Step 2 : analyse base case of Plain RE 
    dp[0] = 0;

    for(int k = 1; k <= amount; k++){
        //Copy-Pasting the below lines from "solveUsingMem()" function & making necessary changes 
        //(Leaving even the comments even though they are not relevant to help you see the copy-paste)

        //Recursive Relation
        int minCoinCnt = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            //Find ans using ith coin
            //Call RE only for valid amounts i.e >= 0 wale amounts
            if(k - coins[i] >= 0){
                int RecursionKaAns = dp[k-coins[i]]; //line (1)
                //If a valid answer receieved from RE
                if(RecursionKaAns != INT_MAX){
                    int ans = 1 + RecursionKaAns;
                    minCoinCnt = min(minCoinCnt, ans);
                }
            }
        }
        dp[k] = minCoinCnt;

        /*
            Tabulation with Space Optimization Not possible here bcz:
            1)"dp[k]" ultimately depends on "dp[k-coins[i]]" in line (1). "dp[k-coins[i]]" kind of uses the entire dp[], lets's see how using a simple 
                hand-waving example:
                Say you have coins of Denomination : 1, 2, 3, 4, 5, 6, 7... & k = 10
                Now "k-coins[i]" can be : (10 - 1 = 9), (10 - 2 = 8), 7, 6, ...
                So you need dp[9], dp[8], dp[7], dp[6], ...

                So, entire dp[] array is needed!
        */

    }

    return dp[amount];
}


int coinChange(vector<int>& coins, int amount) {
    //Using Plain RE
    // int ans = solveUsingRE(coins, amount);
    // return (ans == INT_MAX ? -1 : ans);

    //RE + Mem
    // int n = amount;
    // vector<int> dp(n+1, -1); //upr "solveUsingMem()" me dp[amount] access kiya hua hai to total indexes "amount + 1" hone chaiye
    // int ans = solveUsingMem(coins, amount, dp);
    // return (ans == INT_MAX ? -1 : ans);

    //Tabulation
    int ans = solveUsingTab(coins, amount);
    return (ans == INT_MAX ? -1 : ans);
}

int main(){
   
return 0;
}