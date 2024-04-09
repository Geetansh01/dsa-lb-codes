#include<bits/stdc++.h>
using namespace std;


//M1 : "L202 : Cycle Detection in Directed Graph : Using DFS" [Alter method possible : "L203 : Cycle Detection in Directed Graph : Using BFS (i.e via Kahn's Algo)"]
bool chkCycleInDirectedGraphDFS(int course, unordered_map<int, bool>& visited, unordered_map<int, bool>& stk, unordered_map<int, list<int> >& adjList){
    visited[course] = true;
    stk[course] = true;

    for(auto preReq : adjList[course]){
        if(!visited[preReq]){
            bool cyclePresent = chkCycleInDirectedGraphDFS(preReq, visited, stk, adjList);
            if(cyclePresent) return true;
        }
        else{
            //Check if present in RE CALL stack
            if(stk[preReq] && visited[preReq]){
                return true;
            }
        }
    }

    stk[course] = false; //BackTracking
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //Main Logic : Cycle should not be present in given Directed Graph
    // eg: [1, 0] : (0) ---> (1) [Pehle 0 kro then 1]
    
    
    //Cycle detection using DFS

    unordered_map<int, list<int> > adjList;

    //Make adjList
    for(auto preReqPair : prerequisites){
        int course = preReqPair[0];
        int preReq = preReqPair[1];
        adjList[preReq].push_back(course);
    }

    unordered_map<int, bool> stk; //Node -> Present in RE CALL STACK or not
    unordered_map<int, bool> visited; //Node -> visited or Not
    bool cyclePresent = false;
    for(int course = 0; course < numCourses; course++){
        if(!visited[course]){
            cyclePresent = chkCycleInDirectedGraphDFS(course, visited, stk, adjList);
            if(cyclePresent) return false;
        }
    }

    return true;
}

int main(){
   
return 0;
}