#include<bits/stdc++.h>
using namespace std;

/*
    Main Logic:
    "solveUsingRE()" returns the difference D i.e (Player1's score - Player2's score). If it is P1's turn currently, it returns maximized D (i.e maximum possible value of D from the given array). If it is P2's turn currently, it returns minimized D. This is because if it is P1's turn, P1 would want D to be maximized, but if it is P2's turn, P2 would want D to be minimized because both of them are playing optimally.
*/
int solveUsingRE(vector<int>& nums, int start, int end, bool P1sTurn){
    //BC
    if(start > end) return 0;

    int difference = 0;

    //Case 1 : It is P1's turn, He will try to maximise (P1 - P2)
    if(P1sTurn == true){
        int option1 = nums[start] + solveUsingRE(nums, start + 1, end, false);
        int option2 = nums[end] + solveUsingRE(nums, start, end - 1, false);
        difference = max(option1, option2);
    }
    else{
        //Case 2 : It is P2's turn, He will try to minimise (P1 - P2)
        int option1 = -nums[start] + solveUsingRE(nums, start + 1, end, true);
        int option2 = -nums[end] + solveUsingRE(nums, start, end - 1, true);
        difference = min(option1, option2);
    }

    return difference;
}

/*
    How "solveUsingRE2()" works:
    1)Say there are two players A & B. Jis bhi player ki current turn ke liye ye function run hoga uss player ke favor ka difference maximise krke return krega. For example, if it is A's turn then it will return maximized (A - B) {Bcz A wants the difference (A - B) to be maximised).
    2)So for P1's turn, it returns maximised (P1 - P2);
    2)So for P2's turn, it returns maximised (P2 - P1);
*/
int solveUsingRE2(vector<int>& nums, int start, int end){
    //BC
    if(start > end) return 0;

    int maxCurrPlayerCanGet = 0;

    //Option1 : X chooses 1st stone
    int option1 = + nums[start] - solveUsingRE2(nums, start + 1, end); 
    /*
        Why we subtracted what RE call returned? Assume it is P1's call currently, so we are doing :  
            => + P1 - (P2 - P1)            {(P2 - P1) from RE call}
            => P1 - P2
        And (P1 - P2) is what we wanted here as it was P1's turn1
    */

    //Option2 : X chooses last stone
    int option2 = + nums[end] - solveUsingRE2(nums, start, end - 1);
    maxCurrPlayerCanGet = max(option1, option2);

    return maxCurrPlayerCanGet;
}

int solveUsingMem(vector<int>& nums, int start, int end, vector<vector<int> >& dp){
    //BC
    if(start > end) return 0;

    if(dp[start][end] != INT_MAX){
        return dp[start][end];
    }

    int maxCurrPlayerCanGet = 0;

    //Option1 : X chooses 1st stone
    int option1 = + nums[start] - solveUsingMem(nums, start + 1, end, dp); 

    //Option2 : X chooses last stone
    int option2 = + nums[end] - solveUsingMem(nums, start, end - 1, dp);
    maxCurrPlayerCanGet = max(option1, option2);
    dp[start][end] = maxCurrPlayerCanGet;

    return dp[start][end];
}

int solveUsingTab(vector<int>& nums){
    vector<vector<int> > dp(nums.size() + 1, vector<int>(nums.size() + 1, 0)); //row x col :: start x end
    //INT_MAX represents dp does not have an answer stored!

    //Fill initial Data
    //1)Done by initialising dp with 0
    //2)if (start = end = y) then the current player will choose the only remaining value at nums[y] (So store it in dp)
    for(int i = 0; i < nums.size(); i++){
        dp[i][i] = nums[i]; 
    }

    for(int start_i = nums.size() - 1; start_i >= 0; start_i--){
        for(int end_i = start_i + 1; end_i <= nums.size() - 1; end_i++){
            int maxCurrPlayerCanGet = 0;

            //Option1 : X chooses 1st stone
            int option1 = + nums[start_i] - dp[start_i + 1][end_i]; 

            //Option2 : X chooses last stone
            int option2 = + nums[end_i] - dp[start_i][end_i - 1];
            maxCurrPlayerCanGet = max(option1, option2);
            dp[start_i][end_i] = maxCurrPlayerCanGet;
        }
    }
    return dp[0][nums.size() - 1];
}

bool predictTheWinner(vector<int>& nums) {
    bool canP1Win = false;

    //Plain RE (3 variables change b/w RE calls)
    // int start = 0;
    // int end = nums.size() - 1;
    // bool P1sTurn = true;
    // int difference = solveUsingRE(nums, start, end, P1sTurn); //"difference" = (P1 - P2)
    // return (difference >= 0) ? true : false;

    //Plain RE 2 (2 variables changing b/w RE calls)
    // int start = 0;
    // int end = nums.size() - 1;
    // int maxCurrPlayerCanGet = solveUsingRE2(nums, start, end); 
    // //Bcz Player1 start 1st so he is the current player right now
    // return maxCurrPlayerCanGet >= 0 ? true : false;

    //Mem Based on Plain RE 2
    // int start = 0;
    // int end = nums.size() - 1;
    // vector<vector<int> > dp(nums.size() + 1, vector<int>(nums.size() + 1, INT_MAX)); //row x col :: start x end
    // //INT_MAX represents dp does not have an answer stored!
    // int maxCurrPlayerCanGet = solveUsingMem(nums, start, end, dp); 
    // //Bcz Player1 start 1st so he is the current player right now
    // return maxCurrPlayerCanGet >= 0 ? true : false;

    //Tab
    int maxCurrPlayerCanGet = solveUsingTab(nums); 
    //Bcz Player1 start 1st so he is the current player right now
    return maxCurrPlayerCanGet >= 0 ? true : false;
}

int main(){
   
return 0;
}