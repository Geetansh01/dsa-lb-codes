#include<iostream>
#include<vector>
using namespace std;

/***Partition Equal Subset Sum [LeetCode : https://leetcode.com/problems/partition-equal-subset-sum/description/]*****/
//RE Pattern : Include /Exclude
bool solveUsingRE(vector<int>& nums, int index, int sum, int target){
    //Base Case
    if(index >= nums.size()){
        return false;
    }
    if(sum > target){
        return false;
    }
    if(sum == target){
        return true; //or return 1
    }

    //Recursive Relation
    bool include = solveUsingRE(nums, index+1, sum + nums[index], target);
    bool exclude = solveUsingRE(nums, index+1, sum, target);

    return include || exclude;
}

bool solveUsingMem(vector<int>& nums, int index, int sum, int target, vector<vector<int> >& dp){
    //Base Case
    if(index >= nums.size()){
        return false;
    }
    if(sum > target){
        return false;
    }
    if(sum == target){
        return true;
    }

    if(dp[index][sum] != -1){
        return dp[index][sum];
    }

    //Recursive Relation
    bool include = solveUsingMem(nums, index+1, sum + nums[index], target, dp);
    bool exclude = solveUsingMem(nums, index+1, sum, target, dp);

    bool ans = (include || exclude); 
    dp[index][sum] = ans;
    return dp[index][sum];
}

bool solveUsingTab(vector<int>& nums, int& target){
    int n = nums.size(); 
    vector<vector<int> > dp(n + 1, vector<int>(target+1, -1)); //row x col :: index x sum

    //Fill initial Data : Using Base Case Analysis
    for(int row = 0; row <= n; row++){
        dp[row][target] = 1;
    }

    for(int col = 0; col <= target; col++){
        dp[n][col] = 0;
    }

    for(int ind = n-1; ind >= 0; ind--){
        for(int s = target-1; s >= 0; s--){
            
            bool include = 0;
            if((s + nums[ind]) > target){
                include = 0;
            }
            else{
                include = dp[ind+1][s + nums[ind]];
            }

            bool exclude = dp[ind+1][s];

            bool ans = (include || exclude); 
            dp[ind][s] = ans;
        }
    }

    return dp[0][0];

}

bool solveUsingTabSO(vector<int>& nums, int& target){
    int n = nums.size(); 
    // vector<vector<int> > dp(n + 1, vector<int>(target+1, -1)); //row x col :: index x sum
    vector<int> currRow(target+1, -1);
    vector<int> nextRow(target+1, -1);

    //Fill initial Data : Using Base Case Analysis
    currRow[target] = 1;
    nextRow[target] = 1;
    
    for(int col = 0; col <= target; col++){
        nextRow[col] = 0;
    }
    
    for(int ind = n-1; ind >= 0; ind--){
        for(int s = target-1; s >= 0; s--){
            
            bool include = 0;
            if((s + nums[ind]) > target){
                include = 0;
            }
            else{
                include = nextRow[s + nums[ind]];
            }

            bool exclude = nextRow[s];

            bool ans = (include || exclude); 
            nextRow[s] = ans;
        }

        //update nextRow
        nextRow = currRow;
    }

    return nextRow[0];

}

bool canPartition(vector<int>& nums) {
    int index = 0;
    int totalSum = 0;
    for(int i = 0; i < nums.size(); i++){
        totalSum += nums[i];
    }

    if(totalSum & 1){
        //If "totalSum" is odd then partitioning not possible
        //Reason : Odd no can Not be divided into two equal halves
        return false;
    }

    //Plain RE
    // int target = totalSum/2;
    // int currSum = 0;
    // bool ans = solveUsingRE(nums, index, currSum, target);
    // return ans;

    //RE+Mem
    // int target = totalSum/2;
    // int currSum = 0;
    //-1 : dp me answer nhi hai
    //0 : dp me answer hai & vo answer is false
    //1 : dp me answer hai & vo answer is true
    // vector<vector<int> > dp(nums.size() + 1, vector<int>(target+1, -1)); //row x col :: index x sum
    // bool ans = solveUsingMem(nums, index, currSum, target, dp);
    // return ans;

    //Tabulation
    // int target = totalSum/2;
    // bool ans = solveUsingTab(nums, target);
    // return ans;

    //Tabulation SO
    int target = totalSum/2;
    bool ans = solveUsingTab(nums, target);
    return ans;
}

int main(){
   
return 0;
}