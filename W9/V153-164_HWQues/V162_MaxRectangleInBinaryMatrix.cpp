#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*****Q162 : Max Rectangle In Binary Matrix [LeetCode : https://leetcode.com/problems/maximal-rectangle/description/]********/

//This solution is totally based on "Largest Rectangular Area in a histogram [Interview][LeetCode : https://leetcode.com/problems/largest-rectangle-in-histogram/description/] (See L152)"

//Better way to do this Q is using DP

void makeLeftMatrix(vector<vector<int>>& matrix, vector<vector<int> >& A){
    int R = matrix.size();
    int C = matrix[0].size();

    for(int row = 0; row < R; row++){
        stack<int> stk;
        for(int col = 0; col < C; col++){
            int digit = matrix[row][col];
            while(!stk.empty() && (matrix[row][stk.top()]) >= digit){
                stk.pop();
            }
            if(!stk.empty()){
                A[row][col] = stk.top();
            }
            else{
                A[row][col] = -1;
            }
            stk.push(col);
        }
    } 
    return; 
}

void makeRightMatrix(vector<vector<int>>& matrix, vector<vector<int> >& A){
    int R = matrix.size();
    int C = matrix[0].size();

    for(int row = 0; row < R; row++){
        stack<int> stk;
        for(int col = C-1; col >= 0; col--){
            int digit = matrix[row][col];
            while(!stk.empty() && (matrix[row][stk.top()]) >= digit){
                stk.pop();
            }
            if(!stk.empty()){
                A[row][col] = stk.top();
            }
            else{
                A[row][col] = C;
            }
            stk.push(col);
        }
    } 
    return; 
}

int getWidth(int row, int col, vector<vector<int> >& L, vector<vector<int> >& R){
    int right = R[row][col];
    int left = L[row][col];

    return right - left - 1;
}

void transformToHistogram(vector<vector<int>>& matrix){
    int R = matrix.size();
    int C = matrix[0].size();
    
    for(int row = 0; row < R; row++){
        if(row == 0) continue;
        for(int col = 0; col < C; col++){
            if(matrix[row][col] != 0){
                int digitA = matrix[row - 1][col];

                int digitB = matrix[row][col];

                matrix[row][col] = (digitA + digitB);
            }
        }
    }
}

int maximalRectangle(vector<vector<char>>& mx) {
    int R = mx.size();
    int C = mx[0].size();

    vector<vector<int> > matrix(R, vector<int> (C, 0));
    for(int row = 0; row < R; row++){
        for(int col = 0; col < C; col++){
            matrix[row][col] = mx[row][col] - '0';
        }
    }

    transformToHistogram(matrix);

    vector<vector<int> > ColIndexOfZeroToLeft(R, vector<int> (C, 0)); 
    makeLeftMatrix(matrix, ColIndexOfZeroToLeft);   

    vector<vector<int> > ColIndexOfZeroToRight(R, vector<int> (C, 0));
    makeRightMatrix(matrix, ColIndexOfZeroToRight);  

    // for(auto x : matrix){
    //     for(auto y : x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(auto x : ColIndexOfZeroToRight){
    //     for(auto y : x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int MaxRectArea = 0;

    for(int row = 0; row < R; row++){
        for(int col = 0; col < C; col ++){
            int width = getWidth(row , col, ColIndexOfZeroToLeft, ColIndexOfZeroToRight);
            int height = matrix[row][col];
            int area = width * height;
            MaxRectArea = max(MaxRectArea, area);
        }
    }

    return MaxRectArea;
}

int main(){
   vector<vector<char> > matrix = {{'1','0','1','0','0'},
                                {'1','0','1','1','1'},
                                {'1','1','1','1','1'},
                                {'1','0','0','1','0'}};

    cout<<maximalRectangle(matrix);
return 0;
}