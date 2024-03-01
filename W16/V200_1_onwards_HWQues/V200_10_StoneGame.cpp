#include<iostream>
#include<vector>
using namespace std;

/******V200_10_StoneGame******/

int solveUsingRE(vector<int>& piles, int start, int end){
    //BC
    if(end - start + 1 == 2){
        //only 2 stone-piles left in piles[] array
        return abs(piles[end] - piles[start]);
    }

    int maxMoreAliceStones = 0;
    
    //Option 1 : Alice takes piles[start], Bob can now take either piles[end] or piles[start + 1]
    int temp1 = piles[start] - piles[end] + solveUsingRE(piles, start + 1, end - 1);
    int temp2 = piles[start] - piles[start + 1] + solveUsingRE(piles, start + 2, end);
    int option1 = max(temp1, temp2);

    //Option 2 : Alice takes piles[end], Bob can now take either piles[start] or piles[end - 1]
    int temp3 = piles[end] - piles[start] + solveUsingRE(piles, start + 1, end - 1);
    int temp4 = piles[end] - piles[end - 1] + solveUsingRE(piles, start, end - 2);
    int option2 = max(temp3, temp4);

    maxMoreAliceStones = max(option1, option2);
    return maxMoreAliceStones;
}

int solveUsingMem(vector<int>& piles, int start, int end, vector<vector<int> >& dp){
    //BC
    if(end - start + 1 == 2){
        //only 2 stone-piles left in piles[] array
        return abs(piles[end] - piles[start]);
    }

    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int maxMoreAliceStones = 0;
    
    //Option 1 : Alice takes piles[start], Bob can now take either piles[end] or piles[start + 1]
    int temp1 = piles[start] - piles[end] + solveUsingMem(piles, start + 1, end - 1, dp);
    int temp2 = piles[start] - piles[start + 1] + solveUsingMem(piles, start + 2, end, dp);
    int option1 = max(temp1, temp2);

    //Option 2 : Alice takes piles[end], Bob can now take either piles[start] or piles[end - 1]
    int temp3 = piles[end] - piles[start] + solveUsingMem(piles, start + 1, end - 1, dp);
    int temp4 = piles[end] - piles[end - 1] + solveUsingMem(piles, start, end - 2, dp);
    int option2 = max(temp3, temp4);

    maxMoreAliceStones = max(option1, option2);
    dp[start][end] = maxMoreAliceStones;

    return dp[start][end];
}

int solveUsingTab(vector<int>& piles){
    vector<vector<int> > dp(piles.size() + 1, vector<int>(piles.size() + 1, -1)); //row x col :: start x end

    //Fill initial data
    for(int start_i = 0; start_i <= piles.size()-1; start_i++){
        for(int end_i = 0; end_i <= piles.size()-1; end_i++){
            if(start_i > end_i) continue; //if start_i > end_i then it's invalid range
            if(start_i == end_i) continue; //start_i can Not equal end_i as piles[] has evn length (See how start & end move in RE solution)
            if(end_i - start_i + 1 == 2){
                //only 2 stone-piles left in piles[] array
                dp[start_i][end_i] = abs(piles[end_i] - piles[start_i]);
            }
        }
    }

    for(int start_i = piles.size()-1; start_i >= 0; start_i--){
        for(int end_i = 0; end_i <= piles.size()-1; end_i++){
            
            if(start_i > end_i) continue; //if start_i > end_i then it's invalid range
            if(start_i == end_i) continue; //start_i can Not equal end_i as piles[] has evn length (See how start & end move in RE solution)
            if(dp[start_i][end_i] != -1) continue; //Answer already stored from "Fill initial data" step 

            int maxMoreAliceStones = 0;
    
            //Option 1 : Alice takes piles[start], Bob can now take either piles[end] or piles[start + 1]
            int temp1 = piles[start_i] - piles[end_i] + dp[start_i + 1][end_i - 1];
            int temp2 = piles[start_i] - piles[start_i + 1] + dp[start_i + 2][end_i];
            int option1 = max(temp1, temp2);

            //Option 2 : Alice takes piles[end], Bob can now take either piles[start] or piles[end - 1]
            int temp3 = piles[end_i] - piles[start_i] + dp[start_i + 1][end_i - 1];
            int temp4 = piles[end_i] - piles[end_i - 1] + dp[start_i][end_i - 2];
            int option2 = max(temp3, temp4);

            maxMoreAliceStones = max(option1, option2);
            dp[start_i][end_i] = maxMoreAliceStones;
        }
    }

    return dp[0][piles.size() - 1];
}

bool stoneGame(vector<int>& piles) {
    //using RE
    // int maxMoreAliceStones = 0; //Maximum Stones more than Bob with which Alice can win
    // int start = 0;
    // int end = piles.size() - 1;
    // maxMoreAliceStones = solveUsingRE(piles, start, end);

    //using Mem
    // int maxMoreAliceStones = 0; //Maximum Stones more than Bob with which Alice can win
    // int start = 0;
    // int end = piles.size() - 1;
    // vector<vector<int> > dp(piles.size() + 1, vector<int>(piles.size() + 1, -1)); //row x col :: start x end
    // maxMoreAliceStones = solveUsingMem(piles, start, end, dp);

    //using Tabulation
    int maxMoreAliceStones = 0; //Maximum Stones more than Bob with which Alice can win
    int start = 0;
    int end = piles.size() - 1;
    maxMoreAliceStones = solveUsingTab(piles);

    // cout<<"Max stones : "<<maxMoreAliceStones<<" ";
    return (maxMoreAliceStones > 0) ? true : false;

    //Giga chad solution {Alice always wins!}
    //return true;

}

int main(){
   
return 0;
}