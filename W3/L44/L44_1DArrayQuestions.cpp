#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/************Q1 : Unique element in array Question********************/
int findUnique(vector<int> arr){
    int ans = 0; //Initializing with 0 as XORing with O has no effect

    for(int i = 0; i < arr.size(); i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
// /************Q1 : Unique element in array Question********************/
// cout<<"Enter size of array : ";
// int n;
// cin>>n;

// vector<int> arr(n);
// cout<<"Enter Elements : "<<endl;
// for(int i = 0; i < arr.size(); i++){
//     cin>>arr[i];
// }

// int uniqueElement = findUnique(arr);
// cout<<"Unique Element is : "<<uniqueElement<<endl;

/***********Q2 : Union of two arrays*****************/
// vector<int> arr{1,2,3,4,5,5};
// vector<int> brr{5,6,7,8,9};

// vector<int> ans;

// //Intersection : First add elements common to both arr and brr to ans
// for(int i = 0; i < arr.size(); i++){
//     for(int j = 0; j < brr.size(); j++){
//         if(arr[i] == brr[j]){
//             //push the matched element in ans
//             ans.push_back(arr[i]);

//             //Avoid duplicates : Mark the elements as added to ans
//             arr[i] = INT_MIN;
//             brr[j] = INT_MIN;

//         }
//     }
// }

// //Now add the remaining elements of arr to ans
// for(int i = 0; i < arr.size(); i++){
//     if(arr[i] != INT_MIN){
//         ans.push_back(arr[i]);
//     }
// }

// //Now add the remaining elements of brr to ans
// for(int i = 0; i < brr.size(); i++){
//     if(brr[i] != INT_MIN){
//         ans.push_back(brr[i]);
//     }
// }

// //Printing ans
// for(int i = 0; i < ans.size(); i++){
//     cout<<ans[i]<<" ";
// }


/***********Q2 : Intersection of two arrays*****************/
// vector<int> arr{1,3,5};
// vector<int> brr{2,3,3,4};

// vector<int> ans;

// // Outer Loop on arr
// for(int i = 0; i < arr.size(); i++){
//     //Inner Nested Loop on brr
//     for(int j = 0; j < brr.size(); j++){
//         if(arr[i] == brr[j]){
//             //push the matched element in ans
//             ans.push_back(arr[i]);

//             //Avoid duplicates : Mark the matched elements as added to ans
//             arr[i] = INT_MIN;
//             brr[j] = INT_MIN;

//         }
//     }
// }

// //Printing ans
// for(auto value : ans){
//     cout<<value<<" ";
// }

/***********Q3 : Pair Sum*****************/
// vector<int> arr{10,20,40,60,70};
// int sum = 80;

// //Outer Loop : traverse each element
// for(int i = 0; i < arr.size(); i++){
//     int element = arr[i];

//     //Inner Loop : For all "Aage wale elements"
//     for(int j = i+1; j < arr.size(); j++){
//         if(element + arr[j] == sum){
//             cout<<"Pair Found :"<<element<<","<<arr[j]<<endl;
//         }
//     }
// }

/***********Q3 : Triplet Sum*****************/
// vector<int> arr{10,20,40,50,60,70};
// int sum = 80;

// //Outer Loop : traverse each element 
// for(int i = 0; i < arr.size(); i++){
//     int element1 = arr[i];

//     //Inner Loop
//     for(int j = i+1; j < arr.size(); j++){
//         int element2 = arr[j]; 

//         //Inner-Inner Loop
//         for(int k = j+1; j < arr.size(); k++){
//             if(element1 +element2 + arr[k] == sum){
//                 cout<<"Triplet Found :"<<element1<<","<<element2<<","<<arr[k]<<endl;
//             }
//         }
//     }
// }


/************Q4 : Sort 0's and 1's*************************/
// // vector<int> arr{0,1,0,1,1,0,1,0,1,1};
// vector<int> arr{0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,1,1,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,1,1,1,0,0,1,0,1,1,1,0,1,1,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0};
// // vector<int> arr{1,0,0};


// //Method 1 : Two Pointer Approach 
// int start = 0;
// int end = arr.size() - 1;
// int i = 0;
// while(start <= end){
//     if(arr[start] == 0){
//         start++;
//     }

//     else if(arr[start] == 1){
//         swap(arr[start], arr[end]);
//         end--;
//     }
// }

// // Method 2 : Three pointer Approach
// /*
//     1) Method 2 is exactly same as Method 1 because "medium" and "low" are always having the same value. So both "medium" and "low" can be replaced
//         by a single variable "start" as in Method 1.
//     2) So 3 pointer approach is just 2 pointer approach when the array to be sorted has just 2 values (0 & 1 here).
//     3) But, the real use of 3 pointer approach is when the array to be sorted has 3 values (say 0, 1 & 2). This is the case in HW Q46 (Sort an array with 0, 1 & 2)
// */
// int low = 0;
// int high = arr.size() - 1;
// int medium = 0;
// while(medium <= high){

//     if(arr[medium] == 0){
//         //swap from left
//         swap(arr[low], arr[medium]);
//         medium++;
//         low++;
//     }

//     else if(arr[medium] == 1){
//         //swap from right
//         swap(arr[medium], arr[high]);
//         high--;
//     }

// }


// //Printing the sorted array
// for(auto value : arr){
//     cout<<value<<" ";
// }





return 0;
}