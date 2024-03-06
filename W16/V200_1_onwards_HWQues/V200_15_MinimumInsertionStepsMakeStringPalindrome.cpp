#include<bits/stdc++.h>
using namespace std;


//M1 : Using logic of "L197 : 1)Longest Palindromic Subsequence"
//"solveUsingTabSO()" & "longestPalindromeSubseq()" taken from "L197 : 1)Longest Palindromic Subsequence"
//TabulationSO
int solveUsingTabSO(string a, string b){
    // vector<vector<int> > dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(a.length() + 1, 0);
    //Fill initial data : done by initializing dp[][] with 0

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

int longestPalindromeSubseq(string s) {
    string a = s;
    reverse(a.begin(), a.end());
    int ans = solveUsingTabSO(a, s);
    return ans;
}

int minInsertions(string s) {
    //Length of Longest Palindromic Subsequence (LPSq) from s
    int LPSqLen = longestPalindromeSubseq(s);

    //Minimum Insertion Steps to Make a "s" Palindrome
    int minSteps = s.length() - LPSqLen;

    return minSteps;
}


//M2 : My own Solution :) [Also submitted on LeetCode with same TC as M1 !]
// int solveUsingRE(string &s, int start, int end){
//     //BC
//     if(start >= end) return 0;

//     int minSteps = 0;
//     while(start < end){
//         if(s[start] == s[end]){
//             start++; end--;
//         }
//         else{
//             //Option 1
//             int option1 = 1 + solveUsingRE(s, start + 1, end);

//             //Option 2
//             int option2 = 1 + solveUsingRE(s, start, end - 1);

//             minSteps = min(option1, option2);
//             break;
//         }
//     } 

//     return minSteps;
// }

// int solveUsingMem(string &s, int start, int end, vector<vector<int> >& dp){
//     //BC
//     if(start >= end) return 0;

//     if(dp[start][end] != -1){
//         return dp[start][end];
//     }

//     int minSteps = 0;
//     while(start < end){
//         if(s[start] == s[end]){
//             start++; end--;
//         }
//         else{
//             //Option 1
//             int option1 = 1 + solveUsingMem(s, start + 1, end, dp);

//             //Option 2
//             int option2 = 1 + solveUsingMem(s, start, end - 1, dp);

//             minSteps = min(option1, option2);
//             break;
//         }
//     } 

//     dp[start][end] = minSteps;
//     return dp[start][end];
// }

// int solveUsingTab(string &str){
//     vector<vector<int> > dp(str.length() + 1, vector<int>(str.length() + 1, 0));

//     for(int start_i = str.length() - 1; start_i >= 0; start_i--){
//         for(int end_i = 1; end_i <= str.length() - 1; end_i++){
//             if(start_i >= end_i) continue;

//             int minSteps = 0;
//             int s = start_i;
//             int e = end_i;
//             while(s < e){
//                 if(str[s] == str[e]){
//                     s++; e--;
//                 }
//                 else{
//                     //Option 1
//                     int option1 = 1 + dp[s + 1][e];

//                     //Option 2
//                     int option2 = 1 + dp[s][e - 1];

//                     minSteps = min(option1, option2);
//                     break;
//                 }
//             }
//             dp[start_i][end_i] = minSteps;
//         }
//     }

//     return dp[0][str.length() - 1];
// }

// int minInsertions(string s) {
//     int minSteps = 0;

//     //Plain RE
//     // int start = 0;
//     // int end = s.length() - 1;
//     // minSteps = solveUsingRE(s, start, end);

//     //Mem
//     // int start = 0;
//     // int end = s.length() - 1;
//     // vector<vector<int> > dp(s.length() + 1, vector<int>(s.length() + 1, -1));
//     // minSteps = solveUsingMem(s, start, end, dp);

//     //Tabulation
//     minSteps = solveUsingTab(s);

//     return minSteps;
// }

int main(){
   
return 0;
}