#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*** M2 : Backtracking ****/
//Ref for Solution (NeetCode YT): " https://youtu.be/mBk4I0X46oI?si=lWWS2ma3pAHhCDNr " 
//TC : O(2^(nk)) (Bcz total length of RE tree can be (n*k) as k trees of n height are stacked on top of each other)

bool solveRE(int i, int j, int sum, int psum, int k, vector<int>& nums, int mark){
    //BCs
    if(i > k){ 
        return true;
    }
    else if(sum != psum && j >= nums.size()){
        return false;
    }

    if(sum == psum){
        bool ReAns = solveRE(i+1, 0, 0, psum, k, nums, mark);
        if(ReAns == true){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        while(j < nums.size()){
            if(nums[j] == mark || sum + nums[j] > psum){
                j++;
                continue;
            }
            
            //Include
            int temp = nums[j];
            nums[j] = mark;
            bool include = solveRE(i, j+1, sum+temp, psum, k, nums, mark);
            if(include == true) return true;

            //If include is false, try exclude
            nums[j] = temp; //Backtrack

            if(sum == 0) return false; //__Line (2). If the largest element cannot fit, there's no point in exploring further as the array is already in descending order.

            j++;
        }
        return false;
    }
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int totSum = 0;
    for(auto& n : nums) totSum += n;
    if(totSum % k != 0) return false;
    int psum = totSum/k; //sum of each partition

    sort(nums.begin(), nums.end(), greater<int>()); //__Line (1)

    int mark = -1; //mark a value in "nums" as used (mark used in solveRE())

    bool ans = solveRE(1, 0, 0, psum, k, nums, mark);
    return ans; 
}


int main(){
    
return 0;
}