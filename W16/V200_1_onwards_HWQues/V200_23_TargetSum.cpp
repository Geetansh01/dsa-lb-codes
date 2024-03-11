#include<bits/stdc++.h>
using namespace std;


int solveUsingRE(vector<int>& nums, int target, int index){
    //BC
    if(index >= nums.size() && target == 0)return 1;
    if(index >= nums.size() && target != 0) return 0;

    int totWays = 0;
    //Option1 : make current number '+'
    int option1 = solveUsingRE(nums, target - nums[index], index + 1);

    //Option2 : make current number '-'
    int option2 = solveUsingRE(nums, target + nums[index], index + 1);

    totWays = option1 + option2;
    return totWays;
}

int solveUsingMem(vector<int>& nums, int target, int index, vector<vector<int> >& dp){
    //BC
    if(index >= nums.size() && target == 0)return 1;
    if(index >= nums.size() && target != 0) return 0;

    if(dp[target + 2000][index] != -1){
        return dp[target + 2000][index];
    }

    int totWays = 0;
    //Option1 : make current number '+'
    int option1 = solveUsingMem(nums, target - nums[index], index + 1, dp);

    //Option2 : make current number '-'
    int option2 = solveUsingMem(nums, target + nums[index], index + 1, dp);

    totWays = option1 + option2;
    dp[target + 2000][index] = totWays; 
    return dp[target + 2000][index];
}

int solveUsingMem2(vector<int>& nums, int target, int index, map<pair<int, int>, int>& dp){
    //BC
    if(index >= nums.size() && target == 0)return 1;
    if(index >= nums.size() && target != 0) return 0;

    auto iterator = dp.find({target, index});
    if(iterator != dp.end()){
        return iterator->second;
    }

    int totWays = 0;
    //Option1 : make current number '+'
    int option1 = solveUsingMem2(nums, target - nums[index], index + 1, dp);

    //Option2 : make current number '-'
    int option2 = solveUsingMem2(nums, target + nums[index], index + 1, dp);

    totWays = option1 + option2;
    dp[{target, index}] = totWays; 
    return dp[{target, index}];
}

int solveUsingTab(vector<int>& nums, int target){
    map<pair<int, int>, int> dp; //{target x index} ---> ways 

    //Fill initial data
    int maxSum = 0;
    for(auto& num : nums){
        maxSum += num;
    }

    //Base Case 1
    for(int target_i = target - maxSum; target_i <= target + maxSum; target_i++){
        dp[{target_i, nums.size()}] = 0;
    }

    //Base Case 2
    dp[{0, nums.size()}] = 1;

    //Fill rest of DP
    for(int index_i = nums.size() - 1; index_i >= 0; index_i--){
        for(int target_i = target - maxSum; target_i <= target + maxSum; target_i++){
            
            auto iterator1 = dp.find({target_i - nums[index_i], index_i + 1});
            auto iterator2 = dp.find({target_i + nums[index_i], index_i + 1});
            if(iterator1 == dp.end() || iterator2 == dp.end()) continue;

            int totWays = 0;
            //Option1 : make current number '+'
            int option1 = iterator1->second;

            //Option2 : make current number '-'
            int option2 = iterator2->second;

            totWays = option1 + option2;
            dp[{target_i, index_i}] = totWays; 
        }
    }

    return dp[{target, 0}];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int totWays = 0;

    //Plain RE
    // int index = 0;
    // totWays = solveUsingRE(nums, target, index);

    //Mem1 : dp of vector
    // int index = 0;
    // //Note that ATQ, "-1000 <= target <= 1000" & "0 <= sum(nums[i]) <= 1000"
    // vector<vector<int> > dp(4001, vector<int>(nums.size() + 1, -1)); //row x col :: target x index
    // totWays = solveUsingMem(nums, target, index, dp);

    //Mem2 : dp of std::map
    // int index = 0;
    // map<pair<int, int>, int> dp; //{target x index} ---> ways 
    // totWays = solveUsingMem2(nums, target, index, dp);

    //Tabulation : dp of std::map
    totWays = solveUsingTab(nums, target);

    return totWays;
}

int main(){
   
return 0;
}