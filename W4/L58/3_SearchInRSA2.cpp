#include<iostream>
#include<vector>
using namespace std;

/*
    1)Difference b/w this question and "L58 : 2) Search in Rotated Sorted Array" is that here, duplicate values are allowed in "nums[]"
    2)Because of duplicate values, BS can no longer be used to find the pivot index 
    
        Pivot Index = index of the 1st element that breaks the increasing order
        Ex: nums[] = [1,1,1,1,2,1,1] (Pivot Index Expected : 5)(Element at Pivot Index: 1)

        Note_1: My definition of Pivot Index is slightly different from Love Babbar's (Used in saved solution "1_2_Pivot_SearchInRSA1.cpp") but both are similar : Jahan increasing order me break hai vahan Pivot Index hai

    3)Agr Duplicate values na hoti to you can use BS to find the pivot index (Same BS code as in "0_FindMinInRSA.cpp" with slight modification, see Note_2 below). But now that code will not work. Try that code for this example:
        Ex: nums[] = [1,1,1,1,2,1,1] (Pivot Index Expected : 5) (BS would give: 0)

        Note_2: Code in "0_FindMinInRSA.cpp" gives element, so modify it to return index i.e instead of "return nums[mid]", do "return mid"
*/

//TC : O(n) {Because of findPivotIndex()}
int findPivotIndex(vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] < nums[i-1]) return i;
    }

    //Nothing found uptil here? This means nums is not rotated at all, so return index 0 (Why? To tell that nums is not rotated. See __Line(1) below)
    return 0;
}

bool bs(int s, int e, int target, vector<int>& nums){
    int mid = s + (e-s)/2;
    while(s <= e){
        int curr = nums[mid];
        if(curr == target) return true;
        else if(curr < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return false;
}

bool search(vector<int>& nums, int target) {
    int n = nums.size();

    int pivotIndex = findPivotIndex(nums); 
    // cout<<pivotIndex<<endl;

    //If nums is not rotated then pivotIndex will be 0. So do simple Binary Search [__Line(1)]
    if(pivotIndex == 0){
        return bs(0, n-1, target, nums);            
    }

    int s = -1;
    int e = -1;
    if(target > nums[0]){
        s = 0;
        e = pivotIndex - 1;
    }
    else if(target < nums[0]){
        s = pivotIndex;
        e = n-1;
    }
    else{
        //Means target is equal to nums[0]
        return true;
    }

    return bs(s, e, target, nums);
}

int main(){
   
return 0;
}