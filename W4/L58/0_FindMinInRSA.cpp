#include<bits/stdc++.h>
using namespace std;

//For full solution explanation: https://youtu.be/Jin6vO0MdzY?feature=shared

//TC: O(log n)
int binarySeacrch(vector<int>& nums){
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while(s < e){
        if(nums[mid] > nums[e]){
            //Bcz nums[mid] greater than nums[e] to nums[mid] is definitely not the smallest element
            //So, search to the right
            s = mid + 1;
        }
        else{
            //Bcz nums[mid] is less than or equal to nums[e] so nums[mid] might be the smallest element, so we can NOT do "e = mid - 1"
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return nums[mid];
}

int findMin(vector<int>& nums) {
    int ans = binarySeacrch(nums);
    return ans;
}


int main(){
   
return 0;
}