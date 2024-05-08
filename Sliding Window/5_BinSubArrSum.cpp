#include<bits/stdc++.h>
using namespace std;

//Main Apprach : Variable Sliding Window [But a bit off the usual lines]
//TC : O(n); n = size of "nums[]"

//To Understand, try dry running on :
//nums[] = [0, 0, 1, 1, 0]
//goal = 2
//Expected Ans = 6

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int s = 0;
    int e = 0;
    int ways = 0;
    int sum = 0;

    int prefixZeros = 0;

    while(e < n){
        sum += nums[e];


        while((s < e) && ( (sum == goal && nums[s] == 0) || (sum > goal) )){
            //Minimise window

            //1) Count prefix Zeros (Kind of store answer Bcz "prefixZeros" will be used later on to actually store the answer!)
            if(nums[s] == 0){
                prefixZeros++;
            }
            else{
                //If nums[s] is 1
                prefixZeros = 0;
            }

            //2)Start ko age badhao ( 3) sum bhi update krlena)
            sum = sum - nums[s];
            s++; 
        }

        //Actually Store Answer
        if(sum == goal){
            ways += prefixZeros + 1;
        }

        //4)Increase Window size
        e++;
    }

    return ways;
}

int main(){
   
return 0;
}