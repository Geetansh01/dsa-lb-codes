#include<bits/stdc++.h>
using namespace std;

/***V200_13 : Burst Balloons [Interview] [DP/ RE Pattern : P/MI] [https://leetcode.com/problems/burst-balloons/description/]*****/

//Solution done from : " https://thewayofnada.medium.com/how-to-solve-the-burst-balloons-problem-like-a-piece-of-cake-6121f365b1f " 
//Main Intuition : A very important fact is that if a balloon in the middle is not bursted until the end, the balloons array to its left and the array to its right are independent. The left part and the right part are independent if they are always separated by a balloon.

int solveUsingRE(vector<int>& arr, int start, int end){
    //BC
    if(start > end) return 0;

    //Balloons burst krne ke correct way me (i.e when bursting balloons gives max coins) koi to balloon hoga jo last me foda jaega, this balloon is the appropriate separator!
    //1-1 krke hr balloon ko separator mano and coins nikalo, jab tum shi balloon ko separator loge to max coins mil jaenge & this will be our answer!
    int maxCoins = INT_MIN;
    for(int i = start; i <= end; i++){
        int burstLeftBalloons = solveUsingRE(arr, start, i - 1);
        int burstRightBalloons = solveUsingRE(arr, i + 1, end);
        int coins =( arr[start - 1] * arr[i] * arr[end+1]) + burstLeftBalloons + burstRightBalloons;
        maxCoins = max(coins, maxCoins);
    }
    return maxCoins;
}

int solveUsingMem(vector<int>& arr, int start, int end, vector<vector<int> >& dp){
    //BC
    if(start > end) return 0;

    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int maxCoins = INT_MIN;
    for(int i = start; i <= end; i++){
        int burstLeftBalloons = solveUsingMem(arr, start, i - 1, dp);
        int burstRightBalloons = solveUsingMem(arr, i + 1, end, dp);
        int coins =( arr[start - 1] * arr[i] * arr[end+1]) + burstLeftBalloons + burstRightBalloons;
        maxCoins = max(coins, maxCoins);
    }
    dp[start][end] = maxCoins;

    return maxCoins;
}

int solveUsingTab(vector<int>& modifiedNums){
    vector<vector<int> > dp(modifiedNums.size(), vector<int>(modifiedNums.size(), 0));

    //Fill initial data : Already done by initialising dp with 0;

    for(int start_indx = modifiedNums.size() - 2; start_indx >= 1; start_indx--){
        for(int end_indx = 0; end_indx <= modifiedNums.size() - 2; end_indx++){

            if(start_indx > end_indx) continue;

            int maxCoins = INT_MIN;
            for(int i = start_indx; i <= end_indx; i++){
                int burstLeftBalloons = dp[start_indx][i - 1];
                int burstRightBalloons = dp[i + 1][end_indx];
                int coins = ( modifiedNums[start_indx - 1] * modifiedNums[i] * modifiedNums[end_indx + 1]) + burstLeftBalloons + burstRightBalloons;
                maxCoins = max(coins, maxCoins);
            }
            dp[start_indx][end_indx] = maxCoins;

        }
    }

    return dp[1][modifiedNums.size() - 2];
}

int maxCoins(vector<int>& nums) {
    int maxCoins = 0;

    //given "nums[]" ke starting and ending me 1 lga do 
    //Why? bcz ATQ, agr kisi balloon ke left/ right me koi or balloon nhi hai to use fodte time uske left/ right me'1' wala balloon manlo
    //Try Dry Running the plain RE solution with any LeetCode TestCase to understand how these padded 1's simulate this behavior
    vector<int> modifiedNums = {1};
    modifiedNums.insert(modifiedNums.end(), nums.begin(), nums.end());
    modifiedNums.push_back(1);

    //Plain RE
    // int start = 1; //Bcz we have added the extra 1's in starting and ending so "start" and "end" should ignore them and contain the actual array jiska answer chaiye
    // int end = modifiedNums.size() - 2;
    // maxCoins = solveUsingRE(modifiedNums, start, end);

    //Mem
    // int start = 1;
    // int end = modifiedNums.size() - 2;
    // vector<vector<int> > dp(modifiedNums.size() + 1, vector<int>(modifiedNums.size() + 1, -1)); //row x col :: start x end
    // maxCoins = solveUsingMem(modifiedNums, start, end, dp);

    //Tabulation
    maxCoins = solveUsingTab(modifiedNums);

    //Tabulation SO
    //Given as HomeWork, DIY

    return maxCoins;
}

int main(){
   
return 0;
}