#include<iostream>
using namespace std;

/****************Climbing Stairs[LeetCode : https://leetcode.com/problems/climbing-stairs/]**********************/

//M1 : Unoptimised Recursive (TC : Exponential, Gives TLE on LeetCode)
int climbStairs(int n) {
    //Base case
    if(n == 0) return 1; 
    //0th stair pe pohchne ka 1 way hai (0th stair pe pohchne ke 0 way isliye nhi hai bcz that would mean ki tum 0th stair pe phuch hi ni skte but phuch to tum gye as you are standing there)
    if(n == 1) return 1;
    
    return (climbStairs(n-1) + climbStairs(n-2));
}

int main(){
   cout<<climbStairs(2);
return 0;
}