#include <iostream>
#include<vector>
using namespace std;

int solveUsingRE(int capacity, int wt[], int profit[], int n, int index)
{
    // Base Case
    if (index >= n)
    {   
        //Agr array se bhr chle gye to 0 profit (bcz items hi nhi hai knpsack me dalne ko)
        return 0;
    }
    // Or you can use following Base Case Instead
    //  if(index == n-1){
    //      if(wt[index] <= capacity){
    //          return profit[index];
    //      }
    //      else{
    //          return 0;
    //      }
    //  }

    // Include / Exclude
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingRE(capacity - wt[index], wt, profit, n, index + 1);
    }

    int exclude = 0;
    exclude = 0 + solveUsingRE(capacity, wt, profit, n, index + 1);

    int ans = max(include, exclude);
    return ans;
}

int solveUsingMem(int capacity, int wt[], int profit[], int n, int index, vector<vector<int> >& dp)
{
    // Base Case
    if (index >= n)
    {
        return 0;
    }

    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }

    // Include / Exclude
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, n, index + 1, dp);
    }

    int exclude = 0;
    exclude = 0 + solveUsingMem(capacity, wt, profit, n, index + 1, dp);

    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

//Tabulation
int solveUsingTab(int capacity, int wt[], int profit[], int n, int index){
    vector<vector<int> > dp(capacity + 1, vector<int> (n + 1, -1));

    //Step 2 : Fill initial data
    // int lastCol = n-1;
    for(int row = 0; row <= capacity; row++){
        dp[row][n] = 0; //"n" means out of "wt[]" array index, to agr item hi nhi hai to profit will be 0 no matter what the capacity
    }

    //Step 3
    //RE me capacity : max --> 0 & index : 0 --> n jara tha to yahan opposite krenge
    //Note : capacity <-> row
    //index <-> column
    //Reason? dp bnate vkt hmne "capacity + 1" rows li thi & "n+1" columns
    for(int row = 0; row <= capacity; row++){
        for(int col = n-1; col >= 0; col--){
            int include = 0;
            if (wt[col] <= row)
            {
                include = profit[col] + dp[row - wt[col]][col + 1];
            }

            int exclude = 0;
            exclude = 0 + dp[row][col + 1];

            dp[row][col] = max(include, exclude);
        }
    }

    return dp[capacity][index];
}

//Tabulation Space Optimized - using 2 1D Arrays instead of dp (a 2D array)
int solveUsingTabSO(int capacity, int wt[], int profit[], int n, int index){
    // vector<vector<int> > dp(capacity + 1, vector<int> (n + 1, -1));
    vector<int> next(capacity + 1, -1);
    vector<int> current(capacity + 1, -1);

    //Step 2 : Fill initial data
    for(int row = 0; row <= capacity; row++){
        next[row] = 0; //"n" means out of "wt[]" array index, to agr item hi nhi hai to profit will be 0 no matter what the capacity
    }

    //Step 3
    for(int col = n-1; col >= 0; col--){
        for(int row = 0; row <= capacity; row++){
            int include = 0;
            if (wt[col] <= row)
            {
                include = profit[col] + next[row - wt[col]];
            }

            int exclude = 0;
            exclude = 0 + next[row];

            current[row] = max(include, exclude);
        }

            //Update next[] array
            next = current;
    }

    return current[capacity];
}

//Tabulation Space Optimized 2 - using only single 1D Array
int solveUsingTabSO2(int capacity, int wt[], int profit[], int n, int index){
    vector<int> next(capacity + 1, -1);
    // vector<int> current(capacity + 1, -1);

    //Step 2 : Fill initial data
    for(int row = 0; row <= capacity; row++){
        next[row] = 0; //"n" means out of "wt[]" array index, to agr item hi nhi hai to profit will be 0 no matter what the capacity
    }

    //Step 3
    int temp = 0;
    for(int col = n-1; col >= 0; col--){
        for(int row = capacity; row >= 0; row--){
            int include = 0;
            if (wt[col] <= row)
            {
                include = profit[col] + next[row - wt[col]];
            }

            int exclude = 0;
            exclude = 0 + next[row];

            temp = max(include, exclude);
            
            //Update next[] array
            next[row] = temp;
        }
    }

    return next[capacity];
}

int solveKnapsack(int capacity, int wt[], int profit[], int n)
{
    // Plain RE
    // int index = 0;
    // int ans = solveUsingRE(capacity, wt, profit, n, index);
    // return ans;

    //RE + Mem
    // vector<vector<int> > dp(capacity+1, vector<int> (n+1, -1)); //Rows : capacity + 1; Col : index + 1
    // int index = 0;
    // int ans = solveUsingMem(capacity, wt, profit, n, index, dp);
    // return ans;

    //Tabulation
    // int index = 0;
    // int ans = solveUsingTab(capacity, wt, profit, n, index);
    // return ans;

    //Tabulation SO
    // int index = 0;
    // int ans = solveUsingTabSO(capacity, wt, profit, n, index);
    // return ans;

    //Tabulation SO 2
    int index = 0;
    int ans = solveUsingTabSO2(capacity, wt, profit, n, index);
    return ans;
}

int main()
{
    // int capacity = 0;
    // int wt[] = {10};
    // int profit[] = {60};
    // int n = 1;

    //3 output expected for below testcase
    int capacity = 3;
    int wt[] = {4, 5, 1};
    int profit[] = {1, 2, 3};
    int n = 3;

    int ans = solveKnapsack(capacity, wt, profit, n);
    cout << "Max Profit : " << ans << endl;

    return 0;
}