#include<bits/stdc++.h>
using namespace std;

//TC : O(n^2) {n = total no. of cities}
void bfsTrav(int Node, vector<vector<int>>& isConnected, unordered_map<int, bool>& visited){
    queue<int> q;

    q.push(Node);
    visited[Node] = true;

    int cols = isConnected[0].size();

    while(!q.empty()){
        int currNode = q.front();
        q.pop();

        for(int j = 0; j < cols; j++){
            if(isConnected[currNode][j] == 1){
                int neighbour = j;
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
}

//TC : O(n^2) {n = total no. of cities}
void dfsTrav(int Node, vector<vector<int>>& isConnected, unordered_map<int, bool>& visited){
    visited[Node] = true;

    int col = isConnected[0].size();
    for(int j = 0; j < col; j++){
        if(isConnected[Node][j] == 1){
            int neighbour = j;
            if(!visited[neighbour]){
                dfsTrav(neighbour, isConnected, visited);
            }
        }
    }
    
    return;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int rows = isConnected.size();

    unordered_map<int, bool> visited; //Node --> visited or not
    int provinces = 0;
    for(int i = 0; i < rows; i++){
        if(!visited[i]){
            provinces++;
            dfsTrav(i, isConnected, visited);
            // bfsTrav(i, isConnected, visited);
        }
    }

    return provinces;
}

int main(){
   
return 0;
}