/***********L116 : Max Sub Array Sum [LeetCode : https://leetcode.com/problems/maximum-subarray/description/]**********************/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//M1 : DnC (TC : O(n logn), SC : O(logn))
int Helper(vector<int>& nums, int s, int e){
    //Base Case
    if(s == e){
        return nums[s];
    }

    int mid = s + (e-s)/2;
    int maxLeftSum = Helper(nums, s, mid);
    int maxRightSum = Helper(nums, mid + 1, e);

    //Now finding maximum Sum for cross border array
    //To the left of border
    int maxLeftBorderSum = INT_MIN;
    int temp = 0;
    for(int i = mid; i >= s; i--){
        temp += nums[i];
        if(temp > maxLeftBorderSum){
            maxLeftBorderSum = temp;
        }
    }

    //To the right of border
    int maxRightBorderSum = INT_MIN;
    int temp2 = 0;
    for(int i = mid+1; i <= e; i++){
        temp2 += nums[i];
        if(temp2 > maxRightBorderSum){
            maxRightBorderSum = temp2;
        }
    }

    int maxCrossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    //Finally return the max of the 3 Sums
    return max(maxCrossBorderSum, max(maxLeftSum, maxRightSum));
}

int maxSubArray(vector<int>& nums) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = Helper(nums, s, e);
    return ans;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(nums);
    cout<<"Answer : "<<ans<<endl;
   
return 0;
}


// //M2 : Kadane's Algo (TC : O(n), SC : O(1))
// int maxSubArray(vector<int>& nums) {
//     int current_sum = 0;
//     int best_sum = nums[0];
//     for(int i = 0; i < nums.size(); i++){
//         current_sum += nums[i];
//         best_sum = max(current_sum, best_sum);
//         if(current_sum < 0){
//             current_sum = 0;
//         } 
//     }
//     return best_sum;
// }

// int main(){
//     // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//     vector<int> nums = {-5, -5, 100, 200, -10, -10, -10, 100};
//     int ans = maxSubArray(nums);
//     cout<<"Answer : "<<ans<<endl;
   
// return 0;
// }
