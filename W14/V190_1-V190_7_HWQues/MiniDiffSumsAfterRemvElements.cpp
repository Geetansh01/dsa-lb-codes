#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

/******V190_5 : Minimum Difference in Sums After Removal of Elements [LeetCode : https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/]********/

//M1 : TC : O(n logn) SC : O(n)
#define ll long long
long long minimumDifference(vector<int>& nums) {
    int n = nums.size()/3;
    vector<ll> left(nums.size(), -1), right(nums.size(),  -1);
    //left[i] = min sum of n elements from left side
    //right[i] = max sum of n elements from right side

    ll sum = 0; 
    priority_queue<ll> maxH; //max Heap
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        maxH.push(nums[i]);

        //pop max element frm maxHeap
        if(maxH.size() > n){
            sum -= maxH.top();
            maxH.pop();
        }

        if(maxH.size() == n){
            left[i] = sum;
        }
    }

    sum = 0; //Reusing old sum
    priority_queue<ll, vector<ll>, greater<ll> > minH; //max Heap
    for(int i = nums.size()-1; i >= 0; i--){
        sum += nums[i];
        minH.push(nums[i]);

        //pop max element frm maxHeap
        if(minH.size() > n){
            sum -= minH.top();
            minH.pop();
        }

        if(minH.size() == n){
            right[i] = sum;
        }
    }

    ll ans = LONG_LONG_MAX; //long long ka INT_MAX
    for(int i = n-1; i < 2*n; i++){
        ans = min(ans, left[i] - right[i+1]);
    }
    return ans;
}


//M2 : My Soln;  TC : O(n*n logn) 
//Gives TLE on LeetCode (87/110 passed)
// long long int getMinDiff(priority_queue<int>& maxH, priority_queue<int, vector<int>, greater<int> >& minH){
//     long long int first = 0;
//     long long int second = 0;
//     while(!maxH.empty() && !minH.empty()){
//         first += maxH.top(); 
//         second += minH.top();
//         maxH.pop();
//         minH.pop();
//     }

//     return (first - second);
// }

// long long minimumDifference(vector<int>& nums) {
//     int n = nums.size()/3;
//     int size = nums.size();
//     int div = size-n;
//     long long int minDiff = INT_MAX;

//     while(div > n-1){
//         priority_queue<int> maxH;
//         priority_queue<int, vector<int>, greater<int> > minH; 
        
//         for(int i = 0; i < n; i++){
//             maxH.push(INT_MAX);
//             minH.push(INT_MIN);
//         }

//         int i = 0;
//         for(; i < div; i++){
//             if(nums[i] < maxH.top()){
//                 maxH.pop();
//                 maxH.push(nums[i]);
//             }
//         }
//         for(; i < size; i++){
//             if(nums[i] > minH.top()){
//                 minH.pop();
//                 minH.push(nums[i]);
//             }
//         }

//         long long int newDiff = getMinDiff(maxH, minH);
//         minDiff = min(minDiff, newDiff);
        
//         div--;
//     }

//     return minDiff;
// }

int main(){
   
return 0;
}