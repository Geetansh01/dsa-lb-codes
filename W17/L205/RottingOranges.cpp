#include<bits/stdc++.h>
using namespace std;

//M1 : BFS
//TC : O(m * n)
int bfs(vector<vector<int>>& myGrid, queue< pair<pair<int, int>, int>>& q){
    int totalRottingTime = 0;

    while(!q.empty()){
        auto fNode = q.front();
        q.pop();

        int currRow = fNode.first.first;
        int currCol = fNode.first.second;
        int currTime = fNode.second;
        totalRottingTime = max(currTime, totalRottingTime);

        vector<int> dx = {0, +1, 0, -1}; //Col
        vector<int> dy = {-1, 0, +1, 0}; //Row

        for(int i = 0; i < 4; i++){
            int newRow = currRow + dy[i];
            int newCol = currCol + dx[i];

            if(newRow >= 0 && newRow < myGrid.size() && newCol >= 0 && newCol < myGrid[0].size()){
                if(myGrid[newRow][newCol] == 1 ){
                    q.push({{newRow, newCol}, currTime + 1});
                    myGrid[newRow][newCol] = 2;
                }
            }
        }
    }

    return totalRottingTime;
}

int orangesRotting(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> myGrid = grid;
    
    queue< pair<pair<int, int>, int>> q; //{coordinate of orange{Row x Col}, time of rotting}

    //Push all rotten oranges into the queue
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(myGrid[i][j] == 2){
                q.push({{i, j}, 0});
            }
        }
    }

    //start BFS traversal (Start the rotting process)
    int totalRottingTime = bfs(myGrid, q);

    //Check if any fresh oranges left EVEN after the rotting process is completed
    //Note : Below loops can be skipped by counting fresh oranges in above loop, counting rotten ones in "bfs()" & then directly checking if any fresh ones remain in the end
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(myGrid[i][j] == 1){
                return -1;
            }
        }
    }

    return totalRottingTime;
}


// M2 : My Solution (Also BFS)
// //TC : O( (m*n)*(m*n) ) 

// //My Logic : For each fresh orange, find it's shortest distance (i.e time) from the (nearest) rotten orange {So, i am doing BFS for each fresh orange}. Fresh orange with the highest time is the time it takes all the oranges to rot!
// //How? : Consider the case where the entire m*n grid is filled with fresh oranges

// int bfs(pair<int, int> current, vector<vector<int>>& myGrid){   
//     int row = myGrid.size();
//     int col = myGrid[0].size();
//     vector<vector<int>> visited(row, vector<int>(col, 0));

//     int shortestMinutesToRottenOrange = 0;
//     pair<int, int> separator = {INT_MAX, INT_MAX};

//     queue<pair<int, int>> q;
//     q.push(current);
//     q.push(separator);
//     visited[current.first][current.second] = true;

//     bool rottenOrangeReached = false;
//     while(!q.empty()){
//         pair<int, int> fNode = q.front();
//         q.pop();

//         if(fNode == separator){
//             shortestMinutesToRottenOrange++;
//             if(rottenOrangeReached){
//                 return shortestMinutesToRottenOrange;
//             }
            
//             if(!q.empty()){
//                 q.push(separator);
//             }
//         }
//         else{
//             int currRow = fNode.first;
//             int currCol = fNode.second;

//             vector<int> dx = {0, +1, 0, -1};
//             vector<int> dy = {-1, 0, +1, 0};

//             for(int i = 0; i < 4; i++){
//                 int newRow = currRow + dy[i];
//                 int newCol = currCol + dx[i];

//                 if(newRow >= 0 && newRow < myGrid.size() && newCol >= 0 && newCol < myGrid[0].size()){
//                     if(myGrid[newRow][newCol] != 0 && visited[newRow][newCol] == false){
//                         if(myGrid[newRow][newCol] == 2){
//                             rottenOrangeReached = true;
//                         }
                
//                         q.push({newRow, newCol});
//                         visited[newRow][newCol] = true;
//                     }
//                 }
//             }
//         }
//     }
    
//     return INT_MAX;
// }

// int orangesRotting(vector<vector<int>>& grid) {
//     int row = grid.size();
//     int col = grid[0].size();

//     vector<vector<int>> myGrid = grid;

//     int minutes = 0;
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < col; j++){
//             if(myGrid[i][j] == 1){
//                 minutes = max(minutes, bfs({i, j}, myGrid) );
//             }
//         }
//     }
    
//     if(minutes == INT_MAX){
//         return -1;
//     }
//     else{
//         return minutes;
//     }
// }

int main(){
   
return 0;
}