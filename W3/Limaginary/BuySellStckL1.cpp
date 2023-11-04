#include<iostream>
#include<vector>
using namespace std;

/*************************BuySellStock Level 1 [LeetCode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/]****************************************/
int maxProfit(vector<int>& prices) {
    int minimum = prices[0];
    int profit = 0;
    for(int i = 1; i < prices.size(); i++){
        int diff = prices[i] - minimum;
        profit = max(profit, diff);
        minimum = min(minimum, prices[i]); 
    }
    return profit;
}

int main(){
   vector<int> prices = {7,1,5,3,6,4};
   int ans = maxProfit(prices);
   cout<<"Max Profit u can make is : "<<ans<<endl;
return 0;
}