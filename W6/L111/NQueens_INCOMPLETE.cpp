#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char> >& board, int n){
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row, int col, vector<vector<char> >& board, int n){
    //To check if a Queen can be safely placed at current cell(row, col)
    int i = row;
    int j = col;

    //checking row to the left
    while(j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
    }

    i = row;
    j = col;

    //Checking upper Left diagonal
    while(i >=0 && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--; j--;
    }

    i = row;
    j = col;
    //Checking Lower Left diagonal
    while(i < n && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i++; j--;
    }

    //if you have come to this line that means current cell is safe
    return true;
}

void solve(vector<vector<char> >& board, int col, int n){
    //base case : aggr sare columns me queen dal di to now you are outside the column bound
    if(col >= n){
        printSolution(board, n);
        return;
    }

    //Solve 1 case
    for(int row = 0; row<n; row++){
        if(isSafe(row, col, board, n)){
            //Queen rakh do
            board[row][col] = 'Q';
            //Recursive call
            solve(board, col+1, n);
            //backtracing
            board[row][col] = '-';
        }
    }

}

int main(){
   int n = 4;
   vector<vector<char> > board(n, vector<char>(n, '-'));
   int col = 0;
   solve(board, col, n);
return 0;
}