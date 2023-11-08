#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*********************N Queens [LeetCode : https://leetcode.com/problems/n-queens/description/]****************************/
//Logic same but minor changes to below code while submitting on leetcode (as it's not asking to print the solution but return a " vector<vector<string>> ")

void printSolution(vector<vector<char> >& board, int n){
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

//Unoptimised isSafe() [TC : O(n)]
// bool isSafe(int row, int col, vector<vector<char> >& board, int n){
//     //To check if a Queen can be safely placed at current cell(row, col)
//     int i = row;
//     int j = col;

//     //checking row to the left
//     while(j >= 0){
//         if(board[i][j] == 'Q'){
//             return false;
//         }
//         j--;
//     }

//     i = row;
//     j = col;

//     //Checking upper Left diagonal
//     while(i >=0 && j >= 0){
//         if(board[i][j] == 'Q'){
//             return false;
//         }
//         i--; j--;
//     }

//     i = row;
//     j = col;
//     //Checking Lower Left diagonal
//     while(i < n && j >= 0){
//         if(board[i][j] == 'Q'){
//             return false;
//         }
//         i++; j--;
//     }

//     //if you have come to this line that means current cell is safe
//     return true;
// }


//Optimised isSafe() using unordered_map [TC : O(1)]
bool isSafe(int row, int col, vector<vector<char> >& board, int n, unordered_map<int, bool> &rowChk, unordered_map<int, bool>& upper_left_diagonal_Chk, unordered_map<int, bool>& lower_left_diagonal_Chk){
    //checking row to the left
    if(rowChk[row] == true)
        return false;
    if(upper_left_diagonal_Chk[col-row] == true)
        return false;
    if(lower_left_diagonal_Chk[row+col] == true)
        return false;
    
    //if none of the above triggered then return true
    return true;
}


void solveHelper(vector<vector<char> >& board, int col, int n, unordered_map<int, bool> &rowChk, unordered_map<int, bool>& upper_left_diagonal_Chk, unordered_map<int, bool>& lower_left_diagonal_Chk){
    //base case : aggr sare columns me queen dal di to now you are outside the column bound
    if(col >= n){
        printSolution(board, n);
        return;
    }

    //Solve 1 case
    for(int row = 0; row<n; row++){
        if(isSafe(row, col, board, n, rowChk, upper_left_diagonal_Chk, lower_left_diagonal_Chk)){
            //Queen rakh do
            board[row][col] = 'Q';
            rowChk[row] = true;
            lower_left_diagonal_Chk[row + col] = true;
            upper_left_diagonal_Chk[col-row] = true;

            //Recursive call
            solveHelper(board, col+1, n, rowChk, upper_left_diagonal_Chk, lower_left_diagonal_Chk);
            //backtracing
            board[row][col] = '-';
            rowChk[row] = false;
            lower_left_diagonal_Chk[row + col] = false;
            upper_left_diagonal_Chk[col-row] = false;
        }
    }

}

void solve(vector<vector<char> >& board, int col, int n){
    unordered_map<int, bool> rowChk;
    unordered_map<int, bool> upper_left_diagonal_Chk;
    unordered_map<int, bool> lower_left_diagonal_Chk;

    solveHelper(board, col, n, rowChk, upper_left_diagonal_Chk, lower_left_diagonal_Chk);

}

int main(){
   int n = 4;
   vector<vector<char> > board(n, vector<char>(n, '-'));
   int col = 0;
   solve(board, col, n);
return 0;
}