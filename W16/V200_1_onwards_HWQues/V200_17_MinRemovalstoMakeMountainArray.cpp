#include<bits/stdc++.h>
using namespace std;

/*****V200_17 : Minimum Number of Removals to Make Mountain Array [LeetCode : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/]******/


//This Function will fill the "LISq[]" Array. It is modified version of "L198 : 1)Longest Increasing Subsequence : BS method Code"
void solveUsingBSLISq(vector<int>& nums, vector<int>& LISq){
    if(nums.size() == 0) return;

    LISq.push_back(1);
    vector<int> ans; //isme answer build krunga i.e LISq

    //Initial state of answer : 0th index wala number to insert kr do, fir age ki algo chla denge
    ans.push_back(nums[0]);

    for(int i = 1; i < nums.size(); i++){
        //If current no is sabse bda no then dal do "ans" me
        if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
            LISq.push_back(ans.size());
        }
        else{
            //If current no se just bda number exist krta hai "ans" me to replace that with current no
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); //"index" will store index of this "current no se just bda number"
            ans[index] = nums[i];
            LISq.push_back(index + 1);
        }
    }
    return;
}

int minimumMountainRemovals(vector<int>& nums) {

    //Using Binary Search Method of LISq [ TC : O(n log n) for the complete solution to find "minRemovals"]
    vector<int> LISq; 
    vector<int> LDSq; //Longest Decreasing Subsequence 

    solveUsingBSLISq(nums, LISq);

    reverse(nums.begin(), nums.end()); //reverse nums[]
    solveUsingBSLISq(nums, LDSq); //Bcz we reversed "nums[]" so this function will now work to fill the LDSq array, 
                                    //But bcz "nums[]" reverse krke pass ki hai to LDSq me aswers bhi reverse order me honge, Like LDSq ke 0th index pe original-nums[] (i.e non reversed) ke last element ki LDSq hogi, so read LDSq in reverse

    //Printing LISq and LDSq array (Print LDSq in reverse)
    // for(auto x : LISq){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(int i = LDSq.size() - 1; i >= 0; i--){
    //     cout<<LDSq[i]<< " ";
    // }

    //Main Logic
    int largestMountain = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(LISq[i] == 1 || LDSq[nums.size() - i - 1] == 1) continue;
        largestMountain = max(largestMountain, LISq[i] + LDSq[nums.size() - i - 1] - 1);
    }

    int minRemovals = nums.size() - largestMountain;
    return minRemovals;
}

int main(){
   
return 0;
}