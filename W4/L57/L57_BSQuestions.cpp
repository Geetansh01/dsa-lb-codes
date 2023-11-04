#include<iostream>
#include<vector>
using namespace std;

/*************************BS in Nearly Sorted Array (NSA)****************************************/
// int binarySearch(vector<int> arr, int target){
//     int s = 0;
//     int e = arr.size() - 1;
//     int mid = s + (e-s)/2;

//     while(s <= e){
//         if(arr[mid] == target){
//             return mid;
//         }
//         if(mid-1 >= s && arr[mid-1] == target){
//             return mid-1;
//         }
//         if(mid+1 <= e && arr[mid+1] == target){
//             return mid+1;
//         }

//         else if(arr[mid] < target){
//             //right search
//             s = mid + 2;
//         }

//         else{
//             //left search
//             e = mid - 2;
//         }

//         mid = s + (e-s)/2;
//     }
//     return -1;
// }

// int main(){
//    vector<int> arr{10,3,40,20,50,80,70}; //This is a nearly sorted array.
//    int target = 70;

//    cout<<"Target found at index : "<<binarySearch(arr, target);
// return 0;
// }


/**************************Division of Two Numbers Using BS**************************************************/
// int solve(int dividend, int divisor){
//     //In case the quotient has decimal part, this function will return only the integer part
//     int s = 0;
//     int e = abs(dividend);
//     int mid = s + (e-s)/2;
//     int ans = 0;

//     while(s <= e){
//         //perfect soln
//         if(abs(mid*divisor) == abs(dividend) ){
//             ans = mid;
//             break;
//         }
//         //Not perfect soln
//         if(abs(mid*divisor) > abs(dividend) ){
//             //left search
//             e = mid - 1;
//         }
//         else{
//             //ans store
//             ans = mid;
//             //right search 
//             s = mid + 1;
//         }

//         mid = s + (e-s)/2;
//     }

//     if(divisor < 0 && dividend < 0 || (divisor > 0 && dividend > 0)){
//         return ans;
//     }
//     else{
//         return -ans;
//     }
// }


// int main(){
//     int dividend = -22;
//     int divisor = 7;

//     int ans = solve(dividend, divisor);
//     cout<<"Integer Part of quotient : "<<ans<<endl;

// }


/***********************Find the odd appearing element in O(Log n) time [https://www.geeksforgeeks.org/find-the-element-that-odd-number-of-times-in-olog-n-time/]*********/
/*
Question :
Given an array where all elements appear even number of times except one. All repeating occurrences of elements appear in pairs and these pairs are not adjacent (there cannot be more than two consecutive occurrences of any element). Find the element that appears odd number of times. 
Note that input like {2, 2, 1, 2, 2, 1, 1} is valid as all repeating occurrences occur in pairs and these pairs are not adjacent. 
Input like {2, 1, 2} is invalid as repeating elements don’t appear in pairs. 
Also, input like {1, 2, 2, 2, 2} is invalid as two pairs of 2 are adjacent. 
Input like {2, 2, 2, 1} is also invalid as there are three consecutive occurrences of 2.
*/
int solve(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s < e){

        //mid is even
        if(mid % 2 == 0){
            if(arr[mid] == arr[mid + 1]){
                //right search kro
                s = mid + 2;
            }
            else{
                e = mid;
            }
        }

        //mid is odd
        else{
            if(arr[mid] == arr[mid - 1]){
                //right me search kro
                s = mid + 1;
            }
            else{
                //left me search kro
                e = mid - 1;
            }
        }

        //update mid
        mid = s + (e-s)/2;
    }
    return mid;
}

int main(){
    // vector<int> arr{1,1,2,2,3,3,4,4,3,600,600,4,4};
    // vector<int> arr{1,1,2,2,3,3,4,4,5,5,6,6,7,7,1,1,2,2,3,3,-100};
    // vector<int> arr{1,1,2,2,1};
    // vector<int> arr{12};
    vector<int> arr{1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40, 13, 13};
    int indexOfAnswer = solve(arr);
    cout<<"Index of answer : "<<indexOfAnswer<<endl;
    cout<<"Answer : "<<arr[indexOfAnswer]<<endl;
}