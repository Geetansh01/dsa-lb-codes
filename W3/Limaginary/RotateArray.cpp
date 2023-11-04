#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/********************Right Rotate Array [LeetCode : https://leetcode.com/problems/rotate-array/description/]*************************************************/
// //Method 1 : Modulus "%" operator (TC: O(N), SC: o(N))
// // void rotate(vector<int>& nums, int k) {
// //     vector<int> temp(nums.size(), 0);

// //     for(int i = 0; i < nums.size(); i++){
// //         temp[(i + k)%nums.size()] = nums[i];
// //     }

// //     nums = temp;
// // }

// //Method 2 : Reversing (TC: O(N), SC: O(1))
// void rotate(vector<int>& nums, int k) {
//     k = k%nums.size();
//     reverse(nums.end()-k, nums.end());
//     reverse(nums.begin(), nums.end()-k);
//     reverse(nums.begin(), nums.end());
// }

// int main(){
//     vector<int> nums = {1,2,3,4,5,6,7}; 
//     int k = 3;

//     rotate(nums, k); //5 6 7 1 2 3 4 
    
//     for(auto iter : nums){
//         cout<<iter<<" ";
//     }
   
// return 0;
// }


/********************Left Rotate Array [CodingNinjas : https://www.codingninjas.com/codestudio/problems/rotate-array_1230543?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf]*************************************************/
// //Method : 1(Reversing)
// void rotateArray(vector<int>& arr, int k) {
//     k = k%arr.size();
//     reverse(arr.begin(), arr.begin() + k);
//     reverse(arr.begin() + k, arr.end());
//     reverse(arr.begin(), arr.end());
// }

// //Method 2(TC: O(N), SC: O(N))
// // void rotateArray(vector<int>& arr, int k){
// //     int n = arr.size();
// //     k = k%n;
// //     vector<int> temp(n, 0);
    
// //     for (int i = 0; i < n; i++){
// //       int newIndex = i - k;
// //       if (newIndex < 0) {
// //         newIndex = n + newIndex;
// //       }
// //       temp[newIndex] = arr[i];
// //     }
// //     arr = temp;
// // }

// int main(){
//     vector<int> nums = {1,2,3,4,5,6,7}; 
//     int k = 3;

//     rotateArray(nums, k); //4 5 6 7 1 2 3 
    
//     for(auto iter : nums){
//         cout<<iter<<" ";
//     }
   
// return 0;
// }