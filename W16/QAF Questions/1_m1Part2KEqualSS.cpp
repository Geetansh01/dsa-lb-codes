#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*** M1 : DP + Bitmasking ****/
//Ref for Top Down Solution (my post on LeetCode :p): " https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solutions/5518946/c-top-down-recursive-dp-with-bitmasking-detailed-explanation " 
//Ref for bottom up Solution : " https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solutions/905981/iterative-dp-deep-analysis-4-solutions-2-ways-of-bit-masking-1-backtracking-1-knapsack "
//TC : O(n * 2^n) (Bcz total `2^n` subsets possible and `for` loop for `n` times in each recursive call)

/*
    Content of the post (See on the site with  better formatting)

    # Approach
    This is a top-down solution using recursion and bit masking. The recursive function takes a bitmask, partition sum (`psum`), and the numbers array. The only thing that changes in recursive calls is the mask.

    ### So what does the recursive function return for a given mask?

    1. **What does the mask signify?**
    The 0s and 1s in the mask represent all the subsets in the given `nums` array. The recursive function uses all the values represented by the ones in the mask. The values corresponding to zeros in the mask are considered already used up and are not touched by the recursive function at all.

    2. **What does the function return for a given mask?**
    - **Overview:** It returns the sum of the values that remain after forming subsets with sums equal to `psum` from the values represented by the mask.
    - **Detailed:** It returns the sum of the remaining values (after forming subsets) if the sum is less than `psum`, or it returns 0 if there are no remaining values. If such a return value is not possible, it returns -1.

    **Example:**
    Say `mask = 111110`, `nums = {5, 7, 8, 3, 2, 5}`, and `psum = 10`.

    The effective array seen by the recursive function is `{5, 7, 8, 3, 2}`. From this, it returns 5 after making two 10-sum subsets, `{7, 3}` and `{8, 2}`. Thus, 5 is returned as `5 <= psum (10)`.

    Note that `{5, 3, 2}` is also a valid subset, but the remaining values would be `7 + 8 = 15 > 10`, so this is not returned.

    ### Main recursive logic to understand:
    1. Forget about the numbers marked as 0 in the mask. You are not allowed to work on them as they are already used up by previous recursive calls.
    2. For the numbers marked as 1 in the mask, I will mark one of them as 0 (in a `newMask`), say X (effectively making it inaccessible for further recursive calls) and send a recursive call with this `newMask`. The function would then return a remainder `<= psum` after making all the subset sums optimally.

    Now, the one value that I marked 0 in the `newMask`, X, will be checked against the returned remainder:
    - If `remain + X` equals `psum`, I can form a subset as `{remain + X}`. So, I return 0.
    - If `remain + X` is less than `psum`, I return `remain + X`.
    - If `remain + X` is greater than `psum`, the 1 that I marked 0 was not an appropriate choice, so I should mark another 1 as 0 and send a recursive call with that.

    I will try this for all the 1's available to me in the bitmask:
    - Change a 1 to 0 (i.e., make a `newMask`)
    - Send the `newMask` to further recursive calls. Get a `remain` back
    - Didn't get an answer? The current `newMask` was not appropriate
    - Go to the next 1 and repeat

    If I can find a solution, great. If not, I will return -1 after the for loop (inside the recursive function) ends.

    ### Why use bitmasking?
    You're right, I could have used a data structure to track which values are used up and which are not. However, this solution is a brute force solution, and I need to be able to apply DP. If I had an unordered map telling me which ones are used and which ones are not, it would replace the mask in the recursive calls. It would be hard to apply DP because you would have to memorize the state of the unordered map.

    All the possible values that the mask can take represent the different subsets of the given array, which are nothing but the power set of the array.

    **Example:**
    For `nums = {a, b, c}` (length = 3), the possible subsets are 8 in total. These can be represented by integers from 0 to 7 in binary form. 

    - `{a}`       `{b}`       `{c}`       `{a, b}`       `{a, c}`       `{b, c}`       `{a, b, c}`       `{}`
    - `100`       `010`       `001`       `110`          `101`          `011`          `111`             `000`

    Now notice that the mask is nothing but an integer from 0 to 7. Instead of memorizing the state of an unordered map, I can simply memorize an integer that ranges from 0 to 7. This makes it possible to use dynamic programming.

    # Complexity
    - Time complexity: O(n * 2^n) (Bcz total `2^n` subsets possible and `for` loop for `n` times in each recursive call)

    - Space complexity: O(2^n) (In DP storage)

    - Bottom Up version of above approach: [Post Link](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solutions/905981/iterative-dp-deep-analysis-4-solutions-2-ways-of-bit-masking-1-backtracking-1-knapsack)

*/

    int solveRE(int mask, int psum, vector<int>& nums){
        //BC
        if(mask == 0){
            return 0;
        }

        int len = nums.size();
        for(int j = 0; j < len; j++){
            bool jthBitSet = ((mask & (1<<j)) != 0); //Check if jth bit is set or not
            if(jthBitSet){
                //Make a new mask in which jth bit is unset
                int newMask = mask & (~(1<<j));
                int remain = solveRE(newMask, psum, nums);
                if(remain != -1){
                    int newRemain = nums[len-1-j] + remain;
                    if(newRemain == psum){
                        return 0;
                    }
                    else if(newRemain < psum){
                        return newRemain;
                    }
                }  
            }
        }
        return -1;
    }

    int solveMem(int mask, int psum, vector<int>& nums, vector<int>& dp){
        //BC
        if(mask == 0){
            return 0;
        }

        if(dp[mask] != -2){
            return dp[mask];
        }

        int len = nums.size();
        for(int j = 0; j < len; j++){
            bool jthBitSet = ((mask & (1<<j)) != 0); //Check if jth bit is set or not
            if(jthBitSet){
                //Make a new mask in which jth bit is unset
                int newMask = mask & (~(1<<j));
                int remain = solveMem(newMask, psum, nums, dp);
                if(remain != -1){
                    int newRemain = nums[len-1-j] + remain;
                    if(newRemain == psum){
                        dp[mask] = 0;
                        return dp[mask];
                    }
                    else if(newRemain < psum){
                        dp[mask] = newRemain;
                        return dp[mask];
                    }
                }  
            }
        }
        dp[mask] = -1;
        return dp[mask];
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int len = nums.size();
        int totSum = 0;
        for(auto& n : nums) totSum += n;
        if(totSum % k != 0) return false;
        int psum = totSum/k; //required sum of each partition

        int initialMask = (1<<len) - 1; //Ex: If "nums" is of length 3 then "initialMask" will be 00...000111 (i.e 3 one's in the last )

        int ans = -1;

        //Plain RE (Recursion + bitmasking)
        // ans = solveRE(initialMask, psum, nums);

        //Memoization
        vector<int> dp ((1<<len), -2); // -2 means DP has no answer stored. -1 means DP has answer stored. That answer is "not possible" 
        ans = solveMem(initialMask, psum, nums, dp);

        if(ans == 0){
            return true;
        }
        return false;
    }

int main(){
    
return 0;
}