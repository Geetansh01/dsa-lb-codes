#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

//Making this code generic!
template <typename T>
class Graph{
    unordered_map<T, list<pair<T, int> > > adjList; //Taking Weighted graph
    
    public:
        void addEdge(T u, T v, int weight, bool direction){
            if(direction == 1){
                adjList[u].push_back(make_pair(v, weight)); //I used "make_pair()" just for the sake of it!
            }
            else{
                adjList[u].push_back({v, weight});
                adjList[v].push_back({u, weight});
            }
            // cout<<"Printing Adj List:"<<endl;
            // printAdjList();
            // cout<<endl;
        }

        void printAdjList(){
            for(auto i : adjList){
                cout<<i.first<<" -> {";
                for(auto neighbourPair : i.second){
                    cout<<"{"<<neighbourPair.first<<", "<<neighbourPair.second<<"},  ";
                }
                cout<<"}"<<endl;
            }
        }

        void dfsTraversal(T sourceNode, unordered_map<T, bool>& visited){
            // //BC (Not needed bcz of ___Condition Lines below)
            // if(visited[sourceNode] == true) return;

            //1 case Hm
            visited[sourceNode] = true;
            cout<<sourceNode<<" ";

            //RE Calls for all neighbours
            for(pair<T, int> neighbour : adjList[sourceNode]){
                T neighbourData = neighbour.first;

                //___Condition Lines
                // If you want that BC above then use Line (1) instead
                if(visited[neighbourData] == false){
                    //RE Call only if neighbour not already visited!
                    dfsTraversal(neighbourData, visited);
                }

                // dfsTraversal(neighbourData, visited);  //___Line (1)

            }
        }
};

int main(){
    /******DFS Traversal*******/
    // Connected Graph
    // // graph g4 is drawn in NoteBook
    // Graph<char> g4;
    // g4.addEdge('a', 'b', 5, 0);
    // g4.addEdge('a', 'c', 10, 0);
    // g4.addEdge('c', 'd', 100, 0);
    // g4.addEdge('c', 'e', 50, 0);
    // g4.addEdge('d', 'e', 100, 0);
    // g4.addEdge('e', 'f', 50, 0);

    // //Expected output of DFS Traversal : a b c d e f
    // unordered_map<char, bool> visited;

    // g4.dfsTraversal('a', visited); 

    // // No need of for() loop as g4 is a connected graph (Although it will also work!)
    // // for(char node = 'a'; node <= 'f'; node++){
    // //     if(visited[node] == false){
    // //         g4.dfsTraversal(node, visited); 
    // //     }
    // // }

    // Disconnected Graph
    Graph<char> g5;
    g5.addEdge('a', 'b', 5, 0);
    g5.addEdge('b', 'c', 5, 0);

    g5.addEdge('d', 'e', 5, 0);

    g5.addEdge('f', 'f', 5, 0);

    unordered_map<char, bool> visited;
    for(char node = 'a'; node <= 'f'; node++){
        if(visited[node] == false){
            g5.dfsTraversal(node, visited); 
        }
    }
   
return 0;
}
    