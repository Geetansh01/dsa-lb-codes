#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*******Sliding Window Maximum [Sliding Window] [LeetCode : https://leetcode.com/problems/sliding-window-maximum/description/]*******/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    //Traverse 1st window
    for(int i = 0; i < k; i++){
        //chote element remove kro
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        //inserting current element index
        dq.push_back(i);
    }

    //Store ans of 1st window 
    ans.push_back(nums[dq.front()]);

    //process remainning window
    for(int i = k; i < nums.size(); i++){
        //out of window remove krdo
        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }

        //Again current eleemnt ke liye usse chote elements remove krne hai
        //chote element remove kro
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        //inserting current element index
        dq.push_back(i);

        //current window ka ans store krna hai
        ans.push_back(nums[dq.front()]);

    }

    return ans;
}

int main(){
   vector<int> nums = {1,3,-1,-3,5,3,6,7};
   int k = 3;
   vector<int> ans = maxSlidingWindow(nums, k);

   for(auto x : ans){
    cout<<x<<" ";
   }
return 0;
}