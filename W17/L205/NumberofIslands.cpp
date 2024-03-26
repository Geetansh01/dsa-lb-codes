#include<bits/stdc++.h>
using namespace std;


//TC : O(m * n) {Given an m x n 2D matrix "grid" in Question}
void dfsTrav(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited){
    visited[row][col] = true;

    int lastCol = grid[row].size();
    int lastRow = grid.size();

    //Check Left, Right, top, bottom of current land
    //Left
    if(col >= 1){
        if(grid[row][col-1] == '1'){
            if(visited[row][col-1] == false){
                dfsTrav(row, col-1, grid, visited);
            }
        }
    }
    // Right
    if(col <= lastCol - 2){
        if(grid[row][col+1] == '1'){
            if(visited[row][col+1] == false){
                dfsTrav(row, col+1, grid, visited);
            }
        }
    }
    //Top
    if(row >= 1){
        if(grid[row-1][col] == '1'){
            if(visited[row-1][col] == false){
                dfsTrav(row-1, col, grid, visited);
            }
        }
    }
    // Bottom
    if(row <= lastRow-2){
        if(grid[row+1][col] == '1'){
            if(visited[row+1][col] == false){
                dfsTrav(row+1, col, grid, visited);
            }
        }
    }
}

//TC : O(m * n) {Given an m x n 2D matrix "grid" in Question}
void bfsTrav(pair<int, int> current, vector<vector<char>>& grid, vector<vector<int>>& visited){
    queue<pair<int, int>> q;
    q.push(current);
    visited[current.first][current.second] = true;

    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();

        int currX = front.first;
        int currY = front.second;

        //Check all 4 directions : top, right, bottom, left
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            
            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[currX].size()){
                if(grid[newX][newY] == '1' && visited[newX][newY] == false){
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }

    }

}

int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    //Note : using 2D array as "visited" & not an "unordered_map" bcz "pair<int, int>" is not hashable by default 
    //I could've also used a std::map (which will take "pair<int, int>" as key) but then the TC would increase!
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int islands = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == '1' && visited[i][j] == false){
                islands++;
                bfsTrav({i, j}, grid, visited);
                // dfsTrav(i, j, grid, visited);
            }
        }
    }

    return islands;
}

int main(){
   
return 0;
}