#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**************V120 Permutation - II[LeetCode : https://leetcode.com/problems/permutations-ii/description/]**********************/

void solveHelper(vector<vector<int>> &ans, vector<int>& nums, int i){
    //Base Case
    if(i >= nums.size()){
        ans.push_back(nums);
        return;
    }

    //Using unordered_map to avoid duplicates
    unordered_map<int, bool> visited;
    for(int j = i; j < nums.size(); j++){
        if(visited.find(nums[j]) != visited.end()) continue;
        visited[nums[j]] = true;

        //RE Call
        swap(nums[i], nums[j]);
        solveHelper(ans, nums, i+1);

        //BackTrack
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    int i = 0;
    solveHelper(ans, nums, i);
    return ans;
}

/*
Difference Between two ways to chk if a key exists in a map or not:
Method 1:
    unordered_map<int, bool> mp;
    if(mp.find(3) != mp.end()){
        continue;
    }

Method 2:
    unordered_map<int, bool> mp;
    if(mp[3] == true){
        continue;
    }

Explanation M1(bingAI):
    M1 uses the find() method to check if the key 3 exists in the unordered_map<int, bool> mp. If the key exists, it returns an iterator to the element, otherwise it returns an iterator to the end of the map.

Explanation M2(bingAI):
    M2 uses the subscript operator [] to access the value associated with the key 3 in the unordered_map<int, bool> mp. If the key exists, it returns a reference to the value, otherwise it inserts a new element with the key and a default value of false.

So M1 is better if you just want to check is the key is present or not.

*/

int main(){
   vector<int> nums = {1,2,1};
   vector<vector<int> > ans = permuteUnique(nums);
   for(auto i : ans){
    for(auto j : i){
        cout<<j<<" ";
    }
    cout<<endl;
   }
return 0;
}