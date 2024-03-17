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
        void addEdge(T u, T v, T weight, bool direction){
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

        //Replace "T" with int/char etc to understand!
        //Below function returns true if a cycle is detected in Undirected graph (We have passed the "sourceNode" assuming the entire graph is connected . If the graph is disconnected then we need to run below function for each of the components of disconnected graph)
        bool checkCyclicUsingDFS(T sourceNode, unordered_map<T, bool>& visited, int parent){
            //1 case Hm
            visited[sourceNode] = true;
            
            for(pair<T, int> neighbourPair : adjList[sourceNode]){
                T neighbour = neighbourPair.first;

                if(visited[neighbour] == false){
                    bool ansFromRE = checkCyclicUsingDFS(neighbour, visited, sourceNode);
                    if(ansFromRE == true){
                        return true;
                    }
                }
                //WARNING : Below is an "else if()", Don't make it just "if()" or else it will be a blunder (dry changing to "if()" & then run for an Acyclic graph like "g" below!)
                else if(visited[neighbour] && neighbour != parent){
                    //Cycle Present
                    return true;
                }
            }

            return false;
        }

};

int main(){
    /******Connected Graph*******/
    //g is Acyclic Graph
    // Graph<int> g; 
    // g.addEdge(0, 1, 10, 0);
    // g.addEdge(1, 3, 10, 0);
    // g.addEdge(0, 2, 10, 0);
    // g.addEdge(2, 4, 10, 0);

    // bool ans = false;
    // unordered_map<int, bool> visited;
    // for(int SrcNode = 0; SrcNode <= 4; SrcNode++){
    //     if(visited[SrcNode] == false){
    //         ans = g.checkCyclicUsingDFS(SrcNode, visited, -1);
    //         if(ans == true){
    //             break;
    //         }
    //     }
    // }
    // if(ans == true){
    //     cout<<"Cycle Present"<<endl;
    // }
    // else{
    //     cout<<"Cycle Absent"<<endl; 
    // }

    //g2 is Cyclic Graph
    // Graph<int> g2; 
    // g2.addEdge(0, 1, 10, 0);
    // g2.addEdge(1, 2, 10, 0);
    // g2.addEdge(2, 3, 10, 0);
    // g2.addEdge(2, 4, 10, 0);
    // g2.addEdge(3, 4, 10, 0);

    // bool ans = false;
    // unordered_map<int, bool> visited;
    // for(int SrcNode = 0; SrcNode <= 4; SrcNode++){
    //     if(visited[SrcNode] == false){
    //         ans = g2.checkCyclicUsingDFS(SrcNode, visited, -1);
    //         if(ans == true){
    //             break;
    //         }
    //     }
    // }
    // if(ans == true){
    //     cout<<"Cycle Present"<<endl;
    // }
    // else{
    //     cout<<"Cycle Absent"<<endl; 
    // }
    
    //g3 is Cyclic Graph
    Graph<char> g3; 
    g3.addEdge('a', 'b', 10, 0);
    g3.addEdge('b', 'c', 10, 0);
    g3.addEdge('a', 'c', 10, 0);


    bool ans = false;
    unordered_map<char, bool> visited;
    for(int SrcNode = 'a'; SrcNode <= 'c'; SrcNode++){
        if(visited[SrcNode] == false){
            ans = g3.checkCyclicUsingDFS(SrcNode, visited, -1);
            if(ans == true){
                break;
            }
        }
    }
    if(ans == true){
        cout<<"Cycle Present"<<endl;
    }
    else{
        cout<<"Cycle Absent"<<endl; 
    }

   
return 0;
}
    