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

        //Replace "T" with int/char etc to understand!
        bool checkCyclicDirectedGraphUsingDFS(T sourceNode, unordered_map<T, bool>& visited, unordered_map<T, bool>& RECallStack){
            visited[sourceNode] = true;
            RECallStack[sourceNode] = true;

            for(pair<T, int> neighbourPair : adjList[sourceNode]){
                T neighbour = neighbourPair.first;

                if(visited[neighbour] == false){
                    bool REKaAns = checkCyclicDirectedGraphUsingDFS(neighbour, visited, RECallStack);
                    if(REKaAns == true){
                        return true;
                    }
                }
                else if(visited[neighbour] == true && RECallStack[neighbour] == true){
                    return true;
                }
            }

            RECallStack[sourceNode] = false; //BackTrack {WARNING : Bhule ga tu ye step}
            return false;
        }

};

int main(){
    /******Connected Graph*******/
    //g is Acyclic Graph
    // Graph<int> g; 
    // g.addEdge(0, 1, 10, 1);
    // g.addEdge(1, 2, 10, 1);
    // g.addEdge(2, 3, 10, 1);
    // g.addEdge(3, 4, 10, 1);

    // bool ans = false;
    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> RECallStack;
    // for(int SrcNode = 0; SrcNode <= 4; SrcNode++){
    //     if(visited[SrcNode] == false){
    //         ans = g.checkCyclicDirectedGraphUsingDFS(SrcNode, visited, RECallStack);
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
    Graph<int> g2; 
    g2.addEdge(0, 1, 10, 1);
    g2.addEdge(1, 2, 10, 1);
    g2.addEdge(2, 3, 10, 1);
    g2.addEdge(3, 4, 10, 1);
    g2.addEdge(4, 0, 10, 1);

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> RECallStack;
    for(int SrcNode = 0; SrcNode <= 4; SrcNode++){
        if(visited[SrcNode] == false){
            ans = g2.checkCyclicDirectedGraphUsingDFS(SrcNode, visited, RECallStack);
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

    //g3 is Cyclic Graph
    // Graph<char> g3; 
    // g3.addEdge('a', 'b', 10, 0);
    // g3.addEdge('b', 'c', 10, 0);
    // g3.addEdge('a', 'c', 10, 0);


    // bool ans = false;
    // unordered_map<char, bool> visited;
    // unordered_map<char, bool> RECallStack;
    // for(int SrcNode = 'a'; SrcNode <= 'c'; SrcNode++){
    //     if(visited[SrcNode] == false){
    //         ans = g3.checkCyclicDirectedGraphUsingDFS(SrcNode, visited, RECallStack);
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

   
return 0;
}
    