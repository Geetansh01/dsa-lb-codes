#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<limits.h>
using namespace std;

/************************************Q 59 : K-Diff Pairs In An Array[LeetCode : https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/]****************************************************************/
//Method 1 : Two Pointer Approach (TC: O(nlog n))
// int findPairs(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end());
//     set<pair<int, int>> ans;

//     int i = 0;
//     int j = 1;
//     while(j < nums.size()){
//         if(nums[j] - nums[i] == k){
//             ans.insert({nums[i], nums[j]});
//             i++;
//             j++;
//         }
//         else if(nums[j] - nums[i] > k){
//             i++;
//         }
//         else{
//             //case when (nums[j] - nums[i] > k)
//             j++;
//         }

//         //if i and j arrive on same then send j to the next location
//         if(i == j){
//             j++;
//         }
//     }
//     return ans.size();
// }

//Method 2 : using Binary Search (TC: O(nlog n))
int binarySearch(vector<int>& nums, int target, int start){
    int end = nums.size()-1;
    int mid = start + (end-start)/2;

    while(start <= end){
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            end = mid -1;
        }
        else{
            start = mid +1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int index = 0;

    for(int i = 0; i < nums.size(); i++){
        if(binarySearch(nums, nums[i] + k, i+1) != (-1)){
            ans.insert({nums[i], nums[i]+k});
        }
    }
return ans.size();
}


int main(){
   vector<int> nums = {3,1,4,1,5};
   cout<<findPairs(nums,2)<<endl;
return 0;
}