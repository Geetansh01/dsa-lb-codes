#include<bits/stdc++.h>
using namespace std;

//Using Range Addition (+ Line Sweep)
//TC: O(L); L = Length of array (to be returned) (Ignore number of updates wala input)

vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    // Main Algo: Line Sweep (With Range Additions) 
    vector<int> ansArr(length, 0);
    for(auto& update : updates){
        int start = update[0];
        int end = update[1];
        int value = update[2];

        ansArr[start] += value;
        if(end + 1 < length) ansArr[end + 1] -= value;
    }

    int prefixSum = 0;
    for(int i = 0; i < length; i++){
        prefixSum += ansArr[i];
        ansArr[i] = prefixSum;
    }

    return ansArr;
}

int main(){
    
return 0;
}