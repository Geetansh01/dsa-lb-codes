#include<iostream>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;


int solveUsingRE(int n){
    //BC
    if(n == 1) return 1;
    if(n == 0) return 0;

    int ans  = INT_MAX;
    int sqrtn = sqrt(n);
    for(int i = 1; i <= sqrtn; i++){
        ans = min(ans, 1 + solveUsingRE(n - i*i));
    }
    return ans;
}

int solveUsingMem(int n, vector<int>& dp){
    //BC
    if(n == 1) return 1;
    if(n == 0) return 0;

    if(dp[n] != -1){
        return dp[n];
    }

    int ans  = INT_MAX;
    int sqrtn = sqrt(n);
    for(int i = 1; i <= sqrtn; i++){
        ans = min(ans, 1 + solveUsingMem(n - i*i, dp));
    }
    dp[n] = ans;

    return dp[n];
}

int solveUsingTab(int n){
    vector<int> dp(n+2, -1);

    dp[1] = 1;
    dp[0] = 0;

    for(int n_index = 2; n_index <= n; n_index++){
        int ans  = INT_MAX;
        int sqrtn = sqrt(n_index);
        for(int i = 1; i <= sqrtn; i++){
            ans = min(ans, 1 + dp[n_index - i*i]);
        }
        dp[n_index] = ans;
    }

    return dp[n];

}

int numSquares(int n) {
    int ans;
    
    //Plain RE
    //TC : O(sqrt(n)^n) i.e O(n^n) (Compare with Fibonacci)
    //SC : O(n) (Compare with Fibonacci)
    // ans = solveUsingRE(n);

    //Mem
    //TC/SC : See Tabulation
    // vector<int> dp(n+2, -1);
    // ans = solveUsingMem(n, dp);

    //Tab
    //TC : O(n*sqrt(n)) {This is NOT equal to O(n)!}
    //SC : O(n) 
    ans = solveUsingTab(n);

    return ans;
}

int main(){
   
return 0;
}