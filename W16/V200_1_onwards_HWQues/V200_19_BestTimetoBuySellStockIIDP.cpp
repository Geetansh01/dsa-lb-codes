#include<bits/stdc++.h>
using namespace std;

//Solution Using Dynamic Programming Approach Below

int solveUsingRE(vector<int>& prices, bool canBuy, int index){
    //BC
    if(index >= prices.size()) return 0;

    int maxProfit = 0;

    //If you can Buy Today
    if(canBuy){
        //Option1 : Buy Today
        int option1 = -(prices[index]) + solveUsingRE(prices, false, index + 1);

        //Option2 : Don't Buy Today, ignore todays day
        int option2 = 0 + solveUsingRE(prices, true, index + 1);

        maxProfit = max(option1, option2);
    }
    else{
        //Option1 : Sell Today
        int option3 = +(prices[index]) + solveUsingRE(prices, true, index + 1);

        //Option4 : Don't Sell Today, ignore todays day
        int option4 = 0 + solveUsingRE(prices, false, index + 1);

        maxProfit = max(option3, option4);
    }

    return maxProfit;
}

int solveUsingMem(vector<int>& prices, bool canBuy, int index, vector<vector<int> >& dp){
    //BC
    if(index >= prices.size()) return 0;

    if(dp[canBuy][index] != -1){
        return dp[canBuy][index];
    }

    int maxProfit = 0;

    //If you can Buy Today
    if(canBuy){
        //Option1 : Buy Today
        int option1 = -(prices[index]) + solveUsingMem(prices, false, index + 1, dp);

        //Option2 : Don't Buy Today, ignore todays day
        int option2 = 0 + solveUsingMem(prices, true, index + 1, dp);

        maxProfit = max(option1, option2);
    }
    else{
        //Option1 : Sell Today
        int option3 = +(prices[index]) + solveUsingMem(prices, true, index + 1, dp);

        //Option4 : Don't Sell Today, ignore todays day
        int option4 = 0 + solveUsingMem(prices, false, index + 1, dp);

        maxProfit = max(option3, option4);
    }
    
    dp[canBuy][index] = maxProfit;
    return dp[canBuy][index];
}

int solveUsingTab(vector<int>& prices){
    vector<vector<int> > dp(2, vector<int>(prices.size() + 1, 0)); //row x col :: canBuy x index

    //Fill Initial Data : done by initializing dp with 0

    //canBuy_i = 0 Means false; canBuy_i = 1 Means True (i.e You can Buy Stock Today)
    //How & why the "canBuy_i" loop works is a bit tricky, try dry running for prices[] = [1,5,3,6]; Expected Answer : 7
    //How I did it : initially i was not getting the right answer so i dry runned the Plain RE soln on "prices[] = [1,5,3,6]" to see what it does & modified Below loops to mimick that behavior! 
    for(int index_i = prices.size() - 1; index_i >= 0; index_i--){
        for(int canBuy_i = 0; canBuy_i <= 1; canBuy_i++){
            int maxProfit = 0;

            //If you can Buy Today
            if(canBuy_i){
                //Option1 : Buy Today
                int option1 = -(prices[index_i]) + dp[false][index_i + 1];

                //Option2 : Don't Buy Today, ignore todays day
                int option2 = 0 + dp[true][index_i + 1];

                maxProfit = max(option1, option2);
            }
            else{
                //Option1 : Sell Today
                int option3 = +(prices[index_i]) + dp[true][index_i + 1];

                //Option4 : Don't Sell Today, ignore todays day
                int option4 = 0 + dp[false][index_i + 1];

                maxProfit = max(option3, option4);
            }
            
            dp[canBuy_i][index_i] = maxProfit;
        }
    }

    return dp[1][0];

}

int solveUsingTabSO(vector<int>& prices){
    // vector<vector<int> > dp(2, vector<int>(prices.size() + 1, 0)); //row x col :: canBuy x index

    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    //Fill Initial Data : done by initializing dp with 0

    //canBuy_i = 0 Means false; canBuy_i = 1 Means True (i.e You can Buy Stock Today)
    //How & why the "canBuy_i" loop works is a bit tricky, try dry running for prices[] = [1,5,3,6]; Expected Answer : 7
    //How I did it : initially i was not getting the right answer so i dry runned the Plain RE soln on "prices[] = [1,5,3,6]" to see what it does & modified Below loops to mimick that behavior! 
    for(int index_i = prices.size() - 1; index_i >= 0; index_i--){
        for(int canBuy_i = 0; canBuy_i <= 1; canBuy_i++){
            int maxProfit = 0;

            //If you can Buy Today
            if(canBuy_i){
                //Option1 : Buy Today
                int option1 = -(prices[index_i]) + next[false];

                //Option2 : Don't Buy Today, ignore todays day
                int option2 = 0 + next[true];

                maxProfit = max(option1, option2);
            }
            else{
                //Option1 : Sell Today
                int option3 = +(prices[index_i]) + next[true];

                //Option4 : Don't Sell Today, ignore todays day
                int option4 = 0 + next[false];

                maxProfit = max(option3, option4);
            }
            
            curr[index_i] = maxProfit;
        }

        //Update next
        next = curr;
    }

    return curr[1]; //Using this I was able to submit on LeetCode but some other questions me gdbd hojati thi so I am making practice to return answer from next[] !
    return next[1];
}

int maxProfit(vector<int>& prices) {
    int ans = 0;
    
    // //Plain RE
    // bool canBuy = true;
    // int index = 0;
    // ans = solveUsingRE(prices, canBuy, index);

    //Mem
    // bool canBuy = true;
    // int index = 0;
    // vector<vector<int> > dp(2, vector<int>(prices.size() + 1, -1)); //row x col :: canBuy x index
    // ans = solveUsingMem(prices, canBuy, index, dp); 

    //Tab
    // ans = solveUsingTab(prices); 

    //TabSo [TC : O(n); SC : O(1); n is size of prices[] array]
    ans = solveUsingTab(prices); 

    return ans;
}

int main(){
   
return 0;
}