#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits.h>
#include<set>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<int> > adjList; //Taking non - weighted graph

    void addEdge(int u, int v, bool direction){
        if(direction == 1){
            //Directed edge
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void TarjansBridgeAlgo(int srcNode, int parent, int timer, vector<int>& tin, vector<int>& low, unordered_map<int, bool>& visited){
        visited[srcNode] = true;
        tin[srcNode] = timer;
        low[srcNode] = timer;
        timer++;
        
        for(auto neighbour : adjList[srcNode]){
            if(neighbour == parent){
                //Parent se low nhi uthana
                continue;
            }

            if(!visited[neighbour]){
                //dfs call
                TarjansBridgeAlgo(neighbour, srcNode, timer, tin, low, visited);

                //Update low after returning from dfs
                low[srcNode] = min(low[srcNode], low[neighbour]);

                //Check for bridge
                if(low[neighbour] > tin[srcNode]){
                    cout<<"Bridge : "<<srcNode<<"---"<<neighbour<<endl;
                }
            }
            else{
                //neighbour already visited and not parent (bcz parent ke liye to upr continue lga rkah hai)

                //Update low
                low[srcNode] = min(low[srcNode], low[neighbour]);

                //Below check is not needed by the way bcz in Undirected graph, this neighbour has already been visited & then you arrived at the current "srcNode" So, another path exists from "srcNode" to this neighbour, hence it can not be a bridge

                // // Check for bridge
                // if(low[neighbour] > tin[srcNode]){
                //     cout<<"Bridge : "<<srcNode<<"---"<<neighbour<<endl;
                // }
            }

        }
    }

};


int main(){
    //g, g2, g3 are undirected graphs

    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(3, 4, 0);

    // Graph g2;
    // g2.addEdge(0, 1, 0);
    // g2.addEdge(1, 2, 0);
    // g2.addEdge(2, 3, 0);
    // g2.addEdge(3, 4, 0);

    // Graph g3;
    // g3.addEdge(0, 1, 0);
    // g3.addEdge(0, 2, 0);
    // g3.addEdge(1, 2, 0);
    // g3.addEdge(1, 3, 0);
    // g3.addEdge(1, 4, 0);
    // g3.addEdge(1, 6, 0);
    // g3.addEdge(3, 5, 0);
    // g3.addEdge(4, 5, 0);

    //g4 is having a directed edge
    //Algo does not work for this ! (It outputs 0 bridges but bridges are there!)
    // Graph g4;
    // g4.addEdge(0, 1, 1);
    // g4.addEdge(1, 2, 1);
    // g4.addEdge(2, 0, 0);


    int totNodes = 5; //UPDATE THIS BASED ON THE GRAPH YOU ARE TAKING !!

    int timer = 1; //starting from 1
    vector<int> tin(totNodes);
    vector<int> low(totNodes);
    unordered_map<int, bool> visited;

    g.TarjansBridgeAlgo(0, -1, timer, tin, low, visited);
    
    return 0;
}

