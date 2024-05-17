#include<bits/stdc++.h>
using namespace std;

//TLE Marega ye solution {Dp Needed}
//TC : Exponential
//My own solution below (same as LB's :) )
int solveRE(int start, int& end, vector<int>& nums){
    //BC
    if(start > end) return 0;

    int maxLoot = 0;
    //Option 1 : Loot current house
    int option1 = nums[start] + solveRE(start + 2, end, nums);

    //Option 2 : Don't Loot current House
    int option2 = 0 + solveRE(start + 1, end, nums);

    maxLoot = max(option1, option2);
    return  maxLoot;
}

int rob(vector<int>& nums) {
    int maxLoot = 0;
    
    //Robbing 0th index House [So last wala ghr rob nhi krna]
    int start = 2;
    int end = nums.size() - 2; 
    int option1 = nums[0] + solveRE(start, end, nums);

    //Not Robbing 0th index House [So last wala ghr rob kr skte ho if u want!]
    int start2 = 1;
    int end2 = nums.size() - 1;
    int option2 = 0 + solveRE(start2, end2, nums);

    maxLoot = max(option1, option2);
    return maxLoot;
}

int main(){
   
return 0;
}