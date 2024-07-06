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

        void bfsTraversal(T sourceNode, unordered_map<T, bool>& visited){
            //"adjList" already presented as a data member
            //Visited Data Structure : got as parameter from outside (To handle disconnected graphs)
            //Queue
            queue<T> queue;

            //Initialize Queue
            queue.push(sourceNode);
            visited[sourceNode] = true;

            while(!queue.empty()){
                T frontNode = queue.front();
                cout<<frontNode<<" ";
                queue.pop();

                for(auto neighbour : adjList[frontNode]){
                    T neighbourData = neighbour.first;
                    
                    //If neighbour not already visited
                    if(visited[neighbourData] == false){
                        queue.push(neighbourData);
                        visited[neighbourData] = true;
                    }
                }
            }
        }
};

int main(){
    /******BFS Traversal*******/
    // //Connected Graph
    // //graph g4 is drawn in NoteBook
    // Graph<char> g4;
    // g4.addEdge('a', 'b', 5, 1);
    // g4.addEdge('a', 'c', 10, 1);
    // g4.addEdge('b', 'd', 100, 1);
    // g4.addEdge('b', 'c', 100, 1);
    // g4.addEdge('c', 'f', 20, 1);
    // g4.addEdge('c', 'e', 50, 1);
    // g4.addEdge('e', 'f', 50, 1);

    // //Expected output of BFS Traversal : a b c d f e
    // unordered_map<char, bool> visited;

    // g4.bfsTraversal('a', visited); 

    // // No need of for() loop as g4 is a connected graph (Although it will also work!)
    // // for(char node = 'a'; node <= 'f'; node++){
    // //     if(visited[node] == false){
    // //         g4.bfsTraversal(node, visited); 
    // //     }
    // // }

    // Disconnected Graph
    // Graph<char> g5;
    // g5.addEdge('a', 'b', 5, 0);
    // g5.addEdge('b', 'c', 5, 0);

    // g5.addEdge('d', 'e', 5, 0);

    // g5.addEdge('f', 'f', 5, 0);

    // //g5 is disconnected graph so run for() to treat all nodes as source once
    // unordered_map<char, bool> visited;
    // for(char node = 'a'; node <= 'f'; node++){
    //     if(visited[node] == false){
    //         g5.bfsTraversal(node, visited); 
    //     }
    // }
   
return 0;
}
    