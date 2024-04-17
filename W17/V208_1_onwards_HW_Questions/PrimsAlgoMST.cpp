#include<bits/stdc++.h>
using namespace std;

//[GFG : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1]

//TC : O(n^2)
//If you use a min-heap (Priority Queue) instead of array "key[]" then O(n log(n))
//This is bcz it takes n time every time with simple array "key[]" to find the minimum value
//But min-heap can give minimum value in O(1), although insertion in min-heap is O(log n)
//See min-heap code from Striver's yt if needed!
int getMinValueNode(vector<int>& key, vector<int>& mst){
    int minNode = -1; 
    int minNodeValue = INT_MAX;
    
    for(int index = 0; index < key.size(); index++){
        if(mst[index] == false && key[index] < minNodeValue){
            minNode = index;
            minNodeValue = key[index];
        }
    }
    
    return minNode;
}

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[]){
    
    vector<int> key(V, INT_MAX);
    key[0] = 0;
    
    vector<int> mst(V, false); //Track all nodes included in mst
    vector<int> parent(V, -1); //Will contain the final mst structure
    
    while(true){
        //Step 1 : get minimum value node from "key[]" that is not in mst
        int u = getMinValueNode(key, mst);
        
        if(u == -1){
            break;
        }
        
        //Step 2
        mst[u] = true;
        
        //Step 3 : Process all adjacent nodes/neighbours of u
        for(auto edgeAndWeight : adj[u]){
            int v = edgeAndWeight[0];
            int weight = edgeAndWeight[1];
            
            if(mst[v] == false && weight < key[v]){
                key[v] = weight;
                parent[v] = u;
            }
        }
    }
    
    // Find final weight of MST
    int sum = 0;
    for(int i = 0; i < key.size(); i++){
        sum += key[i];
    }
    
    return sum;
}

int main(){
   
return 0;
}