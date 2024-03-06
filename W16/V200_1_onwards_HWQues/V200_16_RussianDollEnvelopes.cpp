#include<bits/stdc++.h>
using namespace std;

/*****V200_16 : Russian Doll Envelopes [LeetCode : https://leetcode.com/problems/russian-doll-envelopes/description/]******/

//All functions will give TLE Except "solveUsingBS()" on LeetCode

int solveUsingRE(vector<vector<int>>& envelopes, int prev, int curr){
    //BC
    if(curr >= envelopes.size()){
        return 0;
    }

    int ans = 0;
    
    int include = INT_MIN;
    if(prev == -1 || (envelopes[prev][0] < envelopes[curr][0] && envelopes[prev][1] < envelopes[curr][1])){
        //Include "curr" envelope only if it is greater than "prev" envelope
        include = 1 + solveUsingRE(envelopes, curr, curr + 1);
    }
    int exclude = 0 + solveUsingRE(envelopes, prev, curr + 1);
    ans = max(include, exclude);
    return ans;

}

int solveUsingMem(vector<vector<int>>& envelopes, int prev, int curr, vector<vector<int> >& dp){
    //BC
    if(curr >= envelopes.size()){
        return 0;
    }

    if(dp[prev + 1][curr] != -1){
        return dp[prev + 1][curr];
    }

    int ans = 0;
    
    int include = INT_MIN;
    if(prev == -1 || (envelopes[prev][0] < envelopes[curr][0] && envelopes[prev][1] < envelopes[curr][1])){
        //Include "curr" envelope only if it is greater than "prev" envelope
        include = 1 + solveUsingMem(envelopes, curr, curr + 1, dp);
    }
    int exclude = 0 + solveUsingMem(envelopes, prev, curr + 1, dp);
    ans = max(include, exclude);
    dp[prev + 1][curr] = ans;
    
    return dp[prev + 1][curr];
}

//Make below function static if trying to use it on LeetCode inside the "Solution" class
bool comp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]){
        //Sort in descending order by height if width is equal
        return a[1] > b[1];
    }
    else{
        //Sort in ascending order by width
        return a[0] < b[0];
    }
}

//"solveUsingBS()" code copied from "L198 : 1)Longest Increasing Subsequence" with slight CHANGES
int solveUsingBS(vector<vector<int>>& nums){
    //Sort in ascending order by width
    //If width is equal, Sort in descending order by height 
    sort(nums.begin(), nums.end(), comp); //major CHANGE 1

    vector<int> ans; //isme answer build krunga i.e LISq

    //Initial state of answer : 0th index wala number to insert kr do, fir age ki algo chla denge
    ans.push_back(nums[0][1]);

    for(int i = 1; i < nums.size(); i++){
        //If current no is sabse bda no then dal do "ans" me
        if(nums[i][1] > ans.back()){
            ans.push_back(nums[i][1]);
        }
        else{
            //If current no se just bda number exist krta hai "ans" me to replace that with current no
            int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin(); //"index" will store index of this "current no se just bda number"
            ans[index] = nums[i][1];
        }
    }
    return ans.size();

}


int maxEnvelopes(vector<vector<int>>& envelopes) {
    int ans = 0;

    //PlainRE
    // sort(envelopes.begin(), envelopes.end()); //Sort envelopes small to big
    // int prev = -1;
    // int curr = 0;
    // ans = solveUsingRE(envelopes, prev, curr); 

    //Mem
    // sort(envelopes.begin(), envelopes.end()); //Sort envelopes small to big
    // int prev = -1;
    // int curr = 0;
    // vector<vector<int> > dp(envelopes.size() + 1, vector<int>(envelopes.size() + 1, -1)); //row x col :: prev x start
    // ans = solveUsingMem(envelopes, prev, curr, dp); 

    //Using BS
    ans = solveUsingBS(envelopes);

    return ans;
}

int main(){
   
return 0;
}