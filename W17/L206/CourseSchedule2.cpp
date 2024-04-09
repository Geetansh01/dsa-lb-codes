#include<bits/stdc++.h>
using namespace std;


//M1 : "L202 : Cycle Detection in Directed Graph : Using DFS" [Alter method possible : "L203 : Cycle Detection in Directed Graph : Using BFS (i.e via Kahn's Algo)"]
bool chkCycleInDirectedGraphDFS(int course, unordered_map<int, bool>& visited, unordered_map<int, bool>& RECallStack, stack<int>& stk, unordered_map<int, list<int> >& adjList){
    visited[course] = true;
    RECallStack[course] = true;

    for(auto preReq : adjList[course]){
        if(!visited[preReq]){
            bool cyclePresent = chkCycleInDirectedGraphDFS(preReq, visited, RECallStack, stk, adjList);
            if(cyclePresent) return true;
        }
        else{
            //Check if present in RE CALL stack
            if(RECallStack[preReq] && visited[preReq]){
                return true;
            }
        }
    }

    RECallStack[course] = false; //BackTracking
    stk.push(course);
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //Main Logic : Cycle should not be present in given Directed Graph, if cycle present then return empty array ATQ
    // eg: [1, 0] : (0) ---> (1) [Pehle 0 kro then 1]
    //If cycle is NOT present then return the Topological Sort of the given Directed graph!


    //Cycle detection using DFS + Topological Sort if cycle Not present
    vector<int> order;

    unordered_map<int, list<int> > adjList;

    //Make adjList
    for(auto preReqPair : prerequisites){
        int course = preReqPair[0];
        int preReq = preReqPair[1];
        adjList[preReq].push_back(course);
    }

    unordered_map<int, bool> RECallStack; //Node -> Present in RE CALL STACK or not
    unordered_map<int, bool> visited; //Node -> visited or Not
    stack<int> stk; //it will store reverse topological sort
    bool cyclePresent = false;
    for(int course = 0; course < numCourses; course++){
        if(!visited[course]){
            cyclePresent = chkCycleInDirectedGraphDFS(course, visited, RECallStack, stk, adjList);
            if(cyclePresent) return order; //returning empty array ATQ
        }
    }

    while(!stk.empty()){
        order.push_back(stk.top());
        stk.pop();
    }

    return order;
}

int main(){
   
return 0;
}