#include<iostream>
#include<vector>
using namespace std;

/****************************Find Pivot Element in Rotated Array**************************************************/
// int findPivotIndex(vector<int> arr){
//     int s = 0;
//     int e = arr.size() - 1;
//     int mid = s + (e-s)/2;

//     while(s <= e){
//         if(s == e){
//             //single element
//             return mid; //OR "return s" OR "return e"
//         }
//         if(mid+1 <= e && arr[mid] > arr[mid+1]){
//             return mid;
//         }
//         if(mid-1 >= s && arr[mid-1] > arr[mid]){
//             return mid-1;
//         }
//         else if(arr[s] > arr[mid]){
//             //left me search kro
//             e = mid - 1;
//         }
//         else{
//             //right me search kro
//             s = mid + 1;
//         }
//         mid = s + (e-s)/2;
//     }
//     return -1;
// }

// int main(){
// //    vector<int> arr{2,4,6,8,9,10};
//    vector<int> arr{4,5,6,7,0,1,2}; 
//    int ans = findPivotIndex(arr);

//    if(ans == -1){
//     cout<<"Prblm"<<endl;
//    }
//    else{
//     cout<<"Index of pivot : "<<ans<<endl;
//     cout<<"value of pivot : "<<arr[ans]<<endl;

//    }
// return 0;
// }


/****************************Search in Rotated Sorted Array [LeetCode : https://leetcode.com/problems/search-in-rotated-sorted-array/description/]************************************/
//Prerequisite : "Find Pivot Element in Rotated Array" question
int findPivotIndex(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s <= e){
        if(s == e){
            //single element
            return mid; //OR "return s" OR "return e"
        }
        if(mid+1 <= e && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid-1 >= s && arr[mid-1] > arr[mid]){
            return mid-1;
        }
        else if(arr[s] > arr[mid]){
            //left me search kro
            e = mid - 1;
        }
        else{
            //right me search kro
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int binarySearch(vector<int> arr, int s, int e, int target){
    int mid = s + (e-s)/2;

    while(s <= e){
        if(arr[mid] == target){
            return mid;
        }

        else if(arr[mid] > target){
            e = mid - 1;
        }

        else{
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivotIndex = findPivotIndex(nums);
    int ans = 0;

    if(target >= nums[0] && target <= nums[pivotIndex]){
        ans = binarySearch(nums, 0, pivotIndex, target);
    }
    else{
        ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
    }

    return ans;
}

int main(){
    vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;

    int ans = search(nums, target);
    cout<<"Index of target : "<<ans<<endl;
}
