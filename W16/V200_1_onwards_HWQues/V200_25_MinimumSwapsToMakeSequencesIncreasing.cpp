#include<bits/stdc++.h>
using namespace std;

//Pre-Req : 1)Do "V200_18 : Make Array Strictly Increasing", "solveUsingRE()" below is totally based on that
//          2)After you understand "solveUsingRE()", you can easily understand "solveUsingRE2()"

int solveUsingRE(vector<int>& nums1, vector<int>& nums2, int prevNums1, int prevNums2, int index){
    //BC
    if(index >= nums1.size()) return 0;

    int minSwaps = 0;

    //Case 1 : If abhi tak str. increasing order maintained hai, So you can decide to swap or not!
    if(prevNums1 < nums1[index] && prevNums2 < nums2[index]){

        //Option1 : Don't Swap
        int option1 = 0 + solveUsingRE(nums1, nums2, nums1[index], nums2[index], index + 1);

        //Option2 : Try to Swap only if it does not disrupt the str. incr. order
        int option2 = INT_MAX;
        if(prevNums1 < nums2[index] && prevNums2 < nums1[index]){
            option2 = 1 + solveUsingRE(nums1, nums2, nums2[index], nums1[index], index + 1);
        }

        minSwaps = min(option1, option2);
    }
    else{
        //Case 2 : If str. increasing order is broken i.e (prevNums1 !< nums1[index] || prevNums2 !< nums2[index])
        //So we must perform a Swap now (& swap ke bad we will definitely get str. incr. order bcz ATQ, the test cases are generated so that the given input always makes it possible. )
        int onlyOption = 1 + solveUsingRE(nums1, nums2, nums2[index], nums1[index], index + 1);
        minSwaps = onlyOption;
    }

    return minSwaps;
}

int solveUsingRE2(vector<int>& nums1, vector<int>& nums2, bool wasPrevSwapped, int index){
    //BC
    if(index >= nums1.size()) return 0;

    int minSwaps = 0;
    
    int prevNums1, prevNums2;
    if(index == 0){
        prevNums1 = -1;
        prevNums2 = -1;
    }
    else if(wasPrevSwapped){
        prevNums1 = nums2[index - 1];
        prevNums2 = nums1[index - 1];
    }
    else{
        prevNums1 = nums1[index - 1];
        prevNums2 = nums2[index - 1];
    }

    //Case 1 : If abhi tak str. increasing order maintained hai, So you can decide to swap or not!
    if(prevNums1 < nums1[index] && prevNums2 < nums2[index]){

        //Option1 : Don't Swap
        int option1 = 0 + solveUsingRE2(nums1, nums2, false, index + 1);

        //Option2 : Try to Swap only if it does not disrupt the str. incr. order
        int option2 = INT_MAX;
        if(prevNums1 < nums2[index] && prevNums2 < nums1[index]){
            option2 = 1 + solveUsingRE2(nums1, nums2, true, index + 1);
        }

        minSwaps = min(option1, option2);
    }
    else{
        //Case 2 : If str. increasing order is broken i.e (prevNums1 !< nums1[index] || prevNums2 !< nums2[index])
        //So we must perform a Swap now (& swap ke bad we will definitely get str. incr. order bcz ATQ, the test cases are generated so that the given input always makes it possible. )
        int onlyOption = 1 + solveUsingRE2(nums1, nums2, true, index + 1);
        minSwaps = onlyOption;
    }

    return minSwaps;
}

int solveUsingMem(vector<int>& nums1, vector<int>& nums2, bool wasPrevSwapped, int index, vector<vector<int> >& dp){
    //BC
    if(index >= nums1.size()) return 0;

    if(dp[wasPrevSwapped][index] != -1){
        return dp[wasPrevSwapped][index];
    }

    int minSwaps = 0;

    int prevNums1, prevNums2;
    if(index == 0){
        prevNums1 = -1;
        prevNums2 = -1;
    }
    else if(wasPrevSwapped){
        prevNums1 = nums2[index - 1];
        prevNums2 = nums1[index - 1];
    }
    else{
        prevNums1 = nums1[index - 1];
        prevNums2 = nums2[index - 1];
    }

    //Case 1 : If abhi tak str. increasing order maintained hai, So you can decide to swap or not!
    if(prevNums1 < nums1[index] && prevNums2 < nums2[index]){

        //Option1 : Don't Swap
        int option1 = 0 + solveUsingMem(nums1, nums2, false, index + 1, dp);

        //Option2 : Try to Swap only if it does not disrupt the str. incr. order
        int option2 = INT_MAX;
        if(prevNums1 < nums2[index] && prevNums2 < nums1[index]){
            option2 = 1 + solveUsingMem(nums1, nums2, true, index + 1, dp);
        }

        minSwaps = min(option1, option2);
    }
    else{
        //Case 2 : If str. increasing order is broken i.e (prevNums1 !< nums1[index] || prevNums2 !< nums2[index])
        //So we must perform a Swap now (& swap ke bad we will definitely get str. incr. order bcz ATQ, the test cases are generated so that the given input always makes it possible. )
        int onlyOption = 1 + solveUsingMem(nums1, nums2, true, index + 1, dp);
        minSwaps = onlyOption;
    }
    dp[wasPrevSwapped][index] = minSwaps;
    
    return dp[wasPrevSwapped][index];
}

int solveUsingTab(vector<int>& nums1, vector<int>& nums2){
    vector<vector<int> > dp(2, vector<int>(nums1.size() + 1, 0));

    for(int index_i = nums1.size() - 1; index_i >= 0; index_i--){
        for(int wasPrevSwapped = 1; wasPrevSwapped >= 0; wasPrevSwapped--){
            int minSwaps = 0;

            int prevNums1, prevNums2;
            if(index_i == 0){
                prevNums1 = -1;
                prevNums2 = -1;
            }
            else if(wasPrevSwapped){
                prevNums1 = nums2[index_i - 1];
                prevNums2 = nums1[index_i - 1];
            }
            else{
                prevNums1 = nums1[index_i - 1];
                prevNums2 = nums2[index_i - 1];
            }

            //Case 1 : If abhi tak str. increasing order maintained hai, So you can decide to swap or not!
            if(prevNums1 < nums1[index_i] && prevNums2 < nums2[index_i]){

                //Option1 : Don't Swap
                int option1 = 0 + dp[false][index_i + 1];

                //Option2 : Try to Swap only if it does not disrupt the str. incr. order
                int option2 = INT_MAX;
                if(prevNums1 < nums2[index_i] && prevNums2 < nums1[index_i]){
                    option2 = 1 + dp[true][index_i + 1];
                }

                minSwaps = min(option1, option2);
            }
            else{
                //Case 2 : If str. increasing order is broken i.e (prevNums1 !< nums1[index_i] || prevNums2 !< nums2[index_i])
                //So we must perform a Swap now (& swap ke bad we will definitely get str. incr. order bcz ATQ, the test cases are generated so that the given input always makes it possible. )
                int onlyOption = 1 + dp[true][index_i + 1];
                minSwaps = onlyOption;
            }
            dp[wasPrevSwapped][index_i] = minSwaps;
        }
    }

    return dp[0][0];
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;

    //Plain RE 1
    //This recursive method has three variables changing between recursive calls, so it requires a 3D DP and no matter how hard I tried, I could not get the last Test case to be passed (Got TLE or MLE) {I even wrote the tabulation solution using map as a DP and vector as a DP but didn't work}.  What was needed was to write a better recursive solution that uses only two variables changing between recursive calls and thus I wrote "Plain RE 2" !
    // int index = 0;
    // int prevNums1 = -1;
    // int prevNums2 = -1;
    // ans = solveUsingRE(nums1, nums2, prevNums1, prevNums2, index);

    //Plain RE 2
    // int index = 0;
    // bool wasPrevSwapped = false;
    // ans = solveUsingRE2(nums1, nums2, wasPrevSwapped, index);

    //Mem (Based on Plain RE 2)
    // int index = 0;
    // bool wasPrevSwapped = false;
    // vector<vector<int> > dp(2, vector<int>(nums1.size() + 1, -1)); //row x col :: wasPrevSwapped x index
    // ans = solveUsingMem(nums1, nums2, wasPrevSwapped, index, dp);

    //Tabulation
    ans = solveUsingTab(nums1, nums2);

    return ans;
}

int main(){
   
return 0;
}