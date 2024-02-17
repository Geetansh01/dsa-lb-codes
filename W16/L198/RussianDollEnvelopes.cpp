#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/****Russian Doll Envelopes [LeetCode : https://leetcode.com/problems/russian-doll-envelopes/description/]*****/

//Logic same as "L198 : Longest Increasing Subsequence"
//Below soln gives TLE (85 / 87 Test Cases Passed) (BS based Solnn Needed)

bool check(vector<int>& curr, vector<int>& prev){
    //returns True or False for whether "curr" envelope can be placed on top of "prev" envelope
    if((curr[0] < prev[0]) && (curr[1] < prev[1])){
        return true;
    }
    else{
        return false;
    }
}

//Below Code copied from "Longest Increasing Subsequence [LeetCode : https://leetcode.com/problems/longest-increasing-subsequence/description/]"
int solveUsingTabSO(vector<vector<int>>& envelopes){
    int n = envelopes.size();
    // vector<vector<int> > dp(n+1, vector<int>(n+1, 0)); //row x col :: curr x prev
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    //Fill initial data : done by initializing entire dp with 0 (Vaise to khali last row (i.e row = nums.size()) me 0 bharna tha)

    for(int curr_index = n-1; curr_index >= 0; curr_index--){
        //RE+Mem me "prev" worst case me "curr" se just piche ho skta hai but can never be equal to or ahead of it!
        for(int prev_index = curr_index - 1; prev_index >= -1; prev_index--){
            int include = 0;
            if(prev_index == -1 || check(envelopes[curr_index], envelopes[prev_index])){
                include = 1 + nextRow[curr_index+1]; 
            }
            int exclude = 0 + nextRow[prev_index+1];
            currRow[prev_index+1] = max(include, exclude);
        }

        //Update nextRow
        nextRow = currRow;
    }

    return nextRow[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), greater<vector<int> >() );
    int ans = solveUsingTabSO(envelopes);
    return ans;
}

int main(){
   
return 0;
}