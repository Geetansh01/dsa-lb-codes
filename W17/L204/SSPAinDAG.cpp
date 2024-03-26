#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits.h>
using namespace std;

// Finding Shortest Path from Source in DAGs (Directed Acyclic Graphs) using DFS (For Weighted Graphs)

class Graph{
    public:

    unordered_map<int, list<pair<int, int> > > adjList; //Taking weighted graph

    void addEdge(int u, int v, int weight, bool direction){
        if(direction == 1){
            //Directed edge
            adjList[u].push_back({v, weight});
        }
        else{
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"{"<<j.first<<","<<j.second<<"}, ";
            }
            cout<<endl;
        }
    }

    void topoSortDFS(int sourceNode, unordered_map<int, bool>& visited, stack<int>& ans){
        //1 case Hm
        visited[sourceNode] = true;
        // cout<<sourceNode<<" ";

        //RE Calls for all neighbours
        for(pair<int, int> neighbourPair : adjList[sourceNode]){

            int neighbour = neighbourPair.first;

            if(visited[neighbour] == false){
                //RE Call only if neighbour not already visited!
                topoSortDFS(neighbour, visited, ans);
            }
        }

        //While returning, store the node in stack
        ans.push(sourceNode);
    }

    vector<int> shortestPathDFS(int srcNode, int destination, stack<int> topoOrderStack, int totNodes){
        vector<int> distance(totNodes ,INT_MAX);

        //Step 2 : Set distance of Source Node to 0
        distance[srcNode] = 0;

        //Step 3 : in TS Order, process all vertices
        while(!topoOrderStack.empty()){
            int topElement = topoOrderStack.top();
            topoOrderStack.pop();

            //Update distances of Neighbours for "topElement"
            //Agr "topElement" ka khud ka distance INT_MAX hua to usse kisi or node pr kya hi jaoge, so make sure "topElement" ka khud ka distance INT_MAX na ho!
            if(distance[topElement] != INT_MAX){
                for(pair<int, int> neighbourPair : adjList[topElement]){
                    int neighbour = neighbourPair.first;

                    if(distance[topElement] + neighbourPair.second < distance[neighbour]){
                        distance[neighbour] = distance[topElement] + neighbourPair.second;
                    }
                }
            }
        }

        cout<<"Printing Ans : "<<endl;
        for(int i = 0; i < totNodes; i++){
            cout<<"Distance of "<<i<<" from Src Node -> "<<distance[i]<<endl;
        }
        cout<<endl;
    }
};

int main(){
    //g is DAG
    //"g" graph is drawn in notebook 
    Graph g;

    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);

    // g.printAdjList();
    
    //Step 1 : Find Topological Sort
    stack<int> topoOrderStack;
    unordered_map<int, bool> visited; 
    g.topoSortDFS(0, visited, topoOrderStack);

    //Printing TS
    // while(!topoOrderStack.empty())
    // {
    //     cout<<topoOrderStack.top()<<" "; 
    //     topoOrderStack.pop();
    // }
    

    //Step 2 : Fill "distance[]" array
    int srcNode = 0;
    int destination = 3;
    int totNodes = 5;
    g.shortestPathDFS(srcNode, destination, topoOrderStack, totNodes);

    //Expected Output:
    /*
        Distance of 0 from Src Node -> 0
        Distance of 1 from Src Node -> 5
        Distance of 2 from Src Node -> 3
        Distance of 3 from Src Node -> 8 
        Distance of 4 from Src Node -> 9
    */
    //So, Note that shortest distance of destination (i.e 3) from src node is 8

return 0;
}