#include<iostream>
#include<limits.h>
#include<map>
#include<vector>
using namespace std;

/*****Minimum Cost Tree From Leaf Values [LeetCode : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/]******/

int solveUsingRE(vector<int>& arr, map<pair<int, int>, int>& maxi, int start, int end){
    //Base Case
    if(start > end){
        //Invalid Range
        return 0;
    }
    if(start == end){
        //Leaf Node
        return 0;
    }

    int ans = INT_MAX;
    //Now do all the partitionings, we will use i for that
    for(int i = start; i < end; i++){
        int currProduct = maxi[{start, i}] * maxi[{i+1, end}]; //current Partitions Ki Max Leaf Nodes Ka Product
        ans = min(ans, currProduct 
                        + solveUsingRE(arr, maxi, start, i) 
                        + solveUsingRE(arr, maxi, i+1, end));
    }

    return ans;
}

int solveUsingMem(vector<int>& arr, map<pair<int, int>, int>& maxi, int start, int end,  vector<vector<int> >& dp){
    //Base Case
    if(start > end){
        //Invalid Range
        return 0;
    }
    if(start == end){
        //Leaf Node
        return 0;
    }

    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int ans = INT_MAX;
    //Now do all the partitionings, we will use i for that
    for(int i = start; i < end; i++){
        int currProduct = maxi[{start, i}] * maxi[{i+1, end}]; //current Partitions Ki Max Leaf Nodes Ka Product
        ans = min(ans, currProduct 
                        + solveUsingMem(arr, maxi, start, i, dp) 
                        + solveUsingMem(arr, maxi, i+1, end, dp));
    }

    dp[start][end] = ans;
    return dp[start][end];
}

//Tabulation
int solveUsingTab(vector<int>& arr, map<pair<int, int>, int>& maxi){
    int n = arr.size();
    vector<vector<int> > dp(n+2, vector<int>(n+1, 0)); //row x col :: start x end

    //Fill initial data : done by already initialising dp with 0

    //To be precise, u can start "start_index = n-2" (Submit hogya isse bhi) but itna kyu sochna :p
    //Simply take "start_index" from n to 0
    for(int start_index = n; start_index >= 0; start_index--){
        for(int end_index = 0; end_index <= n-1; end_index++){
            
            //Below cases ke liye loop nhi chlana (See base cases above)
            if(start_index > end_index){
                //Invalid Range
                continue;
            }
            if(start_index == end_index){
                //Leaf Node
                continue;
            }
            
            int ans = INT_MAX;
            //Now do all the partitionings, we will use i for that
            for(int i = start_index; i < end_index; i++){
                int currProduct = maxi[{start_index, i}] * maxi[{i+1, end_index}]; //current Partitions Ki Max Leaf Nodes Ka Product
                ans = min(ans, currProduct 
                                + dp[start_index][i] 
                                + dp[i+1][end_index]);
            }

            dp[start_index][end_index] = ans;
        }
    }

    return dp[0][n-1];
}

int mctFromLeafValues(vector<int>& arr) {
    //Precomputation : precompute all "max" values for all partitions
    //Using map & not unordered_map bcz unordered_map ke liye i will need to provide my own hash function for std::pair as key
    map<pair<int, int>, int> maxi; //range ---> max value for that range

    for(int i = 0; i < arr.size(); i++){
        maxi[{i, i}] = arr[i];
        for(int j = i + 1; j < arr.size(); j++){
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }

    //Plain RE
    // int start = 0;
    // int end = arr.size() - 1;
    // int ans = solveUsingRE(arr, maxi, start, end);
    // return ans;
    
    //RE+Mem
    // int n = arr.size();
    // int start = 0;
    // int end = n - 1;
    // vector<vector<int> > dp(n+1, vector<int>(n+1, -1)); //row x col :: start x end
    // int ans = solveUsingMem(arr, maxi, start, end, dp);
    // return ans;

    //RTabulation
    int ans = solveUsingTab(arr, maxi);
    return ans;
    }

int main(){
   
return 0;
}