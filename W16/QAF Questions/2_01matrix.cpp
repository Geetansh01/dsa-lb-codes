#include<bits/stdc++.h>
using namespace std;

//Ref: "https://leetcode.com/problems/01-matrix/solutions/1369741/c-java-python-bfs-dp-solutions-with-picture-clean-concise-o-1-space"

//Top Down Recursive Solution (with Memoization)(See above "Ref" for Bottom Up solution)
//Goes bottom right -> top left
int solveREA(int r, int c, vector<vector<int>>& mat, vector<vector<int>>& ans, vector<vector<bool>>& ansAlreadyComputed){
    int Row = mat.size();
    int Col = mat[0].size();
    int INF = Row + Col; // The distance of cells is up to (Row+Col)

    //BC
    if(r < 0 || c < 0) return INF;

    //DP Step (Dynamic Programming)
    if(ansAlreadyComputed[r][c] == true){
        return ans[r][c];
    }

    int top = solveREA(r-1, c, mat, ans, ansAlreadyComputed);
    int left = solveREA(r, c-1, mat, ans, ansAlreadyComputed);
    if(mat[r][c] == 0){
        ansAlreadyComputed[r][c] = true;
        ans[r][c] = 0;
        return 0;
    }
    int mini = (min(top, left) == INF ? INF : min(top, left));
    ansAlreadyComputed[r][c] = true;
    ans[r][c] = mini+1;
    return ans[r][c];
}

//Goes top left -> bottom right
int solveREB(int r, int c, vector<vector<int>>& mat, vector<vector<int>>& ans, vector<vector<bool>>& ansAlreadyComputed){
    int Row = mat.size();
    int Col = mat[0].size();
    int INF = Row + Col; // The distance of cells is up to (Row+Col)

    //BC
    if(r >= Row || c >= Col) return INF;

    //DP Step (Dynamic Programming)
    if(ansAlreadyComputed[r][c] == true){
        return ans[r][c];
    }

    int bottom = solveREB(r+1, c, mat, ans, ansAlreadyComputed);
    int right = solveREB(r, c+1, mat, ans, ansAlreadyComputed);
    if(mat[r][c] == 0){
        ansAlreadyComputed[r][c] = true;
        ans[r][c] = 0;
        return 0;
    }
    int mini = (min(bottom, right) == INF ? INF : min(bottom, right));
    ansAlreadyComputed[r][c] = true;
    ans[r][c] = min(ans[r][c], mini+1);
    return ans[r][c];
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int Row = mat.size();
    int Col = mat[0].size();
    int INF = Row + Col; // The distance of cells is up to (Row+Col)

    //RE
    vector<vector<int>> ans(Row, vector<int>(Col, -1));
    vector<vector<bool>> ansAlreadyComputed(Row, vector<bool>(Col, false)); // [row][col] -> ans already computed for this cell or not 
    // "ansAlreadyComputed[][]" combined with "ans[][]" acts as the DP storage 

    solveREA(Row-1, Col-1, mat, ans, ansAlreadyComputed);

    //Reset ansAlreadyComputed[][]
    for(int r = 0; r < Row; r++){
        for(int c = 0; c < Col; c++){
            ansAlreadyComputed[r][c] = false;
        }
    }
    
    solveREB(0, 0, mat, ans, ansAlreadyComputed);

    return ans;
}

int main(){

return 0;
}