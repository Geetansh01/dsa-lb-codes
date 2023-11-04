/*
Question : you are given an array/list of 'n' integers you are supposed to return 
           the maximum sum of the subsequence with the constraint that no two elements
           are adjacent in the given array/list.
*/
//Similar to LeetCode : House Robber (Solved in HW maybe)
/*
In "MaximumSumOfNonAdjacentElementsEASY.cpp" , I am writing the code from the lecture. 
For BETTER version of the same code see "MaximumSumOfNonAdjacentElementsBETTER.cpp"
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Many of the arguments in the below function can be removed (See "MaximumSumOfNonAdjacentElementsBETTER.cpp")
void solve(vector<int>& arr, int i, int sum, int& maxi){
    //Base Case
    if(i >= arr.size()){
        //update maxi
        maxi = max(sum, maxi);
        return;
    }

        //include
        solve(arr, i+2, sum + arr[i], maxi);

        //exclude
        solve(arr, i+1, sum, maxi);

}

int main(){
    vector<int> arr{2,1,4,9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, i, sum, maxi);
    cout<<"Answer : "<<maxi<<endl;

    return 0;
}