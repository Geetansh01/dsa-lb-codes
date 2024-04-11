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

    void bellmanFordAlgo(int srcNode, int totNodes){
        vector<int> distance(totNodes, INT_MAX);
        distance[srcNode] = 0;

        //Step 1 : Do (N - 1) relaxations for each edge (here N = "totNodes")
        for(int i = 0; i < totNodes - 1; i++){
            //Assuming directed weighted graph
            
            //Following 2 nested "for()" loops combined run for all the edges 
            for(auto nodeNbrsPair : adjList){
                int u = nodeNbrsPair.first;

                for(auto nbrWeightPair : nodeNbrsPair.second){
                    int v = nbrWeightPair.first;
                    int costu2v = nbrWeightPair.second;

                    if(distance[u] != INT_MAX && (distance[u] + costu2v) < distance[v]){
                        distance[v] = distance[u] + costu2v;
                    }
                }
            }
        }

        //To check if negative cycle is present
        //Once again run the relaxation code
        bool anyDistanceUpdated = false;
        for(auto nodeNbrsPair : adjList){
            int u = nodeNbrsPair.first;

            for(auto nbrWeightPair : nodeNbrsPair.second){
                int v = nbrWeightPair.first;
                int costu2v = nbrWeightPair.second;

                if(distance[u] != INT_MAX && (distance[u] + costu2v) < distance[v]){
                    distance[v] = distance[u] + costu2v;
                    anyDistanceUpdated = true;
                    break;
                }
            }

            if(anyDistanceUpdated) break;
        }

        if(anyDistanceUpdated){
            cout<<"Negative Cycle Present in graph!"<<endl;
            return;
        }    


        cout<<"Printing distance[] array : "<<endl;
        for(auto dist : distance){
            cout<<dist<<" ";
        }

        return;
    }

};


int main(){
    //Graph g is made in notebook, just A B C D E are 0 1 2 3 4 here
    Graph g;

    g.addEdge(0, 1, -1, 1);
    g.addEdge(0, 2, 4, 1);
    g.addEdge(1, 2, 3, 1);
    g.addEdge(1, 4, 2, 1);
    g.addEdge(1, 3, 2, 1);
    g.addEdge(3, 2, 5, 1);
    g.addEdge(3, 1, 1, 1);
    g.addEdge(4, 3, -3, 1);

    g.printAdjList();
    
    int sourceNode = 0;
    int totNodes = 5;  
    
    g.bellmanFordAlgo(0, totNodes); //Expected Output : 0 -1 2 -2 1 

return 0;
}