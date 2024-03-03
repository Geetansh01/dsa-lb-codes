#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Do "V200_11 :  Stone Game II" before this (StoneGameII should be marked Hard Level & this one medium but LeetCode has done the opposite ¯\_(ツ)_/¯)
//Below solution Copied from "V200_11 :  Stone Game II" (With slight changes)
//It's my own solution below ! 

//For an alternate solution with Similar TC, see "https://youtu.be/HsLG5QW9CFQ?si=BQE9AOUPy-tq1Xnc" - Lakshay Bhaiya ne bhi yhi se chapa hai (Here, we calculate (Alice - Bob) or smthing like that, This method of solving falls in the "minmax game approach" !)

int solveUsingRE(vector<int>& stoneValue, int ptr, vector<int>& vec){
    //BC
    if(ptr >= stoneValue.size()){
        //No more stones to pick so the current player can get max 0 stone-value!
        return 0;
    }

    // Whomsoever's turn it is, we will find what is the most no of stone-value they can get from this point onwards [i.e from index = "ptr" in "stoneValue[] " upto end of "stoneValue[]"]
    int maxStonesCurrentPlayerCanGet = INT_MIN;
    int stonesFromCurrTurn = 0;
    for(int i = ptr; (i <= ptr + (3 - 1)) && (i < stoneValue.size()) ; i++){
        stonesFromCurrTurn += stoneValue[i]; 

        int valueFromVec = (i + 1 < stoneValue.size() ? vec[i+1] : 0); //Maximum index of "vec" = stoneValue.size() - 1

        int stonesFromFutureTurns = valueFromVec - solveUsingRE(stoneValue, i + 1, vec);
        maxStonesCurrentPlayerCanGet = max(stonesFromCurrTurn + stonesFromFutureTurns,
                                            maxStonesCurrentPlayerCanGet);
    }

    return maxStonesCurrentPlayerCanGet;

}

int solveUsingMem(vector<int>& stoneValue, int ptr, vector<int>& vec, vector<int>& dp){
    //BC
    if(ptr >= stoneValue.size()){
        //No more stones to pick so the current player can get max 0 stone-value!
        return 0;
    }

    if(dp[ptr] != INT_MIN){
        return dp[ptr];
    }

    int maxStonesCurrentPlayerCanGet = INT_MIN;
    int stonesFromCurrTurn = 0;
    for(int i = ptr; (i <= ptr + (3 - 1)) && (i < stoneValue.size()) ; i++){
        stonesFromCurrTurn += stoneValue[i]; 

        int valueFromVec = (i + 1 < stoneValue.size() ? vec[i+1] : 0); //Maximum index of "vec" = stoneValue.size() - 1

        int stonesFromFutureTurns = valueFromVec - solveUsingMem(stoneValue, i + 1, vec, dp);
        maxStonesCurrentPlayerCanGet = max(stonesFromCurrTurn + stonesFromFutureTurns,
                                            maxStonesCurrentPlayerCanGet);
    }

    dp[ptr] = maxStonesCurrentPlayerCanGet;

    return dp[ptr];

}

int solveUsingTab(vector<int>& stoneValue, vector<int>& vec){
    vector<int> dp(stoneValue.size() + 1, INT_MIN);

    //Fill initial data
    dp[stoneValue.size()] = 0;

    for(int ptr_index = stoneValue.size() - 1; ptr_index >= 0; ptr_index--){
        int maxStonesCurrentPlayerCanGet = INT_MIN;
        int stonesFromCurrTurn = 0;
        for(int i = ptr_index; (i <= ptr_index + (3 - 1)) && (i < stoneValue.size()) ; i++){
            stonesFromCurrTurn += stoneValue[i]; 

            int valueFromVec = (i + 1 < stoneValue.size() ? vec[i+1] : 0); //Maximum index of "vec" = stoneValue.size() - 1

            int stonesFromFutureTurns = valueFromVec - dp[i + 1];
            maxStonesCurrentPlayerCanGet = max(stonesFromCurrTurn + stonesFromFutureTurns,
                                                maxStonesCurrentPlayerCanGet);
        }

        dp[ptr_index] = maxStonesCurrentPlayerCanGet;
    }

    return dp[0];
}

string stoneGameIII(vector<int>& stoneValue) {
    //Precalculating all sums
    vector<int> vec(stoneValue.size(), 0); // vec[index] gives sum of stone-values from index upto end in "stoneValue[]"
    int temp = 0;
    for(int i = stoneValue.size() - 1; i >= 0; i--){
        temp += stoneValue[i];
        vec[i] = temp;
    }

    //Plain RE
    // int ptr = 0; //traverses "stoneValue[]" array
    // // "solveUsingRE()" returns the max Stones the player with the current turn can get from this point onwards [i.e from index = "ptr" in "piles[] " upto end of "piles[]"] 
    // // Since Alice get's the 1st turn, here it will return the maximum number of stones Alice can get!
    // int maxStonesAliceCanGet = solveUsingRE(stoneValue, ptr, vec);
    // int maxStonesBobCanGet = vec[0] - maxStonesAliceCanGet;

    //Mem
    // int ptr = 0; //traverses "stoneValue[]" array
    // vector<int> dp(stoneValue.size() + 1, INT_MIN);
    // int maxStonesAliceCanGet = solveUsingMem(stoneValue, ptr, vec, dp);
    // int maxStonesBobCanGet = vec[0] - maxStonesAliceCanGet;

    //Tabulation
    int maxStonesAliceCanGet = solveUsingTab(stoneValue, vec);
    int maxStonesBobCanGet = vec[0] - maxStonesAliceCanGet;



    if(maxStonesAliceCanGet == maxStonesBobCanGet){
        return "Tie";
    }
    else if(maxStonesAliceCanGet > maxStonesBobCanGet){
        return "Alice";
    }
    else{
        return "Bob";
    }
}

int main(){
   
return 0;
}