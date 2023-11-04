#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*****************************Rotate Image [LeetCode : https://leetcode.com/problems/rotate-image/description/]**************************************************/
void transpose(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for(int r = 0; r < row-1; r++){
        for(int c = r+1; c < col; c++){
            swap(matrix[r][c], matrix[c][r]);
            
            /*You can also implement your own swap()
            int t1 = matrix[r][c];
            int t2 = matrix[c][r];
            matrix[r][c] = t2;
            matrix[c][r] = t1;
            */
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    int row = matrix.size();
    int col = matrix[0].size();
    
    for(int r = 0; r < row; r++){
        reverse(matrix[r].begin(), matrix[r].end());
    }
}

int main(){
    vector<vector<int> > matrix{{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);

    for(int i = 0; i < matrix.size(); i++){
        for(int c = 0; c < matrix.size(); c++){
            cout<<matrix[i][c];
        }
        cout<<endl;
    }   
return 0;
}