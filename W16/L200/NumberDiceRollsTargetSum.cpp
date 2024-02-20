#include<iostream>
#include<vector>
using namespace std;

/****Number of Dice Rolls With Target Sum [LeetCode : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/]*****/


#define MOD 1000000007
int solveUsingRE(int diceUsed, int currSum, int n, int k, int target){
    //Base Case
    if(currSum == target && diceUsed == n){
        //1 way milgya
        return 1;
    }
    if(currSum != target && diceUsed == n){
        //n ke n dice roll kr diye, no more die to roll
        return 0;
    }
    if(currSum == target && diceUsed != n){
        //Jldi target bn gya, abhi die bche the
        return 0;
    }
    if(currSum > target){
        //target Overshoot hogya (like 5 bnana tha but 6 bn gya)
        return 0;
    }

    int ans = 0;
    for(int face = 1; face <= k; face++){
        ans += solveUsingRE(diceUsed + 1, currSum + face, n, k, target);
    }

    return ans;
}

int solveUsingMem(int diceUsed, int currSum, int n, int k, int target, vector<vector<int> >& dp){
    //Base Case
    if(currSum == target && diceUsed == n){
        //1 way milgya
        return 1;
    }
    if(currSum != target && diceUsed == n){
        //n ke n dice roll kr diye, no more die to roll
        return 0;
    }
    if(currSum == target && diceUsed != n){
        //Jldi target bn gya, abhi die bche the
        return 0;
    }
    if(currSum > target){
        //target Overshoot hogya (like 5 bnana tha but 6 bn gya)
        return 0;
    }

    if(dp[diceUsed][currSum] != -1){
        return dp[diceUsed][currSum];
    }

    int ans = 0;
    for(int face = 1; face <= k; face++){
        int recKaAns = solveUsingMem(diceUsed + 1, currSum + face, n, k, target, dp);
        ans = ((ans%MOD) + recKaAns)%MOD;
    }

    dp[diceUsed][currSum]  = ans;
    return dp[diceUsed][currSum] ;
}

int solveUsingTab(int n, int k, int target){
    vector<vector<int> > dp(n+1, vector<int> (target+1, 0)); //row x col :: diceUsed x currSum
    
    dp[n][target] = 1;

    for(int dice = n-1; dice >= 0; dice--){
        for(int sum = target-1; sum >= 0; sum--){

            int ans = 0;
            for(int face = 1; face <= k; face++){
                int recKaAns = 0;
                if(sum + face <= target){
                    recKaAns = dp[dice + 1][sum + face];
                }
                ans = ((ans%MOD) + recKaAns)%MOD;
            }

            dp[dice][sum]  = ans;
        }
    }

    return dp[0][0];
}

int solveUsingTabSO(int n, int k, int target){
    // vector<vector<int> > dp(n+1, vector<int> (target+1, 0)); //row x col :: diceUsed x currSum
    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);

    next[target] = 1;

    for(int dice = n-1; dice >= 0; dice--){
        for(int sum = target-1; sum >= 0; sum--){

            int ans = 0;
            for(int face = 1; face <= k; face++){
                int recKaAns = 0;
                if(sum + face <= target){
                    recKaAns = next[sum + face];
                }
                ans = ((ans%MOD) + recKaAns)%MOD;
            }

            curr[sum]  = ans;
        }

        //Update next
        next = curr;
    }

    return next[0];
}

int numRollsToTarget(int n, int k, int target) {
    //Plain RE
    // int currSum = 0;
    // int diceUsed = 0;
    // int ans = solveUsingRE(currSum, diceUsed, n, k, target);
    // return ans;

    //RE+Mem
    // vector<vector<int> > dp(n+1, vector<int> (target+1, -1)); //row x col :: diceUsed x currSum
    // int currSum = 0;
    // int diceUsed = 0;
    // int ans = solveUsingMem(currSum, diceUsed, n, k, target, dp);
    // return ans;

    //Tab
    // int ans = solveUsingTab(n, k, target);
    // return ans;

    //TabSO
    int ans = solveUsingTabSO(n, k, target);
    return ans;
}


int main(){
   
return 0;
}