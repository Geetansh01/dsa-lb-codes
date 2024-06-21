#include<bits/stdc++.h>
using namespace std;

//TC : O(n)
/*
    Hint 1 : Create an array sumLeft where sumLeft[i] is the sum of all the numbers to the left of index i.
    Hint 2 : Create an array sumRight where sumRight[i] is the sum of all the numbers to the right of index i.
    Hint 3 : For each index i, check if sumLeft[i] equals sumRight[i] return i. If no i found, return -1.
*/ 
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> cumSumLeft(n, 0); //Cumulative sum from left
    vector<int> cumSumRight(n, 0);

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        cumSumLeft[i] = sum;
    }

    sum = 0;
    for(int i = n-1; i >= 0; i--){
        sum += nums[i];
        cumSumRight[i] = sum;
    }

    for(int i = 0; i < n; i++){
        if(cumSumRight[i] == cumSumLeft[i]) return i;
    }
    return -1;
}

int main(){
   
return 0;
}