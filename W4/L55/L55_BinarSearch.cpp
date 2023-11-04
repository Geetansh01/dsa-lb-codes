#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/************************************Binary Search***************************************************************/
// int binarySearch(int arr[], int size, int target){
//     int start = 0;
//     int end = size - 1;
//     // int mid = (start + end) / 2;
//     int mid = start + (end - start) / 2;

//     while(start <= end){
//         int element = arr[mid];

//         if(element == target){
//             return mid;
//         }

//         //Search in left of mid
//         else if(target < element){
//             end = mid - 1;
//         }

//         //Search in right of mid
//         else{
//             start = mid + 1;
//         }

//         mid = start + (end - start) / 2;
//     }
//     return -1;
// }

// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int target = 12;
    
//     //using function written by me
//     cout<<binarySearch(arr, size, target)<<endl;
   
//     //usinig STL Built In function
//     cout<<binary_search(arr, arr+(size), target)<<endl;
//     vector<int> vec{1,2,3,4,5,6,7,8,9};
//     cout<<binary_search(vec.begin(), vec.end(), 12)<<endl;
// return 0;
// }


/****************************First Occurence of an Element (Using Binary Search)************************************************/
// int firstOccurrence(vector<int> arr, int target){
//     int start = 0;
//     int end = arr.size() - 1;

//     int mid = start + (end - start)/2;
//     int ans = -1;

//     while( start <= end){
//         if(arr[mid] == target){
//             //store ans
//             ans = mid;
//             //search in left
//             end = mid - 1;
//         }

//         else if(target > arr[mid]){
//             //search in right
//             start = mid + 1;
//         }

//         else if(target < arr[mid]){
//             //search in left
//             end = mid - 1;
//         }

//         mid = start + (end - start)/2;
//     }
//     return ans;
// }

// int main(){
//     vector<int> v{1,2,2,4,4,4,4,4,4,5,6,6};
//     int target = 4;

//     //using function written by me
//     cout<<"Index Of First Occurrence of target is :"<<firstOccurrence(v, target)<<endl;

//     //usinig STL Built In function (iterators are being used here, we will study them later)
//     auto ans = lower_bound(v.begin(), v.end(), target);  
//     cout<<"Index Of first Occurrence of target is :"<<ans - v.begin()<<endl;  
// }

/****************************Last Occurence of an Element (Using Binary Search)************************************************/
// int lastOccurrence(vector<int> arr, int target){
//     int start = 0;
//     int end = arr.size() - 1;

//     int mid = start + (end - start)/2;
//     int ans = -1;

//     while( start <= end){
//         if(arr[mid] == target){
//             //store ans
//             ans = mid;
//             //search in left
//             start = mid + 1;
//         }

//         else if(target > arr[mid]){
//             //search in right
//             start = mid + 1;
//         }

//         else if(target < arr[mid]){
//             //search in left
//             end = mid - 1;
//         }

//         mid = start + (end - start)/2;
//     }
//     return ans;
// }

// int main(){
//     // vector<int> v{1,2,2,4,4,4,4,4,4,5,6,6};
//     vector<int> v{4,4,4};
//     int target = 4;

//     //using function written by me
//     cout<<"Index Of Last Occurrence of target is :"<<lastOccurrence(v, target)<<endl;

//     //usinig STL Built In function (iterators are being used here, we will study them later)
//     auto ans = upper_bound(v.begin(), v.end(), target); //It will give one more than the expected answer 
//     cout<<"Index Of Last Occurrence of target is :"<<ans - v.begin()<<endl; //It will give one more than the expected answer 
// }

/**************************************Peak Index in a Mountain Array [LeetCode : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/]*********************************************/
int peakIndexInMountainArray(vector<int>& vec) {
    int s = 0;
    int e = vec.size() - 1;
    int m = s + (e-s)/2;

    while(s < e){
        if(vec[m] < vec[m + 1]){
            s = m + 1;
        }
        else{
            e = m ;
        }

        m = s + (e-s)/2;
    }
    return m;
}

int main(){
    vector<int> vec{0,1,3,10,2,0};
    // vector<int> vec{-1};
    cout<<"Value of peak index in this mountain array is : "<<peakIndexInMountainArray(vec);
}
