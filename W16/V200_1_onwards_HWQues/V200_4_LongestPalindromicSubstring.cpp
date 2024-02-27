#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/******************V200_4 : Longest Palindromic Substring [LeetCode : https://leetcode.com/problems/longest-palindromic-substring/]*********************************************/

//RE chk Palindrome function
bool chkPalindromeRE(string& s, int start, int end){
    //BC
    if(start >= end) return true;

    bool temp = false;
    if(s[start] == s[end]){
        temp = chkPalindromeRE(s, start+1, end-1);
    }
    else{
        temp = false;
    }

    return temp;
}

bool chkPalindromeMem(string& s, int start, int end, vector<vector<int> >& dp){
    //BC
    if(start >= end) return true;

    if(dp[start][end] != -2){
        return dp[start][end];
    }

    bool temp = false;
    if(s[start] == s[end]){
        temp = chkPalindromeMem(s, start+1, end-1, dp);
    }
    else{
        temp = false;
    }
    dp[start][end] = temp;

    return dp[start][end];
}

string longestPalindrome(string s) {
    int maxPalinLen = INT_MIN;
    int startIndexOfAns = -1;

    //Mem
    vector<vector<int> > dp(s.length() + 1, vector<int>(s.length() + 1, -2)); //row x col :: start x end
    //-2 means No answer in dp (0 : true, 1 : false)

    for(int start = 0; start < s.length(); start++){
        for(int end = start; end < s.length(); end++){
            int currLen = end - start + 1;

            //Plain RE
            // bool chkResult = (currLen > maxPalinLen && chkPalindromeRE(s, start, end));

            //Mem
            //dp made outside
            bool chkResult = (currLen > maxPalinLen && chkPalindromeMem(s, start, end, dp));

            if(chkResult){
                maxPalinLen = currLen;
                startIndexOfAns = start;
            }
        }
    }

    string ansStr = s.substr(startIndexOfAns, maxPalinLen);

    return ansStr;   
}

int main(){
   
return 0;
}