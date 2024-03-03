#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/***********/

/*
    Hint:
    Both Players will play optimally. This means that each player needs to maximize their stones while being aware that the other player will try to do the same when it's their turn.
*/

int solveUsingRE(vector<int>& piles, int ptr, int M, unordered_map<int, int>& mp){
    //BC
    if(ptr >= piles.size()){
        //No more piles to pick so the current player can get max 0 stones!
        return 0;
    }
    //Below is another valid Base Case but it's harder to implement in Tabulation Approach
    // if(ptr + (2*M - 1) >= piles.size() - 1){
    //     //If a player can take all the remainig stones then that is the best/optimal move for him, just take them all!
    //     return mp[ptr];
    // }

    // Whomsoever's turn it is, we will find what is the most no of stones they can get from this point onwards [i.e from index = "ptr" in "piles[] " upto end of "piles[]"]
    int maxStonesCurrentPlayerCanGet = 0;
    int stonesFromCurrTurn = 0;
    for(int i = ptr; (i <= ptr + (2*M - 1)) && (i < piles.size()) ; i++){
        stonesFromCurrTurn += piles[i]; 
        int stonesFromFutureTurns = mp[i+1] - solveUsingRE(piles, i + 1, max(M, i - ptr + 1), mp);
        maxStonesCurrentPlayerCanGet = max(stonesFromCurrTurn + stonesFromFutureTurns,
                                            maxStonesCurrentPlayerCanGet);
    }

    return maxStonesCurrentPlayerCanGet;

}

int solveUsingMem(vector<int>& piles, int ptr, int M, unordered_map<int, int>& mp, vector<vector<int>>& dp){
    //BC
    if(ptr >= piles.size()){
        //No more piles to pick so the current player can get max 0 stones!
        return 0;
    }

    if(dp[ptr][M] != -1){
        return dp[ptr][M];
    }

    // Whomsoever's turn it is, we will find what is the most no of stones they can get from this point onwards [i.e from index = "ptr" in "piles[] " upto end of "piles[]"]
    int maxStonesCurrentPlayerCanGet = 0;
    int stonesFromCurrTurn = 0;
    for(int i = ptr; (i <= ptr + (2*M - 1)) && (i < piles.size()) ; i++){
        stonesFromCurrTurn += piles[i]; 
        int stonesFromFutureTurns = mp[i+1] - solveUsingMem(piles, i + 1, max(M, i - ptr + 1), mp, dp);
        maxStonesCurrentPlayerCanGet = max(stonesFromCurrTurn + stonesFromFutureTurns,
                                            maxStonesCurrentPlayerCanGet);
    }

    dp[ptr][M] = maxStonesCurrentPlayerCanGet;

    return dp[ptr][M];

}

int solveUsingTab(vector<int>& piles,  unordered_map<int, int>& mp){

    vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, 0)); //row x col :: ptr x M

    //Fill initial data : done by initiating dp with 0

    //Fill remaining data
    for(int ptr_index = piles.size() - 1; ptr_index >= 0; ptr_index--){
        for(int M_index = piles.size(); M_index >= 1; M_index--){

            int maxStonesCurrentPlayerCanGet = 0;
            int stonesFromCurrTurn = 0;
            for(int i = ptr_index; (i <= ptr_index + (2*M_index - 1)) && (i < piles.size()) ; i++){
                stonesFromCurrTurn += piles[i]; 
                int stonesFromFutureTurns = mp[i+1] - dp[i + 1][max(M_index, i - ptr_index + 1)];
                maxStonesCurrentPlayerCanGet = max(stonesFromCurrTurn + stonesFromFutureTurns,
                                                    maxStonesCurrentPlayerCanGet);
            }

            dp[ptr_index][M_index] = maxStonesCurrentPlayerCanGet;
        }
    }

    return dp[0][1];
}

int stoneGameII(vector<int>& piles) {
    int maxStonesAliceCanGet = 0;
    //Precalculating all sums
    unordered_map<int, int> mp; // index ---> sum of values from index upto end in "piles[]"
    int temp = 0;
    for(int i = piles.size() - 1; i >= 0; i--){
        temp += piles[i];
        mp[i] = temp;
    }

    //Plain RE
    // int ptr = 0; //traverses "piles[]" array
    // int M = 1;
    // maxStonesAliceCanGet = solveUsingRE(piles, ptr, M, mp);
    // "solveUsingRE()" returns the max Stones the player with the current turn can get from this point onwards [i.e from index = "ptr" in "piles[] " upto end of "piles[]"] 
    // Since Alice get's the 1st turn, here it will return the maximum number of stones Alice can get!


    //Mem
    int ptr = 0; //traverses "piles[]" array
    int M = 1;
    //Note that M can, atmax, become equal to piles.size() but not more (Vaise isse bhi chota hi bnra hai, try making M max for any test case!)
    vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, -1)); //row x col :: ptr x M
    maxStonesAliceCanGet = solveUsingMem(piles, ptr, M, mp, dp);

    //Tab
    // maxStonesAliceCanGet = solveUsingTab(piles, mp);

    /*
        This is one of those questions where the top-down approach actually works faster than the bottom-up approach, even though they have the same time complexity (i.e more submission Time on LeetCode). This is because in the top-down approach, no unnecessary values are calculated. In contrast, in the bottom-up approach, I took M to be from 1 to piles.size() (but this actually means I have considered some values of M that would have never occurred in the top-down approach). These unnecessary values might never have to be calculated in the top-down approach.
    */


    return maxStonesAliceCanGet;
}

int main(){
   
return 0;
}