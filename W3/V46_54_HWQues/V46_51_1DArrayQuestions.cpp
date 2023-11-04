#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
#include<set>
using namespace std;

/*************************Q 46 : Sort Colors [LeetCode : https://leetcode.com/problems/sort-colors/description/]**********************************************/
// void sortColors(vector<int>& nums) {
//     //3 Pointer Approach
//     int low = 0;
//     int medium = 0;
//     int high = nums.size() - 1;

//     while(medium <= high){
//         if(nums[medium] == 0){
//             swap(nums[low], nums[medium]);
//             low++;
//             medium++;
//         }
//         else if(nums[medium] == 1){
//             medium++;
//         }
//         else{
//             swap(nums[medium], nums[high]);
//             high--;
//         }
//     }
// }

// int main(){
//    vector<int> vec = {0,1,2,2,1,0,1};
//    sortColors(vec);

//    //Top print the sorted Array
//    for(int i = 0; i < vec.size(); i++){
//     cout<<vec[i]<<" ";
//    }

// return 0;
// }


/**************************************Q 48 : Find Duplicate Number [LeetCode : https://leetcode.com/problems/find-the-duplicate-number/description/]*************************************************/
// //Method 1
// //This Method has good Time Complexity {O(n)} but it is wrong as it is modifying the input array and the Question forbids it.
// int findDuplicate(vector<int>& nums) {
//     for(int i = 0; i < nums.size(); i++){
//         int index = abs(nums[i]);

//         //Checking if already marked visited
//         if(nums[index] < 0){
//             return index;
//         }

//         //mark visited
//         else{
//             nums[index] = -nums[index];     
//         }  
//     }
//     return -1;
// }

// //Method 2
// //This Method has good Time Complexity {O(n)} but it is wrong as it is modifying the input array and the Question forbids it.
// int findDuplicate(vector<int>& nums) {
//     int index = nums[0];
//     while(nums[0] != nums[index]){
//         swap(nums[0], nums[index]);
//         index = nums[0];
//     }
//     return nums[0];
// }

// //Method 3 : Using Binary Search (Will be studied later)

// int main(){
//     vector<int> vec{1,2,3,2};
//     cout<<findDuplicate(vec);
//     return 0;
// }


/**************************************Q 49 : Missing Elements From An Array With Duplicates*************************************************/
//Ques : Given an array of size N. The elements in the array are integers in the range [1,N] inclusive. The array has one or more duplicate elements which result in some 
//missing elements. Print these missing elements.

//Visited Method (see Q48 Method-1)
// void findMissingNum(vector<int>& vec){
//     for(int i = 0; i < vec.size(); i++){
//         //Assuming the elements are indexes
//         int index = abs(vec[i]) - 1;

//         //Mark Visited (by making it negative)
//         if(vec[index] > 0){
//             vec[index] *= -1; 
//         }
//     }

//     //Now, all the indexes of the vector which have not been visited are the missing elements
//     for(int i = 0; i < vec.size(); i++){
//         if(vec[i] > 0){
//             cout<<i + 1<<" ";
//         }
//     }
// }

//Swapping Method (See Q48 Method-2 for reference but this is slightly different)
// int findMissingNum(vector<int>& arr){
//     //Sending all elements to their corresponding index
//     int i = 0;
//     while(i < arr.size()){
//         int index = arr[i] - 1;
//         if(arr[i] != arr[index]){
//             swap(arr[i], arr[index]);
//         }
//         else{
//             i++;
//         }
//     }

//     //Now all elements not on their correct index will give the missing element
//     for(int i = 0; i < arr.size(); i++){
//         if(arr[i] != i + 1){
//             cout<<i + 1<<" ";
//         }
//     }
// }

// int main(){
//     vector<int> vec{1,3,5,3,4};
//     findMissingNum(vec);
//     return 0;
// }


/**************************************Q 50 : Find First Repeating Element [GFG : https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1]*************************************************/
/*
Ques : Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first 
occurrence should be the smallest.
Note:- The position you return should be according to 1-based indexing. 
*/

// //Method 1 : Using Hashing, STL(Vetors) (T.C : O(N) )
// int firstRepeated(int arr[], int n) {

//     //Finding Max element in arr
//     int max = INT_MIN;
//     for(int i = 0; i < n; i++){
//         if(arr[i] > max){
//             max = arr[i];
//         }
//     }

//     //Making a hash (here, a vector with size "max + 1" and initialised with 0)   
//     vector<int> hash(max+1, 0);

//     //Counting occurrence of all elements from " arr " into hash
//     for(int i = 0; i < n; i++){
//         hash[arr[i]] = hash[arr[i]] + 1;
//     }

//     //Again traversing " arr " to find elements with occurrence more than 1 (i.e repeated element)
//     for(int i = 0; i < n; i++){
//         //return index + 1 for the first repeating element found
//         if(hash[arr[i]] > 1){
//             return i + 1;
//         }
//     }
//     return -1;
// }


//Method 2 : Using Hashing, Dynamic Arrays (T.C : O(N) )
// int firstRepeated(int arr[], int n) {

//     //Finding Max element in arr
//     int max = INT_MIN;
//     for(int i = 0; i < n; i++){
//         if(arr[i] > max){
//             max = arr[i];
//         }
//     }

//     //Making a hash (here, a dynamic array with size "max + 1" and initialised with 0)   
//     int* hash = new int[max + 1]; //write now, the array hash has got garbage values

//     //making all values in hash 0
//     for(int i = 0; i < max + 1; i++){
//         hash[i] = 0;
//     }


//     //Counting occurrence of all elements from " arr " into hash
//     for(int i = 0; i < n; i++){
//         hash[arr[i]] = hash[arr[i]] + 1;
//     }

//     //Again traversing " arr " to find elements with occurrence more than 1 (i.e repeated element)
//     for(int i = 0; i < n; i++){
//         //return index + 1 for the first repeating element found
//         if(hash[arr[i]] > 1){
//             return i + 1;
//         }
//     }
//     return -1;
// }

//Method 3 : Using Hashing, unordered_map (T.C : O(N) )
//unordered_map will be studied in detail later
// int firstRepeated(int arr[], int n) {
//     unordered_map<int, int> hash;

//     //Counting occurrence of all elements from " arr " into hash
//     for(int i = 0; i < n; i++){
//         hash[arr[i]] = hash[arr[i]] + 1;
//     }

//     //Again traversing " arr " to find elements with occurrence more than 1 (i.e repeated element)
//     for(int i = 0; i < n; i++){
//         //return index + 1 for the first repeating element found
//         if(hash[arr[i]] > 1){
//             return i + 1;
//         }
//     }
//     return -1;
// }


//Method 3 : Worst (T.C : O(N^2) )
// int firstRepeated(int arr[], int n) {
//     for(int i = 0; i < n; i++){
//         int element = arr[i];
//         for(int j = i + 1; j < n; j++){
//             if(arr[j] == element){
//                 return i + 1;
//             }
//             else{
//                 //Nthing
//             }
//         }
//     }
//     return -1;
// }


// int main(){
//     int arr[] = {3,2,1,1,3};
//     // int arr[] = {1,2,3,4};
//     int size = sizeof(arr)/sizeof(int);
//     cout<<firstRepeated(arr, size);
// }



/**********************************************Q 51 : Common Elements In 3 Sorted Array[GFG : https://practice.geeksforgeeks.org/problems/common-elements1132/1]******************************************************************************************************/
/*
Ques : Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?
*/
//Method 3 : Only Correct solution out of the 3 Methods as we use no additional STL Data Structure as asked in the question
// vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
// {   
//     vector<int> ans; //Made an empty vector

//     //Marking Duplicates
//     for(int i = 1; i<n1; i++){
//         if(A[i] == A[i-1]){
//             A[i-1] =INT_MIN;
//         }
//     }
//     for(int i = 1; i<n2; i++){
//         if(B[i] == B[i-1]){
//             B[i-1] =INT_MIN;
//         }
//     }
//     for(int i = 1; i<n3; i++){
//         if(C[i] == C[i-1]){
//             C[i-1] =INT_MIN;
//         }
//     }
    
//     //Finding Common Elements and inserting in "ans"
//     //3 counters for 3 arrays initialised with 0
//     int i, j, k;
//     i=j=k=0;

//     while(i<n1 && j<n2 && k<n3){
//         //Add common element to "ans" except for INT_MINs
//         if((A[i]==B[j] && B[j]==C[k]) && (A[i] != INT_MIN)){
//             ans.push_back(A[i]);
//             i++; j++; k++;
//         }
//         else if(A[i] < B[j]){
//             i++;
//         }
//         else if(B[j] < C[k]){
//             j++;
//         }
//         else{
//             k++;
//         }
//     }
//     return ans;
// }


//Method 2 : Using set[STL]
// vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
// {   
//     vector<int> ans; //Made an empty vector
//     //making a set as it will not accept duplicate values
//     set<int> ansset;

//     //3 counters for 3 arrays initialised with 0
//     int i, j, k;
//     i=j=k=0;

//     while(i<n1 && j<n2 && k<n3){
//         //Add common element to " ansset "
//         if(A[i]==B[j] && B[j]==C[k]){
//             ansset.insert(A[i]);
//             i++; j++; k++;
//         }
//         else if(A[i] < B[j]){
//             i++;
//         }
//         else if(B[j] < C[k]){
//             j++;
//         }
//         else{
//             k++;
//         }
//     }

//     //Now that we have the " ansset ", just insert elements from "ansset" into "ans"
//     for(auto iter : ansset){
//         ans.push_back(iter);
//     }

//     //Returning ans
//     return ans;
// }


//Method 1 : My method using Hashing and unordered_map[STL]
// vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
// {
//     //making hash and array to return
//     unordered_map<int, int> hash;
//     vector<int> ans;
    
//     //traversing A
//     for(int i = 0; i < n1; i++){
//         //Hashing the first element
//         if(i == 0){
//             hash[A[i]]++;
//         }
//         //Not Hashing duplicate elements
//         else if(A[i] == A[i - 1]){
//             //nthing
//         }
//         else{
//             hash[A[i]]++;
//         }
//     }

//     //traversing B
//     for(int i = 0; i < n2; i++){
//         if(i == 0){
//             hash[B[i]]++;
//         }
//         else if(B[i] == B[i - 1]){
//             //nthing
//         }
//         else{
//             hash[B[i]]++;
//         }
//     }

//     //traversing C
//     for(int i = 0; i < n3; i++){
//         if(i == 0){
//             hash[C[i]]++;
//         }
//         else if(C[i] == C[i - 1]){
//             //nthing
//         }
//         else{
//             hash[C[i]]++;
//         }
        
//         //Inserting in ans but not inserting duplicates
//         if(hash[C[i]] >= 3 && C[i] != C[i - 1]){
//             ans.push_back(C[i]);
//         }
//     }
//     //Returning ans
//     return ans;
// }

// int main(){
//     int A[] = {1, 5, 10, 20, 40, 80};
//     int n1 = 6; 
//     int B[] = {6, 7, 20, 80, 100};
//     int n2 = 5;
//     int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
//     int n3 = 8;

//     vector<int> ans = commonElements (A, B, C, n1, n2, n3);

//     for(auto iter : ans){
//         cout<< iter <<" ";
//     }
// }