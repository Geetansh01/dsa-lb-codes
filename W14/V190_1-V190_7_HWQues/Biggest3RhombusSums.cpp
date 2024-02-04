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

int main(){
   vector<vector<int> > grid = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
   vector<int> ans = getBiggestThree(grid);

   for(auto x : ans){
    cout<<x<<" ";
   }

return 0;
}
