#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<set>
using namespace std;


/**************Q60 : Find K Closest Elements [LeetCode : https://leetcode.com/problems/find-k-closest-elements/]*********************************/
//Method 1 : Two Pointer Approach (TC: O(N), SC: O(k))
// vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//     int low = 0;
//     int high = arr.size() - 1;
//     vector<int> ans;

//     while(high - low >= k){
//         if(x-arr[low] > arr[high] - x){
//             low++;
//         }
//         else{
//             high--;
//         }
//     }

//     for(int i = low; i <= high; i++){
//         ans.push_back(arr[i]);
//     }  

//     return ans;
//     //Alter method to return the answer, SC remains same
//     // return vector<int> (arr.begin() + low, arr.begin() + high + 1);
// }

//Method 2 : Using Binary Search and two pointers (TC: O(N), SC:O(K))
int closestElement(vector<int>& arr, int target){
   //This is modified Binary Search
   int s = 0;
   int e = arr.size()-1;
   int mid = s + (e-s)/2;
   int ans = e;

   while(s <= e){
      if(arr[mid] >= target){
            ans = mid;
            e = mid - 1;
      }
      else if(target > arr[mid]){
            s = mid + 1;
      }
      else{
            e = mid - 1;
      }
      mid = s + (e-s)/2;
   }
   return ans;
}  

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
int high = closestElement(arr, x);
int low = high - 1;
vector<int> ans;

while(k--){
   if(low < 0){
         high++;
   }
   else if(high >= arr.size()){
         low--;
   }
   else if(x-arr[low] > arr[high]-x){
         high++;
   }
   else{
         low--;
   }
}
for(int i = low + 1; i < high; i++){
   ans.push_back(arr[i]);
}
return ans;
}

int main(){
   vector<int> arr = {1,2,3,4,5};
   int k = 4;
   int x = -1;

   vector<int> vec = findClosestElements(arr, k, x);

   for(auto iter : vec){
    cout<<iter<<" ";
   }

return 0;
}