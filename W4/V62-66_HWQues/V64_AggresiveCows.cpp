#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

/*************************Q 64 : Aggresive Cows[GFG : https://practice.geeksforgeeks.org/problems/aggressive-cows/1]*************************************************/
//Very Very Similar to "Q 62 : Book Allocation Problem"
/*
Ques : 
You are given an array consisting of n integers which denote the position of a stall. 
You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.
*/

//Predicate function
bool check(int n, int k, vector<int>& arr, int testValue){
    int i = 1;
    k = k - 1;
    int ctbpa = arr[0] + testValue; //Cow To Be Placed At
    while(k > 0 && i < n){
        if(arr[i] >= ctbpa){
            k--;
            ctbpa = arr[i] + testValue;
        }
        i++;
    }
    if(k > 0){
        return false;
    }
    else{
        return true;
    }
}

int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    //Finding SS
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(stalls[i] > max){
            max = stalls[i];
        }
        if(stalls[i] < min){
            min = stalls[i];
        }
    }
    
    int ans = -1;
    int s = 0;
    int e = max - min;
    int mid = s + (e-s)/2;
    
    while(s <= e){
        if(check(n, k , stalls, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    int n=5; 
    vector<int> stalls = {10, 1, 2, 7, 5};
    int k=3;

    cout<<solve(n, k, stalls)<<endl;

return 0;
}