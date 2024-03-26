#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

//Finding Shortest Path from Source in Undirected Non-weighted graph using BFS

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

    void shortestPathBFS(int src, int destination){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        //Initialise queue
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto neighbourPair : adjList[frontNode]){
                int neighbour = neighbourPair.first;

                if(visited[neighbour] == false){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }

        //Traverse parent[] & store shortest path in "ans" vector
        vector<int> ans;
        int node = destination;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout<<"Printing Shortest Path : "<<endl;
        for(auto i : ans){
            cout<<i<<", ";
        }
        cout<<endl;

    }
};

int main(){
    //g is undirected graph
    Graph g;

    g.addEdge(0, 1, 1, 0);
    g.addEdge(1, 2, 1, 0);
    g.addEdge(2, 3, 1, 0);

    g.addEdge(3, 4, 1, 0);
    g.addEdge(0, 5, 1, 0);
    g.addEdge(5, 4, 1, 0);

    g.addEdge(0, 6, 1, 0);
    g.addEdge(6, 7, 1, 0);
    g.addEdge(7, 8, 1, 0);
    g.addEdge(8, 4, 1, 0);

    // g.printAdjList();

    int src = 0;
    int destination = 4;

    g.shortestPathBFS(src, destination); //Expected Output : 0, 5, 4,


return 0;
}