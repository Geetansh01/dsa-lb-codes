#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

//Refer GFG Question : https://www.geeksforgeeks.org/problems/cutted-segments1642/1
//Although the question is not important here but rather how to convert RE to DP solution!

// Given RE code {Assume it satisfies 1)Overlapping Subprblms & 2)Optimal Substructure i.e conditions to use DP }
// Function to find the maximum number of cuts.
// int solveUsingRE(int n, int x, int y, int z)
// {
//     // Base Case
//     if (n < 0)
//         return INT_MIN;
//     if (n == 0)
//         return 0;

//     // Step 2
//     int opt1 = 1 + solveUsingRE(n - x, x, y, z);
//     int opt2 = 1 + solveUsingRE(n - y, x, y, z);
//     int opt3 = 1 + solveUsingRE(n - z, x, y, z);

//     int ans = max(opt1, max(opt2, opt3));
//     return ans;
// }

// // Function to find the maximum number of cuts.
// int maximizeTheCuts(int n, int x, int y, int z)
// {
//     int ans = solveUsingRE(n, x, y, z);
//     return (ans < 0) ? 0 : ans;
// }

// Changed to (RE + memoization)
int solveUsingRE(int n, int x, int y, int z, vector<int> &dp)
{
    // Base Case
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return 0;

    // Step 3
    if (dp[n] != INT_MIN)
    {
        return dp[n];
    }

    // Step 2
    int opt1 = 1 + solveUsingRE(n - x, x, y, z, dp);
    int opt2 = 1 + solveUsingRE(n - y, x, y, z, dp);
    int opt3 = 1 + solveUsingRE(n - z, x, y, z, dp);

    dp[n] = max(opt1, max(opt2, opt3));
    return dp[n];
}

// Function to find the maximum number of cuts.
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN); //(-1) bhi use kr skte hai but INT_MIN makes more sense (See Question)
    int ans = solveUsingRE(n, x, y, z, dp);
    return (ans < 0) ? 0 : ans;
}

int main()
{

    return 0;
}