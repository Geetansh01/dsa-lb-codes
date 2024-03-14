#include<bits/stdc++.h>
using namespace std;

int solveUsingRE(vector<int>& satisfaction, int index, int time){
    //BC
    if(index >= satisfaction.size()) return 0;

    int maxSatisfaction = 0;
    //Option 1 : Make Current Dish
    int option1 = time * satisfaction[index] + solveUsingRE(satisfaction, index + 1, time + 1);

    //Option 2 : Don't Make current Dish, (You must never ignore making a dish with +ve/0 satisfaction rating)
    int option2 = INT_MIN;
    if(satisfaction[index] < 0){
        option2 = 0 +  solveUsingRE(satisfaction, index + 1, time);
    }
    maxSatisfaction = max(option1, option2);

    return maxSatisfaction;
}

int solveUsingMem(vector<int>& satisfaction, int index, int time, vector<vector<int> >& dp){
    //BC
    if(index >= satisfaction.size()) return 0;

    if(dp[index][time] != -1){
        return dp[index][time];
    }

    int maxSatisfaction = 0;
    //Option 1 : Make Current Dish
    int option1 = time * satisfaction[index] + solveUsingMem(satisfaction, index + 1, time + 1, dp);

    //Option 2 : Don't Make current Dish, (You must never ignore making a dish with +ve/0 satisfaction rating)
    int option2 = INT_MIN;
    if(satisfaction[index] < 0){
        option2 = 0 +  solveUsingMem(satisfaction, index + 1, time, dp);
    }
    maxSatisfaction = max(option1, option2);

    dp[index][time] = maxSatisfaction;

    return dp[index][time];
}

int solveUsingTab(vector<int>& satisfaction){
    vector<vector<int> > dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 2, 0));  //row x col :: index x time

    for(int index_i = satisfaction.size() - 1; index_i >= 0; index_i--){
        for(int time_i = satisfaction.size(); time_i >= 1; time_i--){
            int maxSatisfaction = 0;
            //Option 1 : Make Current Dish
            int option1 = time_i * satisfaction[index_i] + dp[index_i + 1][time_i + 1];

            //Option 2 : Don't Make current Dish, (You must never ignore making a dish with +ve/0 satisfaction rating)
            int option2 = INT_MIN;
            if(satisfaction[index_i] < 0){
                option2 = 0 +  dp[index_i + 1][time_i];
            }
            maxSatisfaction = max(option1, option2);

            dp[index_i][time_i] = maxSatisfaction;
        }
    }

    return dp[0][1];
}

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int ans = 0;

    //Plain RE
    // int index = 0;
    // int time = 1;
    // ans = solveUsingRE(satisfaction, index, time);

    //Mem
    // int index = 0;
    // int time = 1;
    // vector<vector<int> > dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1)); //row x col :: index x time
    // ans = solveUsingMem(satisfaction, index, time, dp);

    //Tab
    ans = solveUsingTab(satisfaction);

    return ans;
}

int main(){
   
return 0;
}