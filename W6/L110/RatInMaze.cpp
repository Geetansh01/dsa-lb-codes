#include<iostream>
#include<vector>
using namespace std;

/************************Rat in a Maze Problem - I[GFG : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1]******************************************/
//TC : O(4^(m*n)) (m and n are the dimensions of the maze) (Exponential)
//SC : O(m*n)
    bool isSafe(int x, int y, int row, int col, vector<vector<int>> &arr, vector<vector<bool> > &visited){
        if(((x >= 0 && x <  row) && (y >= 0 && y <  col)) && (arr[x][y] == 1) && (visited[x][y] == false)){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solveMaze(vector<vector<int>> &arr, int& row, int& col, int i, int j, vector<vector<bool> > &visited, vector<string> &paths, string output){
        //base case
        if(i == row - 1 && j == col - 1){
            //answer found
            paths.push_back(output);
            return;
        }
    
        //Going Down
        if(isSafe(i+1, j, row, col, arr, visited)){
            visited[i+1][j] = true;
            solveMaze(arr, row, col, i+1, j, visited, paths, output + 'D');
            //backTracking Step
            visited[i+1][j] = false;
        }
    
        //Going Left
        if(isSafe(i, j-1, row, col, arr, visited)){
            visited[i][j-1] = true;
            solveMaze(arr, row, col, i, j-1, visited, paths, output + 'L');
            //backTracking Step
            visited[i][j-1] = false;
        }
    
        //Going Right
        if(isSafe(i, j+1, row, col, arr, visited)){
            visited[i][j+1] = true;
            solveMaze(arr, row, col, i, j+1, visited, paths, output + 'R');
            //backTracking Step
            visited[i][j+1] = false;
        }
    
        //Going Up
        if(isSafe(i-1, j, row, col, arr, visited)){
            visited[i-1][j] = true;
            solveMaze(arr, row, col, i-1, j, visited, paths, output + 'U');
            //backTracking Step
            visited[i-1][j] = false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        int row = n;
        int col = n;
        
        vector<string> paths;
        
        if(maze[0][0] == 0){
            //No paths exist, return empty list
            return paths;
        }
        
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        //Mark Source value Visited
        visited[0][0] = true;
        
        
        string output = "";
        solveMaze(maze, row, col, 0, 0, visited, paths, output);
        
        return  paths;
    }


int main(){
   vector<vector<int> > maze{
    {1,0,0},
    {1,1,0},
    {1,1,1}};
    int row = 3;
    int col = 3;

    vector<string> answers = findPath(maze, row);

    if(answers.size() == 0){
        cout<<"No Paths Exist"<<endl;
    }
    else{
        cout<<"Possible Paths are :"<<endl;
        for(auto iter : answers){
            cout<<iter<<" ";
        }
    }

return 0;
}