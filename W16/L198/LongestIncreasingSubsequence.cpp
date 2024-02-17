#include<iostream>
#include<vector>
using namespace std;

/****Longest Increasing Subsequence [Interview][Pattern Based][LeetCode : https://leetcode.com/problems/longest-increasing-subsequence/description/]*****/

int solveUsingRE(vector<int>& nums, int curr, int prev){
    //base case
    if(curr >= nums.size()){
        //Out of nums array, no number to put in subsequence
        return 0;
    }

    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev]){
        include = 1 + solveUsingRE(nums, curr+1, curr);
    }
    int exclude = 0 + solveUsingRE(nums, curr+1, prev);
    int ans = max(include, exclude);
    return ans; 
}

int solveUsingMem(vector<int>& nums, int curr, int prev, vector<vector<int> >& dp){
    //base case
    if(curr >= nums.size()){
        //Out of nums array, no number to put in subsequence
        return 0;
    }

    if(dp[curr][prev+1] != -1){
        //Index shifting in dp : "prev" -1 se initialized hai but that is not a valid column in dp
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev]){
        include = 1 + solveUsingMem(nums, curr+1, curr, dp);
    }
    int exclude = 0 + solveUsingMem(nums, curr+1, prev, dp);
    dp[curr][prev+1] = max(include, exclude);
    return dp[curr][prev+1]; 
}

int solveUsingTab(vector<int>& nums){
    int n = nums.size();
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0)); //row x col :: curr x prev

    //Fill initial data : done by initializing entire dp with 0 (Vaise to khali last row (i.e row = nums.size()) me 0 bharna tha)

    for(int curr_index = n-1; curr_index >= 0; curr_index--){
        //RE+Mem me "prev" worst case me "curr" se just piche ho skta hai but can never be equal to or ahead of it!
        for(int prev_index = curr_index - 1; prev_index >= -1; prev_index--){
            int include = 0;
            if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                include = 1 + dp[curr_index+1][curr_index+1];
            }
            int exclude = 0 + dp[curr_index+1][prev_index+1];
            dp[curr_index][prev_index+1] = max(include, exclude);
        }
    }

    return dp[0][-1+1]; //Shifting ke liye "prev" ko +1 krna hai in dp[][]
}

//TC : O(n^2)
//SC : O(n)
int solveUsingTabSO(vector<int>& nums){
    int n = nums.size();
    // vector<vector<int> > dp(n+1, vector<int>(n+1, 0)); //row x col :: curr x prev
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    //Fill initial data : done by initializing entire dp with 0 (Vaise to khali last row (i.e row = nums.size()) me 0 bharna tha)

    for(int curr_index = n-1; curr_index >= 0; curr_index--){
        //RE+Mem me "prev" worst case me "curr" se just piche ho skta hai but can never be equal to or ahead of it!
        for(int prev_index = curr_index - 1; prev_index >= -1; prev_index--){
            int include = 0;
            if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                include = 1 + nextRow[curr_index+1];
            }
            int exclude = 0 + nextRow[prev_index+1];
            currRow[prev_index+1] = max(include, exclude);
        }

        //Update nextRow
        nextRow = currRow;
    }

    return nextRow[0];
}

//TC : O(n log n)
//SC : O(n)
int solveUsingBS(vector<int>& nums){
    vector<int> ans; //isme answer build krunga i.e LISq

    //Initial state of answer : 0th index wala number to insert kr do, fir age ki algo chla denge
    ans.push_back(nums[0]);

    for(int i = 1; i < nums.size(); i++){
        //If current no is sabse bda no then dal do "ans" me
        if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            //If current no se just bda number exist krta hai "ans" me to replace that with current no
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); //"index" will store index of this "current no se just bda number"
            ans[index] = nums[i];
        }
    }
    return ans.size();

}

int lengthOfLIS(vector<int>& nums) {
    //Plain RE
    // int curr = 0;
    // int prev = -1;
    // int ans = solveUsingRE(nums, curr, prev);
    // return ans;

    // //RE + Mem
    // int n = nums.size();
    // vector<vector<int> > dp(n+1, vector<int>(n+1, -1)); //row x col :: curr x prev
    // int curr = 0;
    // int prev = -1;
    // int ans = solveUsingMem(nums, curr, prev, dp);
    // return ans;

    //Tabulation
    // int ans = solveUsingTab(nums);
    // return ans;

    //TabulationSO
    // int ans = solveUsingTabSO(nums);
    // return ans;

    //Binary Search
    int ans = solveUsingBS(nums);
    return ans;
}

int main(){
   
return 0;
}