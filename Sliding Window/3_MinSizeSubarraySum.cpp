#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    //Main Logic: 2 pointer
    int start = 0;
    int end = 0;
    int sum = 0;
    int length = INT_MAX; //We need to get minimum length

    while(end < n){
        //Include current element
        sum = sum + nums[end];

        while(sum >= target){
            //Minimise the window
            
            //1)Pehle current length store kr lo
            length = min(length, end - start + 1); 

            //2)start ko age bdhao ( 3) to sum bhi update krlena)
            sum = sum - nums[start];
            start++;
        }

        //4) Increase window size
        end++;
    }

    if(length == INT_MAX){
        return 0;
    }
    else{
        return length;
    }
}

int main(){
   
return 0;
}