#include<iostream>
#include<vector>
using namespace std;

/******************Check if Array Is Sorted and Rotated[LeetCode : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/]***********************************************/
bool check(vector<int>& nums) {
    int flag = 0;
    int L = nums.size();

    for(int i = 0; i < L; i++){
        if(i == L-1 && nums[i] <= nums[0]){
            //Nthing
        }
        else if(i == L-1 && nums[i] > nums[0]){
            flag++;
        }
        else if(nums[i] <= nums[i+1]){
            //Nthing
        }
        else{
            flag++;
        }
    }

    if(flag == 1 || flag == 0){
        return true;
    }
    else{
        return false;
    }
}


int main(){
//    vector<int> arr{3,4,5,1,2};
//    vector<int> arr{4,1};
   vector<int> arr{4,5,1,2,3};
   bool ans = check(arr);
   cout<<ans<<endl;
return 0;
}