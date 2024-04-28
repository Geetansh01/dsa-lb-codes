#include<bits/stdc++.h>
using namespace std;

//M1: Using Disjoint Set

//Main Logic : using disjoint set DS to find extra edges and no. of disconnected components (see V208_1_onwards_HW_Questions : KruskalsAlgoMST in notebook)

//TC : O(n^2) {In worst case, there can be n(n-1) edges & I am traversing all the edges once from the "connections" vector given}
//Still M1 is more efficient than M2

//code for findParent() and unionSet() copied from V208_1_onwards_HW_Questions : KruskalsAlgoMST.cpp
int findParent(vector<int>& parent, int node){
    //BC
    if(parent[node] == node) return node;
    
    int parentOfnode = findParent(parent, parent[node]);
    parent[node] = parentOfnode; //Path Compression
    
    return parentOfnode;
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
    int parentU = findParent(parent, u); 
    int parentV = findParent(parent, v);
    
    if(rank[parentU] < rank[parentV]){
        parent[parentU] = parentV;
    }
    else if(rank[parentU] > rank[parentV]){
        parent[parentV] = parentU;
    }
    else{
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    //Main Logic : using disjoint set DS to find extra edges and no. of disconnected components 
    vector<int> parent(n);
    vector<int> rank(n, 0);

    //Initialise parent[] array
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int numOfExtraEdges = 0;
    for(auto connection : connections){
        int u = connection[0];
        int v = connection[1];

        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        if(uParent != vParent){
            unionSet(u, v, parent, rank);
        }
        else{
            numOfExtraEdges++;
        }
    }

    //Find total numbebr of Disconnected components
    int discntdComp = 0;
    for(int i = 0; i < n; i++){
        if(parent[i] == i) discntdComp++;
    }

    int cablesNeeded = discntdComp - 1;
    return (numOfExtraEdges >= cablesNeeded) ? cablesNeeded : -1;
}


//M2 : Using DFS
// // TC : O(n^2 + n^2) = O(n^2) {n^2 for making adjList, n^2 for DFS}
// //I thought of this solution :)

// void dfs(int i, int& nodes, int& cables, unordered_map<int, bool>& visited, vector<list<int> >& adjList){
//     visited[i] = true;
//     nodes++;

//     for(int nbr : adjList[i]){
//         cables++;
//         if(!visited[nbr]){
//             dfs(nbr, nodes, cables, visited, adjList);
//         }
//     }

//     return;
// }

// int makeConnected(int n, vector<vector<int>>& connections) {
//     //Make Adj List
//     // unordered_map<int, list<int> > adjList;
//     vector<list<int> > adjList(n);
//     for(int i = 0; i < connections.size(); i++){
//         int u = connections[i][0];
//         int v = connections[i][1];
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     //Do DFS
//     int discntdComp = 0;
//     int extraCables = 0;
//     unordered_map<int, bool> visited;
//     for(int i = 0; i < n; i++){
//         if(!visited[i]){
//             discntdComp++;
//             int nodes = 0;
//             int cables = 0;
//             dfs(i, nodes, cables, visited, adjList);
//             cables = cables/2; //Every cable will be counted x2 in dfs()
//             extraCables += cables - (nodes - 1);
//         }
//     }
    
//     if(extraCables >= discntdComp - 1){
//         return discntdComp - 1;
//     }

//     return -1;
// }

int main(){
   
return 0;
}