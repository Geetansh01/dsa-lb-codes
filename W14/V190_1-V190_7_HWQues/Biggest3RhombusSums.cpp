#include<iostream>
#include<queue>
#include<limits.h>
#include<functional>
#include<algorithm>
using namespace std;

/****V190_4 : Get Biggest Three Rhombus Sums in a Grid [LeetCode : https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/]*****/

//Nothing to learn in this Q but writing code is a bit tough for it
//I beat 98% TC with brute force , so brute force is the only answer !?
//Lakshay Bhaiya also did brute force

//My Soln
int getRhomArea(int& Rstart, int& Rend, int& Cstart, int& Cend, vector<vector<int>>& grid){
    int length = Rend - Rstart + 1;
    int mid = Cstart + (length/2);
    int a = mid; int b = mid;
    int RhomSum = 0;
    bool outward = true;
    int row = Rstart;

    while(row <= Rend){
        if(a == b){
            RhomSum += grid[row][a];
        }
        else{
            RhomSum = RhomSum + grid[row][a] + grid[row][b];
        }

        if(a == Cstart && b == Cend) outward = false;

        if(outward){
            b++; a--;
        }
        else{
            b--; a++;
        }

        row++;
    }

    return RhomSum;
}

bool isInHeap(priority_queue<int, vector<int>, greater<int>> minH, int x){
    while(!minH.empty()){
        int temp = minH.top();
        minH.pop();
        if(temp == x) return true;
    }

    return false;
}

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int N = grid.size() - 1;
    int M = grid[0].size() - 1;
    priority_queue<int, vector<int>, greater<int> > minH;
    minH.push(INT_MIN); minH.push(INT_MIN); minH.push(INT_MIN);
    
    int side = 1;
    while(side <= N+1){
        int Rstart = 0; 
        int Rend = Rstart + side -1;

        while(Rend <= N){
            int Cstart = 0;
            int Cend = Cstart + side -1;

            while(Cend <= M){
                int RhomArea = getRhomArea(Rstart, Rend, Cstart, Cend, grid);

                if(RhomArea > minH.top()){
                    if(!isInHeap(minH, RhomArea)){
                        minH.pop();
                        minH.push(RhomArea);
                    }
                }

                Cstart++;
                Cend++;
            }

            Rstart++;
            Rend++;
        }

        side += 2;
    }

    vector<int> ans;
    while(!minH.empty()){
        int temp = minH.top();
        minH.pop();
        if(temp != INT_MIN){
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end(), greater<int>());
    return ans;
}

//Lakshay Bhaiya's Soln (Also Brute Force, nothing to learn)
// bool checkPointsInGrid(vector<pair<int, int>>& corners, vector<vector<int>>& grid){
//     int row = grid.size();
//     int col = grid[0].size();
//     for(auto& c : corners){
//         int x = c.first; //x coordinate
//         int y = c.second; 
//         if(x < 0 || x >= row || y < 0 || y >= col) return false;
//     }
//     return true;
// }

// bool getCorners(vector<vector<int>>& grid, vector<pair<int, int>>& corners, pair<int, int>& centre, int delta){
//     //Corners of Rhombus A B C D (Clockwise from top)
//     pair<int, int> A(centre.first-delta, centre.second);
//     pair<int, int> B(centre.first, centre.second+delta);
//     pair<int, int> C(centre.first+delta, centre.second);
//     pair<int, int> D(centre.first, centre.second-delta);

//     corners[0] = A;
//     corners[1] = B;
//     corners[2] = C;
//     corners[3] = D;

//     if(checkPointsInGrid(corners, grid)){
//         return true;
//     }
//     return false;
// }

// void getAllRhomSum(vector<vector<int>>& grid, int i, int j, priority_queue<int>& pq){
//     //Push 1x1 rhombus sum (i.e the cell itself)
//     pq.push(grid[i][j]);

//     int delta = 1;
//     vector<pair<int, int>> corners(4); //Will store corners of Rhombus A, B, C, D
//     pair<int, int> centre = {i, j};
//     while(getCorners(grid, corners, centre, delta)){
//         pair<int, int>& A = corners[0];
//         pair<int, int>& B = corners[1];
//         pair<int, int>& C = corners[2];
//         pair<int, int>& D = corners[3];

//         int sum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

//         //Sum of cells B/w A to B
//         for(int i = 1; i < (B.first - A.first); i++){
//             sum += grid[A.first + i][A.second + i];
//         }

//         //Sum of cells B/w B to C
//         for(int i = 1; i < (C.first - B.first); i++){
//             sum += grid[B.first + i][B.second - i];
//         }

//         //Sum of cells B/w C to D
//         for(int i = 1; i < (C.first - D.first); i++){
//             sum += grid[C.first - i][C.second - i];
//         }

//         //Sum of cells B/w D to A
//         for(int i = 1; i < (D.first - A.first); i++){
//             sum += grid[D.first - i][D.second + i];
//         }
        
//         pq.push(sum); //Pushed Rhombus sum
//         delta++; 
//     }
// }

// bool isDistinct(int top, vector<int>& ans){
//     for(auto& num : ans){
//         if(num == top) return  false;
//     }
//     return true;
// }

// vector<int> getBiggestThree(vector<vector<int>>& grid) {
//     priority_queue<int> pq; //maxH
//     int row = grid.size();
//     int col = grid[0].size();

//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < col; j++){
//             getAllRhomSum(grid, i, j, pq);
//         }
//     }

//     vector<int> ans;
//     while(!pq.empty() && ans.size() < 3){
//         int top = pq.top();
//         pq.pop();
//         if(isDistinct(top, ans)){
//             ans.push_back(top);
//         }
//     }

//     return ans;

// }

int main(){
   vector<vector<int> > grid = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
   vector<int> ans = getBiggestThree(grid);

   for(auto x : ans){
    cout<<x<<" ";
   }

return 0;
}
