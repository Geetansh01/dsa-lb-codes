#include<bits/stdc++.h>
using namespace std;

//Solution Using Greedy Apprach Below
//TC : O(n)

/*
    Hints:
    1)The most basic thing to understand before doing any "Buy and Sell Stock" problem :

        Take ex : prices[] = [1,4,7,8,6,4]
        If you take diff(1, 8) = 7
        OR
        If you take diff(1, 4) + diff(4, 7) + diff(7, 8) = 3 + 3 + 1 = 7

        Going directly to 8, or going to 8 by adding all differences in between is same in result, so rather than thinking to jump, think it in this way.
        Why? : Try plotting on Graph & it will seem common sense!
    2)Imagine you were a stock trader and you know the future prices for a given stock (This is the problem input). Each day you would buy the stock if you knew you could sell it tomorrow for a profit (This is the greedy solution).

*/

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int currStockVal = -1; //-1 means Stock kharida hi nhi, 0 means 0$ me stock kharid liya

    for(int i = 0; i <= prices.size() - 1; i++){
        if(currStockVal != -1){
            profit += prices[i] - currStockVal; //Sell Today
            currStockVal = -1;
        }

        if(i+1 < prices.size() && prices[i+1] > prices[i]){
            currStockVal = prices[i]; //Buy Today
        }
    }

    return profit;
}

int main(){
   
return 0;
}