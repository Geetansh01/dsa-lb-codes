#include<iostream>
#include<limits.h>
using namespace std;

/************************105. Perfect Squares[LeetCode : https://leetcode.com/problems/perfect-squares/description/]*****************************/
//Below soln will give TLE (DP needed)
int numSquares(int n) {
    //Base Case
    if(n == 0){
        return 0;
    }  

    //Solve 1 Case
    int ans = INT_MAX;
    int i = 1; //i will be the numbers where ( i*i <= n)
    while(i*i <= n){
        int a = numSquares(n - i*i);
        ans = min(a, ans);
        i++;
    }
    return ans+1;

}

int main(){
   cout<<numSquares(12)<<endl;
return 0;
}