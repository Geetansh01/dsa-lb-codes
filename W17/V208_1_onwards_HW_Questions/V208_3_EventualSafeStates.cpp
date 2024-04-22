#include<bits/stdc++.h>
using namespace std;

// Eventual Safe States [GFG : https://www.geeksforgeeks.org/problems/eventual-safe-states/1]

/*
    Main Logic : For any node X in the graph, it is either 
        1)Non - Safe Node:
            1)If it itself is part of a cycle
            2)If it is not part of a cycle but it can reach a node that is part of a cycle
        2)Safe Node

    So, exact code from "L202 : DirectedchkCycleDFS.cpp" can be used with minor changes

    Reference : Striver's YT channel (https://youtu.be/uRbJ1OF9aYM?si=iIYSOYqUMVFdWJd0)
*/

//TC : O(V + E) (BCz of DFS)

bool checkCyclicDirectedGraphUsingDFS(int node, vector<int> adj[], unordered_map<int, bool>& visited, unordered_map<int, bool>& reCallStack, vector<bool>& safeNode){
    visited[node] = true;
    reCallStack[node] = true;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool REKaAns = checkCyclicDirectedGraphUsingDFS(neighbour, adj, visited, reCallStack, safeNode);
            if(REKaAns == true){
                //Mtlb agee cycle hai so Current Node is not a safe Node
                return true;
            }
        }
        else if(visited[neighbour] == true && reCallStack[neighbour] == true){
            //Mtlb agee cycle hai so Current Node is not a safe Node
            return true;
        }
        
    }
    
    reCallStack[node] = false; //backtracking
    
    //Yahan tk aye to current Node safe node hai, unsafe hoti to cycle milti & upr se hi return ho jate
    safeNode[node] = true;

    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    //Get all nodes making a cycle
    // vector<bool> makingCycle (V, false);
    
    vector<int> ans;
    
    vector<bool> safeNode (V, false); //For any Node that is safe, it's entry in "safeNode" will be true
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> reCallStack;
    for(int node = 0; node < V; node++){
        if(!visited[node]) {
            checkCyclicDirectedGraphUsingDFS(node, adj, visited, reCallStack, safeNode);
        }
        
    }
    
    //Push all safe nodes in "ans"
    for(int node = 0; node < V; node++){
        if(safeNode[node]) ans.push_back(node);
    }
    
    return ans;
}

int main(){
   
return 0;
}