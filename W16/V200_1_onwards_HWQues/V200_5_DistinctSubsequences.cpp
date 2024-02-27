#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/****V200_5 : Distinct Subsequences [LeetCode : https://leetcode.com/problems/distinct-subsequences/description/]******/

//TC : Exponential (2 RE calls of include & exclude at each step of RE Tree)
int solveUsingRE(string& s, string& t, int sptr, int tptr){
    //BC
    if(tptr >= t.length()){
        //Means t caompletely matched!
        return 1;
    }
    if(sptr >= s.length()){
        //Means s over but t not matched!
        return 0;
    } 

    int ans = 0;
    if(s[sptr] == t[tptr]){
        //Include current char from s & match with current char in t
        ans += solveUsingRE(s, t, sptr + 1, tptr + 1);
    }
    //Exclude current char from s (So, no matching with current char in t) 
    //You can always choose to exclude current char from s but U can choose to include it (i.e match it) only if it equals current char in t 
    ans += solveUsingRE(s, t, sptr + 1, tptr);

    return ans;
}

int solveUsingMem(string& s, string& t, int sptr, int tptr, vector<vector<int> >& dp){
    //BC
    if(tptr >= t.length()){
        //Means t completely matched!
        return 1;
    }
    if(sptr >= s.length()){
        //Means s over but t not matched!
        return 0;
    } 

    if(dp[sptr][tptr] != -1){
        // cout<<"DP Used : "<<endl<<"s: "<<s.substr(sptr)<<" t: "<<t.substr(tptr)<<endl;
        return dp[sptr][tptr];
    }

    int ans = 0;
    if(s[sptr] == t[tptr]){
        //Include current char of s & match with current char in t
        ans += solveUsingMem(s, t, sptr + 1, tptr + 1, dp);
    }
    //Exclude current char of s (So, no matching with current char in t) 
    //You can always choose to exclude current char of s but U can choose to include it (i.e match it) only if it equals current char in t 
    ans += solveUsingMem(s, t, sptr + 1, tptr, dp);
    dp[sptr][tptr] = ans;

    return dp[sptr][tptr];
}

//TC : O(n * m)
//n : length of s
//m : length of t
unsigned long long int solveUsingTab(string& s, string& t){
    vector<vector<unsigned long long int> > dp(s.length() + 1, vector<unsigned long long int> (t.length() + 1, -1));

    for(int tptr = 0; tptr <= t.length(); tptr++){
        dp[s.length()][tptr] = 0;
    }

    for(int sptr = 0; sptr <= s.length(); sptr++){
        dp[sptr][t.length()] = 1;
    }

    for(int sptr_i = s.length() - 1; sptr_i >= 0; sptr_i--){
        for(int tptr_i = t.length() - 1; tptr_i >= 0; tptr_i--){
            
            //You can add below line as we know from the RE soln that sptr_i can NEVER be less that tptr_i (sptr_i always increments but tptr_i does not in "exclude" case)
            // I originally added this line bcz i was trying to avoid int-overflow but vo to nhi hua! last me i had to use "unsigned long long int" (it's range is huge!) 
            if(sptr_i < tptr_i) continue; 

            unsigned long long int ans = 0;
            if(s[sptr_i] == t[tptr_i]){
                //Include current char from s & match with current char in t
                ans = ans + dp[sptr_i + 1][tptr_i + 1];
            }
            //Exclude current char from s (So, no matching with current char in t) 
            //You can always choose to exclude current char from s but U can choose to include it (i.e match it) only if it equals current char in t 

            ans = (ans + dp[sptr_i + 1][tptr_i]);

            dp[sptr_i][tptr_i] = ans;
        }
    }

    return dp[0][0];
}

//TabuationSO() {DIY} {Soln video me nhi tha but can be done!}

int numDistinct(string s, string t) {
    // //Plain RE
    // int sptr = 0;
    // int tptr = 0;
    // int ans = solveUsingRE(s, t, sptr, tptr);

    // //Mem
    // vector<vector<int> > dp(s.length() + 1, vector<int> (t.length() + 1, -1)); //row x col :: sptr x tptr
    // int sptr = 0;
    // int tptr = 0;
    // int ans = solveUsingMem(s, t, sptr, tptr, dp);
    
    //Tab
    int sptr = 0;
    int tptr = 0;
    int ans = solveUsingTab(s, t); //even though "solveUsingTab()" returns "unsigned long long int" but ATQ, the test cases are generated so that the answer fits on a 32-bit signed integer.

    return ans;   
}

int main(){
   
return 0;
}