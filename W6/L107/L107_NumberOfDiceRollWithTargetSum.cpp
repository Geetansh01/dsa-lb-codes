#include<iostream>
using namespace std;
/*****************107 : Number Of Dice Roll With Target Sum[LeetCode : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/]*******************************/
//TLE marega ye soln (TC : O(K^N); SC : O(N))
void helperRE(int n, int& k, int& target, int& ans, int sum){
    //Base Case
    if(n == 0){
        if(sum == target){
            ans++; return;
        }
        else return;
    }

    //Solve 1 case
    for(int i = 1; i <= k;  i++){
        helperRE(n-1, k, target, ans, sum + i);
    }
}

int numRollsToTarget(int n, int k, int target) {
    int ans = 0;
    int sum = 0;
    helperRE(n, k, target, ans, sum);
    return ans;   
}

int main(){
    int n = 2; 
    int k = 6;
    int target = 7;
    cout<<numRollsToTarget(n, k , target);
   
return 0;
}