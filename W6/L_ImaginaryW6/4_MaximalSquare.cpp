#include<bits/stdc++.h>
using namespace std;

//Plain RE (will give TLE)
int solveRE(vector<vector<char>>& matrix, int i, int j, int& row, int& col, int& maxi){
    //Base Case
    if(i >= row || j >= col) return 0;
    
    //Explore all 3 directions
    int right = solveRE(matrix, i, j+1, row, col, maxi);
    int lowerRightDiagonal = solveRE(matrix, i+1, j+1, row, col, maxi);
    int down = solveRE(matrix, i+1, j, row, col, maxi);
    
    //Check of we are standing on a 1 (i.e can we build a square from current position)
    if(matrix[i][j] == '1'){
        int ans = 1 + min(right, min(lowerRightDiagonal, down));
        maxi = max(ans, maxi);
        return ans;
    }
    else{
        //Agr 0 pe khade ho to no square
        return 0;
    }
}

//RE + Mem (TC : O(n*m)); 
//n = no of rows in matrix
//m = no of cols in matrix
int solveMem(vector<vector<char>>& matrix, int i, int j, int& row, int& col, int& maxi, vector<vector<int> >& dp){
    //Base Case
    if(i >= row || j >= col) return 0;
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //Explore all 3 directions
    int right = solveMem(matrix, i, j+1, row, col, maxi, dp);
    int lowerRightDiagonal = solveMem(matrix, i+1, j+1, row, col, maxi, dp);
    int down = solveMem(matrix, i+1, j, row, col, maxi, dp);
    
    //Check of we are standing on a 1 (i.e can we build a square from current position)
    if(matrix[i][j] == '1'){
        int ans = 1 + min(right, min(lowerRightDiagonal, down));
        maxi = max(ans, maxi);

        dp[i][j] = ans;
        return ans;
    }
    else{
        //Agr 0 pe khade ho to no square
        dp[i][j] = 0;
        return 0;
    }
}

int maximalSquare(vector<vector<char>>& matrix) {
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;

    //Plain RE
    // solveRE(matrix, i, j, row, col, maxi);

    //Mem
    vector<vector<int> > dp(row, vector<int>(col, -1) ); // cell (i, j) --> Largest Square with this cell as top left corner
    solveMem(matrix, i, j, row, col, maxi, dp);

    
    return maxi * maxi;
}

int main(){
   
return 0;
}