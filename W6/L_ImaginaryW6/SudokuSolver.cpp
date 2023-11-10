#include<iostream>
#include<vector>
using namespace std;

/*********************Sudoku Solver [LeetCode : https://leetcode.com/problems/sudoku-solver/description/]********************************/
//TC : Exponential (O(9^m) ; m = No of Empty Cells)
//SC : O(1) ; Max depth in call stack can be 81 for a 9x9 sudoku when all the cells are empty
bool isSafe(int i, int j, char digit, vector<vector<char>>& board){
    //Check whole row for "digit"
    for(int col = 0; col < 9; col++){
        if(board[i][col] == digit){
            return false;
        }

    }

    for(int row = 0; row < 9; row++){
        if(board[row][j] == digit){
            return false;
        }
    }

    //Now checking the 3*3 box of cell(i, j) if it contains "digit"
    int row = i - (i%3);
    int col = j - (j%3);
    for(int r = row; r < row+3; r++){
        for(int c = col; c < col+3; c++){
            if(board[r][c] == digit){
                return false;
            }
        }
    }

    //Agr upr kahin "false" return nhi hua to Safe hai rkhna
    return  true;
}

void solveHelper(int i, int j, bool& puzzle_solved, vector<vector<char>>& board){
    //Base Case
    if(i >= 9){
        puzzle_solved = true;
        return;
    }

    //If current cell already filled then go to the next
    if(board[i][j] != '.'){
        if(j+1 >= 9){
            solveHelper(i+1, 0, puzzle_solved, board);
        }
        else{
            solveHelper(i, j+1, puzzle_solved, board);
        }

    }
    else{
        for(int num = 1; num <= 9; num++){
            char digit = num - 1 + '1';

            //Is it safe to place "digit" on cell(i, j)
            if(isSafe(i, j, digit, board)){
                //rkh do
                board[i][j] = digit;

                //Recursive Call
                    if(j+1 >= 9){
                        solveHelper(i+1, 0, puzzle_solved, board);
                    }
                    else{
                        solveHelper(i, j+1, puzzle_solved, board);
                    }

                //kya puzzle_solved true hai?
                if(puzzle_solved == true){
                    return;
                }
                else{
                    //Backtrack
                    board[i][j] = '.';
                }
            }
        }
    }

}

void solveSudoku(vector<vector<char>>& board) {
    int i = 0;
    int j = 0;
    bool puzzle_solved = false;
    solveHelper(i, j, puzzle_solved, board);
    return;
}

int main(){
   vector<vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

   solveSudoku(board);

   for(auto iter : board){
    for(auto j : iter){
        cout<<j<<" ";
    }
    cout<<endl;
   }


return 0;
}