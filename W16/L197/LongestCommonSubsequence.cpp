#include<iostream>
#include<vector>
using namespace std;

/***Longest Common Subsequence [LeetCode : https://leetcode.com/problems/longest-common-subsequence/description/]***/

int solveUsingRE(string a, string b, int i, int j){
    //Base Case 
    if(i >= a.length()){
        return 0;
    }
    if(j >= b.length()){
        return 0;
    }

    //RE Logic
    int ans = 0;
    if(a[i] == b[j]){
        //current chars match
        ans = 1 + solveUsingRE(a, b, i+1, j+1);
    }
    else{
        //current chars don't match
        ans = 0 + max(solveUsingRE(a, b, i, j+1), 
                        solveUsingRE(a, b, i+1, j));
    }

    return ans;
}

int solveUsingMem(string& a, string& b, int i, int j,  vector<vector<int> >& dp){
    //Base Case 
    if(i >= a.length()){
        return 0;
    }
    if(j >= b.length()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //RE Logic
    int ans = 0;
    if(a[i] == b[j]){
        //current chars match
        ans = 1 + solveUsingMem(a, b, i+1, j+1, dp);
    }
    else{
        //current chars don't match
        ans = 0 + max(solveUsingMem(a, b, i, j+1, dp), 
                        solveUsingMem(a, b, i+1, j, dp));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

//Tabulation
int solveUsingTab(string a, string b){
    vector<vector<int> > dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    //Fill initial data : done by initializing dp[][] with 0

    for(int i_index = a.length()-1; i_index >= 0; i_index--){
        for(int j_index = b.length()-1; j_index >= 0; j_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    //current chars match
                    ans = 1 + dp[i_index+1][j_index+1];
                }
                else{
                    //current chars don't match
                    ans = 0 + max(dp[i_index][j_index+1], 
                                    dp[i_index+1][j_index]);
                }

                dp[i_index][j_index] = ans;  
        }
    }

    return dp[0][0];
}

//TabulationSO
int solveUsingTabSO(string a, string b){
    // vector<vector<int> > dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(a.length() + 1, 0);
    //Fill initial data : done by initializing next[] with 0

    for(int j_index = b.length()-1; j_index >= 0; j_index--){
        for(int i_index = a.length()-1; i_index >= 0; i_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    //current chars match
                    ans = 1 + next[i_index+1];
                }
                else{
                    //current chars don't match
                    ans = 0 + max(next[i_index], 
                                    curr[i_index+1]);
                }

                curr[i_index] = ans;  
        }

        // Updation of next
        next = curr;
    }

    return curr[0];
}

//TabulationSO without loop change compared to pure Tabulation (Sb purana logic hai, try to see dp me filling kaise hori hai)
int solveUsingTabSONoLoopChange(string a, string b){
    // vector<vector<int> > dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    vector<int> currRow(b.length() + 1, 0);
    vector<int> nextRow(b.length() + 1, 0);

    //Fill initial data : done by initializing next[] with 0

    for(int i_index = a.length()-1; i_index >= 0; i_index--){
        for(int j_index = b.length()-1; j_index >= 0; j_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    //current chars match
                    ans = 1 + nextRow[j_index+1];
                }
                else{
                    //current chars don't match
                    ans = 0 + max(currRow[j_index+1], 
                                    nextRow[j_index]);
                }
                currRow[j_index] = ans;
        }

        //Update next
        nextRow = currRow;  
    }

    return nextRow[0];
}

int longestCommonSubsequence(string text1, string text2) {
    //Plain RE
    // int i = 0;
    // int j = 0;
    // int ans = solveUsingRE(text1, text2, i, j);
    // return ans;

    //RE + Mem
    // vector<vector<int> > dp(text1.length() + 1, vector<int>(text2.length() + 1, -1)); //row x col :: i X j
    // int i = 0;
    // int j = 0;
    // int ans = solveUsingMem(text1, text2, i, j, dp);
    // return ans;

    //Tabulation
    // int ans = solveUsingTab(text1, text2);
    // return ans;

    //TabulationSO
    // int ans = solveUsingTabSO(text1, text2);
    // return ans;

    //TabulationSO without loop change compared to pure Tabulation (Sb purana logic hai, try to see dp me filling kaise hori hai)
    int ans = solveUsingTabSONoLoopChange(text1, text2);
    return ans;
}

int main(){
   
return 0;
}