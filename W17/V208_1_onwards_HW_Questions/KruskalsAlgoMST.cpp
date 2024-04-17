#include<bits/stdc++.h>
using namespace std;

// [GFG : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1]

void makeSet(vector<int>& parent, vector<int>& rank, int V){
    //Initialise "parent[]" and "rank[]"
    
    for(int i = 0; i < V; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    
}

//Find parent Recursively
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

static bool cc(vector<int>& A, vector<int>& B){
    // return "true" if "A" has weight less than "B"
    return A[2] < B[2];
}


//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    //Make a linear Data Structure "edges"
    //"edges" will have have all the edges in format "u, v, weight"
    vector<vector<int>> edges;
    
    for(int index = 0; index < V; index++){
        int u = index;
        
        for(auto vAndWeight : adj[u]){
            int v = vAndWeight[0];
            int weight = vAndWeight[1];
            
            vector<int> temp = {u, v, weight};
            edges.push_back(temp);
        }
    }
    
    //Sort "edges" by weight
    sort(edges.begin(), edges.end(), cc);


    vector<int> parent(V);
    vector<int> rank(V);
    makeSet(parent, rank, V);
    
    int mstWeight = 0;
    
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        int parentU = findParent(parent, u); 
        int parentV = findParent(parent, v);
        
        //If u and v in different components then perform Union
        if(parentU != parentV){
            unionSet(u, v, parent, rank);
            mstWeight += weight;
        }
    }
    
    return mstWeight;
}


int main(){
   
return 0;
}