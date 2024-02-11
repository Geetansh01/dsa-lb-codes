#include<iostream>
#include<vector>
using namespace std;

/*****House Robber [LeetCode : https://leetcode.com/problems/house-robber/description/]****/

//Using Plain RE
int solveUsingRE(vector<int>& nums, int index){
    //Base Case
    if(index >= nums.size()){
        return 0;
    }

    //Recursive Relation
    int include = nums[index] + solveUsingRE(nums, index+2);
    int exclude = 0 + solveUsingRE(nums, index+1);
    int ans = max(include, exclude);
    return ans;
}

//RE+Mem
int solveUsingMem(vector<int>& nums, int index, vector<int>& dp){
    //Base Case
    if(index >= nums.size()){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    //Recursive Relation
    int include = nums[index] + solveUsingMem(nums, index+2, dp);
    int exclude = 0 + solveUsingMem(nums, index+1, dp);
    dp[index] = max(include, exclude);
    return dp[index];
}

//Tabulation
int solveUsingTab(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, -1); //dp "n" size ki le bcz max subproblems (i.e index) 0 to n-1 tk ja skti hai (i.e total "n" size)
    
    //Step 2 :
    //This is a bit tricky, think what dp[index] represents?
    dp[n-1] = nums[n-1];

    //Step 3
    for(int index = n-2; index >= 0; index--){
        int tempAns = 0;
        if((index  + 2) < n){
            tempAns = dp[index + 2];
        }
        int include = nums[index] + tempAns;
        int exclude = 0 + dp[index+1];
        dp[index] = max(include, exclude);
    }

    return dp[0];
}

//Tabulation Space Optimized
int solveUsingTabSO(vector<int>& nums){
    int n = nums.size();
    // vector<int> dp(n, -1); //dp "n" size ki le bcz max subproblems (i.e index) 0 to n-1 tk ja skti hai (i.e total "n" size)
    
    //Step 2 :
    //This is a bit tricky, think what dp[index] represents?
    // dp[n-1] = nums[n-1];
    int prev = nums[n-1];
    int next = 0;
    int currAns = 0;

    //Step 3
    for(int index = n-2; index >= 0; index--){
        int tempAns = 0;
        if((index  + 2) < n){
            tempAns = next;
        }
        int include = nums[index] + tempAns;
        int exclude = 0 + prev;
        currAns = max(include, exclude);

        //WARNING : Bhule ga tu, update next, prev
        next = prev;
        prev = currAns;
    }

    // return currAns; //Ye fse ga "nums = [1]" me 
    return prev;
}

int rob(vector<int>& nums) {
    //Using Plain RE
    // int index = 0;
    // int ans = solveUsingRE(nums, index);
    // return ans;

    //Using RE + Mem
    // int n = nums.size();
    // vector<int> dp(n, -1); //dp "n" size ki le bcz max subproblems (i.e index) 0 to n-1 tk ja skti hai (i.e total "n" size)
    // int index = 0;
    // int ans = solveUsingMem(nums, index, dp);
    // return ans;

    //Tabulation    
    // int ans = solveUsingTab(nums);
    // return ans;

    //Tabulation SO 
    int ans = solveUsingTabSO(nums);
    return ans;
}

int main(){
   
return 0;
}