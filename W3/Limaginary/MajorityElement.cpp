#include<iostream>
#include<vector>
using namespace std;

/**************Majority Element In Array [LeetCode : https://leetcode.com/problems/majority-element/description/]************************************/
//Method 1 : Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    //Apply Moore's voting Algorithm
    int count = 0;
    int element;
    for(int i = 0; i < nums.size(); i++){
        if(count == 0){
            count = 1;
            element = nums[i];
        }
        else if(nums[i] == element){
            count++;
        }
        else{
            count--;
        }
    }
    //Being cautious for if there might be NO majority element in the array
    int celement = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == element){
            celement++;
        }
    }

    if(celement > (nums.size()/2)){
        return element;
    }
return -1;
}

//Method 2 : Using Hashing (STL : unordered_map)(Easy Code hai, DIY)

int main(){
   vector<int> nums = {2,2,1,1,1,2,2};
   cout<<majorityElement(nums)<<endl;
return 0;
}