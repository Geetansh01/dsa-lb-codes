#include<bits/stdc++.h>
using namespace std;

//Below code copied from "V200_20 : Best Time to Buy and Sell Stock III", just replace "2" from old code with "k" here!

int solveUsingTabSO(vector<int>& prices, int k){
    vector<vector<int> > current(2, vector<int>(k+1, 0));
    vector<vector<int> > next(2, vector<int>(k+1, 0));

    //Fill initial Data : done by initializing dp with 0

    for(int index_i = prices.size() - 1; index_i >= 0; index_i--){
        for(int canBuy_i = 0; canBuy_i <= 1; canBuy_i++){
            for(int transactions_i = 1; transactions_i <= k; transactions_i++){
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
    return next[1][k];
}

int maxProfit(int k, vector<int>& prices) {
    int ans = 0;

    //TabulationSO
    ans = solveUsingTabSO(prices, k);

    return ans;
}

int main(){
   
return 0;
}