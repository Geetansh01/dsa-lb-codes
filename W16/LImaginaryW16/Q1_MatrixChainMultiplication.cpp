#include<bits/stdc++.h>
using namespace std;

//RE Pattern : P/MI or MCM Pattern (See "L199 : 1)Guess Number Higher or Lower II")
//Soln reference/basic theory from Striver (https://youtu.be/vRVfmbCFW7Y?si=94XmWJ-MGE_Nfjyr)

class Info{
    public:
    int row; //resultant matrix rows
    int col; //resultant matrix columns
    int operations;

    Info(int r, int c, int o){
        this->row = r;
        this->col = c;
        this->operations = o;
    }
};

Info solveUsingRE(int* arr, int start, int end){
    //BC
    if(end - start + 1 == 2){
        //You have a single matrix
        int row = arr[start];
        int col = arr[end];
        int ops = 0;
        Info temp(row, col, ops);
        return temp;
    }

    int minOpsNeeded = INT_MAX;
    for(int i = start + 1; i < end; i++){
        Info leftPartitionAnswer = solveUsingRE(arr, start, i);
        Info rightPartitionAnswer = solveUsingRE(arr, i, end);

        int currentOps = leftPartitionAnswer.operations + rightPartitionAnswer.operations + (leftPartitionAnswer.row * arr[i] * rightPartitionAnswer.col);
        minOpsNeeded = min(minOpsNeeded, currentOps);
    }

    Info temp(arr[start], arr[end], minOpsNeeded);
    return temp;
}

Info solveUsingMem(int* arr, int start, int end, vector<vector<Info> >& dp){
    //BC
    if(end - start + 1 == 2){
        //You have a single matrix
        int row = arr[start];
        int col = arr[end];
        int ops = 0;
        Info temp(row, col, ops);
        return temp;
    }

    if(dp[start][end].row != 0){
        //Means dp has an answer stored
        return dp[start][end];
    }

    int minOpsNeeded = INT_MAX;
    for(int i = start + 1; i < end; i++){
        Info leftPartitionAnswer = solveUsingMem(arr, start, i, dp);
        Info rightPartitionAnswer = solveUsingMem(arr, i, end, dp);

        int currentOps = leftPartitionAnswer.operations + rightPartitionAnswer.operations + (leftPartitionAnswer.row * arr[i] * rightPartitionAnswer.col);
        minOpsNeeded = min(minOpsNeeded, currentOps);
    }

    Info temp = Info(arr[start], arr[end], minOpsNeeded);
    dp[start][end] = temp;
    return dp[start][end];
}

Info solveUsingTab(int* arr, int start, int end){
    int n = end;

    Info temp(0, 0, 0);
    vector<vector<Info> > dp(n+1, vector<Info>(n+1, temp));

    //Fill initial data
    for(int s_index = 0; s_index <= n; s_index++){
        for(int e_index = 0; e_index <= n; e_index++){
            auto& temp = dp[s_index][e_index];
            if(e_index - s_index + 1 == 2){
                // cout<<"Row : "<<arr[s_index]<<endl;
                //You have a single matrix
                temp.row = arr[s_index];
                temp.col = arr[e_index];
                temp.operations = 0;
            }
        }
    }


    for(int s_index = n; s_index >= 0; s_index--){
        for(int e_index = 0; e_index <= n; e_index++){
            
            if(s_index >= e_index) continue;

            if((dp[s_index][e_index]).row != 0){
                // cout<<"Row : "<<(dp[s_index][e_index]).row<<endl;
                continue; //Means dp has an answer stored already
            } 

            int minOpsNeeded = INT_MAX;
            for(int i = s_index + 1; i < e_index; i++){
                Info& leftPartitionAnswer = dp[s_index][i];
                Info& rightPartitionAnswer = dp[i][e_index];

                int currentOps = leftPartitionAnswer.operations + rightPartitionAnswer.operations + (leftPartitionAnswer.row * arr[i] * rightPartitionAnswer.col);
                minOpsNeeded = min(minOpsNeeded, currentOps);
            }

            Info temp = Info(arr[s_index], arr[e_index], minOpsNeeded);
            dp[s_index][e_index] = temp;
        }
    }

    return dp[0][n];
}

int matrixChainMultiplication(int* arr, int n) {
    int minOps = 0;

    //Plain RE
    // int start = 0;
    // int end = n;
    // minOps = solveUsingRE(arr, start, end).operations;

    //Mem
    // int start = 0;
    // int end = n;
    // Info temp(0, 0, 0);
    // vector<vector<Info> > dp(n+1, vector<Info>(n+1, temp));
    // minOps = solveUsingMem(arr, start, end, dp).operations;

    //Tab
    int start = 0;
    int end = n;
    minOps = solveUsingTab(arr, start, end).operations;


    return minOps;
}

int main(){
   
return 0;
}