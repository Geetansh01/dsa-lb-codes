#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/*************************** Coin Change [LeetCode : https://leetcode.com/problems/coin-change/]**************************************/
//LeetCode will give TLE as this soln needs to be optimized (DP)

int solve(vector<int>& arr, int target){
    //Base Case
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }

    //1 case Solve Kro
    int mini = INT_MAX;
    for(int i = 0; i < arr.size(); i++){
        int ans = solve(arr, target - arr[i]);
        if(ans != INT_MAX){
            mini = min(mini, ans+1);
        }
    }

    return mini;
}

int main(){
    vector<int> arr{1,2,3};
    int target = 7;
    int mini = INT_MAX;
    int ans = solve(arr, target);
    cout<<"Answer:"<<ans<<endl;

return 0;
}