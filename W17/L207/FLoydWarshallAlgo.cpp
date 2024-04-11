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

    void floydWarshall(int totNodes){
        vector<vector<int> > distance(totNodes, vector<int>(totNodes, INT_MAX));

        //Fill diagonal with 0
        for(int i = 0; i < totNodes; i++){
            distance[i][i] = 0;
        }

        //Step D0 : Fill the weights from graph into "distance[][]"
        //So, get all edges from graph
        for(auto nodeNbrsPair : adjList){
            int u = nodeNbrsPair.first;

            for(auto nbrWeightPair : nodeNbrsPair.second){
                int v = nbrWeightPair.first;
                int weight = nbrWeightPair.second; //weight stored on edge

                //Note that pehle Diagonal pe 0's dale the vo override nhi krne
                //Bcz my adjList is such that no node will have an edge to itself so i don't need any checks but otherwise you must not run below line for diagonal. 
                //I am adding the check anyways!
                if(u != v){
                    distance[u][v] = weight;
                }
            }
        }

        //Step D1, D2, ... Dn : Helper Nodes se hoke jana
        for(int helper = 0; helper < totNodes; helper++){
            for(int srcNode = 0; srcNode < totNodes; srcNode++){
                for(int destination = 0; destination < totNodes; destination++){
                    int oldDist = distance[srcNode][destination];

                    int newDist = INT_MAX;
                    if(distance[srcNode][helper] != INT_MAX && distance[helper][destination] != INT_MAX){
                        //Go through the helper node
                        newDist = distance[srcNode][helper] + distance[helper][destination];  // __Line(1)

                        //Bcz we are reusing previously calculated stored info in __Line(1) so Floyd Warshall Algo is DP based!
                    }

                    distance[srcNode][destination] = min(oldDist, newDist);
                }
            }
        }

        //Printing distance[][] matrix
        for (int i = 0; i < totNodes; i++){
            for (int j = 0; j < totNodes; j++){
                cout<<distance[i][j]<<", ";
            }
            cout<<endl;
        }
    }   

};


int main(){
    //Graph g
    Graph g;

    g.addEdge(0, 1, 3, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(2, 1, 1, 1);
    g.addEdge(3, 2, 2, 1);

    // g.printAdjList();
    
    int totNodes = 4;  
    
    g.floydWarshall(totNodes); 
    //Expected Output : 
    /*
        0, 3, 7, 5, 
        2, 0, 6, 4, 
        3, 1, 0, 5, 
        5, 3, 2, 0, 
    */
    return 0;
}