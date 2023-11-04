#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

/*********************L106 : Minimum Cost For Tickets [LeetCode : https://leetcode.com/problems/minimum-cost-for-tickets/]*********************************/
//TLE Marega ye solution (TC : O(3^N) i.e Exponential ; SC : O(N) i.e Linear)
int helperRE(vector<int>& days, int di, vector<int>& costs){
    //Base Case
    if(di >= days.size()){
        return 0;
    }

    //Solve 1 case
    int ans = INT_MAX;
    for(int i = 0; i < costs.size(); i++){
        
        if(i == 0){
            int next_day = days[di] + 1;
            int j = 0;
            while( j < days.size() && days[j] < next_day){j++;}
            ans = min(ans, helperRE(days, j, costs) + costs[i]);
        }
        else if(i == 1){
            int next_day = days[di] + 7;
            int j = 0;
            while( j < days.size() && days[j] < next_day){j++;}
            ans = min(ans, helperRE(days, j, costs) + costs[i]);
        }
        else if(i == 2){
            int next_day = days[di] + 30;
            int j = 0;
            while( j < days.size() && days[j] < next_day){j++;}
            ans = min(ans, helperRE(days, j, costs) + costs[i]);
        }
    }

    return ans;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int di = 0; //Index for days array
    return helperRE(days, di, costs);
}

int main(){
   vector<int> days = {1,4,6,7,8,20};
   vector<int> costs = {2,7,15};
   cout<<"Answer :"<<mincostTickets(days, costs);
return 0;
}