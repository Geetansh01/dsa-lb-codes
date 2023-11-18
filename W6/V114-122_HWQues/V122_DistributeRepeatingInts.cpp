#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/***************122 : Distribute Repeating Integers [LeetCode : https://leetcode.com/problems/distribute-repeating-integers/description/]******************/

bool solveHelper(vector<int> &freq, vector<int>& quantity, int i){
    //Base Case
    if(i >= quantity.size()){
        return true;
    }

    for(int j = 0; j < freq.size(); j++){
        //Trying to allocate ith customer's order
        if(quantity[i] <= freq[j]){
            freq[j] -= quantity[i];

            //RE call for next customer's order
            bool ans = solveHelper(freq, quantity, i+1);
            if(ans){
                return true;
            }
            else{
                freq[j] += quantity[i]; 
            }
        }
    }
    return false;
}

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    sort(quantity.rbegin(), quantity.rend());
    bool ans = false;
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }
    vector<int> freq;
    for(auto i : mp){
        freq.push_back(i.second);
    }

    int i = 0;
    ans = solveHelper(freq, quantity, i);
    return ans;
}

int main(){
   vector<int> nums = {1,1,2,2}; 
   vector<int> quantity = {2,2};
   bool ans = canDistribute(nums, quantity);
   cout<<ans<<endl;

return 0;
}