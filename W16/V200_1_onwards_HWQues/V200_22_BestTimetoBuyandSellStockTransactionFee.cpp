#include<bits/stdc++.h>
using namespace std;

//Below code copied from "V200_19 : Best Time to Buy and Sell Stock II DP Solution", Just added "-fee" in line___(1)

int solveUsingRE(vector<int>& prices, bool canBuy, int index, int fee){
    //BC
    if(index >= prices.size()) return 0;

    int maxProfit = 0;

    //If you can Buy Today
    if(canBuy){
        //Option1 : Buy Today
        int option1 = -(prices[index]) -fee + solveUsingRE(prices, false, index + 1, fee); //line___(1)

        //Option2 : Don't Buy Today, ignore todays day
        int option2 = 0 + solveUsingRE(prices, true, index + 1, fee);

        maxProfit = max(option1, option2);
    }
    else{
        //Option1 : Sell Today
        int option3 = +(prices[index]) + solveUsingRE(prices, true, index + 1, fee);

        //Option4 : Don't Sell Today, ignore todays day
        int option4 = 0 + solveUsingRE(prices, false, index + 1, fee);

        maxProfit = max(option3, option4);
    }

    return maxProfit;
}

int solveUsingTabSO(vector<int>& prices, int fee){
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
                int option1 = -(prices[index_i]) -fee + next[false];

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
            
            curr[canBuy_i] = maxProfit;
        }

        //Update next
        next = curr;
    }

    // return curr[1]; //Using this I was able to submit on LeetCode but some other questions me gdbd hojati thi so I am making practice to return answer from next[] !
    return next[1];
}

int maxProfit(vector<int>& prices, int fee) {
    int ans = 0;
    
    //Plain RE
    // bool canBuy = true;
    // int index = 0;
    // ans = solveUsingRE(prices, canBuy, index, fee);

    //TabSo [TC : O(n); SC : O(1); n is size of prices[] array]
    ans = solveUsingTabSO(prices, fee); 

    return ans;
}

int main(){
   
return 0;
}