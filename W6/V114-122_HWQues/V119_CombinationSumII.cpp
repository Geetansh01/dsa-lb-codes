#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*************Combination Sum II [LeetCode : https://leetcode.com/problems/combination-sum-ii/description/]**********************/

void solveHelper(vector<int>& candidates, int& target, int& sum, vector<int> &possible_ans, int prev, vector<vector<int> > &combos){
    //Base Case
    if(sum >= target){
        if(sum == target){
            combos.push_back(possible_ans);
        }
        return;
    }

    for(int i = prev; i < candidates.size(); i++){
        //To avoid Duplicates
        if(i > prev && candidates[i] == candidates[i-1]) continue;

        sum = sum + candidates[i];
        possible_ans.push_back(candidates[i]);

        //RE Call
        solveHelper(candidates, target, sum, possible_ans, i+1, combos);

        //BackTrack
        sum = sum - candidates[i];
        possible_ans.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int& target) {
    vector<int> possible_ans;
    vector<vector<int> > combos;
    int sum = 0;
    int prev = 0;

    //To avoid Duplicates
    sort(candidates.begin(), candidates.end());
    
    solveHelper(candidates, target, sum, possible_ans, prev, combos);
    return combos;
}

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int> > ans = combinationSum2(candidates, target);
    for(auto iter : ans){
        for(auto i : iter){
            cout<<i<<" ";
        }
        cout<<endl;
    }

return 0;
}