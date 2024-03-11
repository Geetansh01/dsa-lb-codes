#include<bits/stdc++.h>
using namespace std;

//Do "V200_19 : Best Time to Buy and Sell Stock II DP Solution" before this, then to ye Question Halwa hai :p

int solveUsingRE(vector<int>& prices, bool canBuy, int transactions, int index){
    //BC
    if(index >= prices.size()) return 0;
    if(transactions <= 0) return 0;

    int maxProfit = 0;
    if(canBuy){
        //Option1 : Buy today
        int profit1 = -(prices[index]) + solveUsingRE(prices, false, transactions, index + 1);

        //Option2 : don't buy
        int profit2 = 0 + solveUsingRE(prices, true, transactions, index + 1);
        maxProfit = max(profit1, profit2);
    }
    else{
        //option3 : Sell
        int profit3 = +(prices[index]) + solveUsingRE(prices, true, transactions - 1, index + 1);

        //Option4 : Don't Sell
        int profit4 = 0 + solveUsingRE(prices, false, transactions, index + 1);
        maxProfit = max(profit3, profit4);
    }
    return maxProfit;
}

int solveUsingMem(vector<int>& prices, bool canBuy, int transactions, int index, vector<vector<vector<int> > >& dp){
    //BC
    if(index >= prices.size()) return 0;
    if(transactions <= 0) return 0;

    if(dp[canBuy][transactions][index] != -1){
        return dp[canBuy][transactions][index];
    }

    int maxProfit = 0;
    if(canBuy){
        //Option1 : Buy today
        int profit1 = -(prices[index]) + solveUsingMem(prices, false, transactions, index + 1, dp);

        //Option2 : don't buy
        int profit2 = 0 + solveUsingMem(prices, true, transactions, index + 1, dp);
        maxProfit = max(profit1, profit2);
    }
    else{
        //option3 : Sell
        int profit3 = +(prices[index]) + solveUsingMem(prices, true, transactions - 1, index + 1, dp);

        //Option4 : Don't Sell
        int profit4 = 0 + solveUsingMem(prices, false, transactions, index + 1, dp);
        maxProfit = max(profit3, profit4);
    }
    dp[canBuy][transactions][index] = maxProfit;
    return dp[canBuy][transactions][index];
}

int solveUsingTab(vector<int>& prices){
    vector<vector<vector<int> > > dp( 2, vector<vector<int> >( 3, vector<int>( prices.size() + 1, 0 ) ) ); //A x B x C :: canBuy x transaction x index

    //Fill initial Data : done by initializing dp with 0

    for(int index_i = prices.size() - 1; index_i >= 0; index_i--){
        for(int canBuy_i = 0; canBuy_i <= 1; canBuy_i++){
            for(int transactions_i = 1; transactions_i <= 2; transactions_i++){
                int maxProfit = 0;
                if(canBuy_i){
                    //Option1 : Buy today
                    int profit1 = -(prices[index_i]) + dp[false][transactions_i][index_i + 1];

                    //Option2 : don't buy
                    int profit2 = 0 + dp[true][transactions_i][index_i + 1];
                    maxProfit = max(profit1, profit2);
                }
                else{
                    //option3 : Sell
                    int profit3 = +(prices[index_i]) + dp[true][transactions_i - 1][index_i + 1];

                    //Option4 : Don't Sell
                    int profit4 = 0 + dp[false][transactions_i][index_i + 1];
                    maxProfit = max(profit3, profit4);
                }
                dp[canBuy_i][transactions_i][index_i] = maxProfit;
            }
        }
    }
    return dp[1][2][0];
}

int solveUsingTabSO(vector<int>& prices){
    // vector<vector<vector<int> > > dp( 2, vector<vector<int> >( 3, vector<int>( prices.size() + 1, 0 ) ) ); //A x B x C :: canBuy x transaction x index
    vector<vector<int> > current(2, vector<int>(3, 0));
    vector<vector<int> > next(2, vector<int>(3, 0));

    //Fill initial Data : done by initializing dp with 0

    for(int index_i = prices.size() - 1; index_i >= 0; index_i--){
        for(int canBuy_i = 0; canBuy_i <= 1; canBuy_i++){
            for(int transactions_i = 1; transactions_i <= 2; transactions_i++){
                int maxProfit = 0;
                if(canBuy_i){
                    //Option1 : Buy today
                    int profit1 = -(prices[index_i]) + next[false][transactions_i];

                    //Option2 : don't buy
                    int profit2 = 0 + next[true][transactions_i];
                    maxProfit = max(profit1, profit2);
                }
                else{
                    //option3 : Sell
                    int profit3 = +(prices[index_i]) + next[true][transactions_i - 1];

                    //Option4 : Don't Sell
                    int profit4 = 0 + next[false][transactions_i];
                    maxProfit = max(profit3, profit4);
                }
                current[canBuy_i][transactions_i] = maxProfit;
            }
        }
        //Update next
        next = current;
    }
    return next[1][2];
}

int maxProfit(vector<int>& prices) {
    int ans = 0;

    //Plain RE
    // bool canBuy = true;
    // int transactions = 2;
    // int index = 0;
    // ans = solveUsingRE(prices, canBuy, transactions, index);

    //Mem
    // bool canBuy = true;
    // int transactions = 2;
    // int index = 0;
    // vector<vector<vector<int> > > dp( 2, vector<vector<int> >( 3, vector<int>( prices.size() + 1, -1 ) ) ); //A x B x C :: canBuy x transaction x index
    // ans = solveUsingMem(prices, canBuy, transactions, index, dp);

    //Tabulation
    // ans = solveUsingTab(prices);

    //TabulationSO
    ans = solveUsingTabSO(prices);

    return ans;
}

int main(){
   
return 0;
}