#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

/*********/

int binSrch(vector<int>& days, int target){
    int start = 0;
    int end = days.size() - 1;
    int mid = start + ((end - start) / 2);
    int ans = INT_MAX;

    while(start <= end){
        if(days[mid] >= target){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid + 1;
        }

        mid = start + ((end - start) / 2);
    }

    return ans;
}

int getExpirationDayIndex(vector<int>& days, int currDayIndex, int currPassDays){
    int PassExpiresOnDay = days[currDayIndex] + currPassDays;
    int ans = binSrch(days, PassExpiresOnDay);
    return ans;
}

int solveUsingRE(vector<int>& days, vector<int>& costs, int currDayIndex){
    //BC
    if(currDayIndex >= days.size()) return 0;

    int ans = INT_MAX;
    //Try all passes
    for(int i = 0; i < costs.size(); i++){
        int currPassCost = costs[i];
        int currPassDays = (i == 0 ? 1 : (i == 1 ? 7 : 30));
        int nxtExpiration = getExpirationDayIndex(days, currDayIndex, currPassDays); //index Of Next Day When current Pass Expires
        int temp = currPassCost + solveUsingRE(days, costs, nxtExpiration);
        ans = min(temp, ans);
    }
    return ans;
}    

int solveUsingMem(vector<int>& days, vector<int>& costs, int currDayIndex, vector<int>& dp){
    //BC
    if(currDayIndex >= days.size()) return 0;

    if(dp[currDayIndex] != -1){
        return dp[currDayIndex];
    }

    int ans = INT_MAX;
    //Try all passes
    for(int i = 0; i < costs.size(); i++){
        int currPassCost = costs[i];
        int currPassDays = (i == 0 ? 1 : (i == 1 ? 7 : 30));
        int nxtExpiration = getExpirationDayIndex(days, currDayIndex, currPassDays); //index Of Next Day When current Pass Expires
        int temp = currPassCost + solveUsingMem(days, costs, nxtExpiration, dp);
        ans = min(temp, ans);
    }
    dp[currDayIndex] = ans;

    return dp[currDayIndex];
}    

int solveUsingTab(vector<int>& days, vector<int>& costs, int currDayIndex){
    vector<int> dp(days.size() + 1, 0);

    //Fill initial data : done by initializing dp with 0

    for(int i_index = days.size() - 1; i_index >= 0; i_index--){
        int ans = INT_MAX;
        //Try all passes
        //Below loop runs 3 times (Given in Question) 
        for(int i = 0; i < costs.size(); i++){
            int currPassCost = costs[i];
            int currPassDays = (i == 0 ? 1 : (i == 1 ? 7 : 30));
            //TC for "getExpirationDayIndex()" : O(log N) {It uses Binary Search}
            int nxtExpiration = getExpirationDayIndex(days, i_index, currPassDays); //index Of Next Day When current Pass Expires
            int temp = 0;
            if(nxtExpiration == INT_MAX){
                temp = currPassCost + 0;
            }
            else{
                temp = currPassCost + dp[nxtExpiration];
            }
            ans = min(temp, ans);
        }
        dp[i_index] = ans;
    }

    return dp[currDayIndex];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int ans = 0;

    //Plain RE
    //N = days.size(); 
    // (TC : O(3^N) i.e Exponential (Compare with Fibonnaci); SC : O(N) i.e Linear)
    // int currDayIndex = 0; //index of days[] 
    // ans = solveUsingRE(days, costs, currDayIndex);

    //Mem
    // int currDayIndex = 0; //index of days[] 
    // vector<int> dp(days.size() + 1, -1);
    // ans = solveUsingMem(days, costs, currDayIndex, dp);

    //Tabulation
    //N = days.size();
    //TC : O(N log N)
    //SC : O(N)
    int currDayIndex = 0; //index of days[] 
    ans = solveUsingTab(days, costs, currDayIndex);

    return ans;
}

int main(){
   
return 0;
}