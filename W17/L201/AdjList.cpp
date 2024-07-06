#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

/***************Unweighted graph*************/
// class Graph{
//     unordered_map<int, list<int> > adjList; //Node -> Neighbours

//     public:
//     void addEdge(int u, int v, bool direction){
//         //Adds edge from Node u to Node v
//         //if direction = 0 --> undirected edge
//         //if direction = 1 --> directed edge

//         if(direction == 1){
//             //An edge from u to v exists i.e u ---> v
//             adjList[u].push_back(v);
//         }
//         else{
//             //Here, direction = 0
//             //So An edge exists from u to v AND from v to u
//             //i.e u ---> v 
//             adjList[u].push_back(v);

//             //AND v ---> u
//             adjList[v].push_back(u);
//         }

//         cout<<"Printing Adj List:"<<endl;
//         printAdjList();
//         cout<<endl;
//     }

//     void printAdjList(){
//         for(auto i : adjList){
//             cout<<i.first<<" -> {";
//             for(auto neighbour : i.second){
//                 cout<<neighbour<<", ";
//             }
//             cout<<"}"<<endl;
//         }
//         cout<<endl;
//     }
// };

// int main(){
//    Graph g;
//    g.addEdge(0, 1, 1);
//    g.addEdge(1, 2, 1);
//    g.addEdge(1, 3, 1);
//    g.addEdge(2, 3, 1);
   
//    Graph g2;
//    g2.addEdge(10, 11, 0);
// return 0;
// }


/***************Weighted graph*************/
//Making this code generic!
template <typename T>
class Graph{
    unordered_map<T, list<pair<T, int> > > adjList;
    
    public:
        void addEdge(T u, T v, int weight, bool direction){
            if(direction == 1){
                adjList[u].push_back(make_pair(v, weight)); //I used "make_pair()" just for the sake of it!
            }
            else{
                adjList[u].push_back({v, weight});
                adjList[v].push_back({u, weight});
            }
            cout<<"Printing Adj List:"<<endl;
            printAdjList();
            cout<<endl;
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
};

int main(){
    //Making weighted graph via adjacency list
    Graph<int> g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(1, 2, 10, 1);
    g.addEdge(1, 3, 20, 1);
    g.addEdge(2, 3, 50, 1);

    Graph<int> g2;
    g2.addEdge(0, 1, 100, 0);

    Graph<char> g3;
    g3.addEdge('a', 'b', 5, 1);
    g3.addEdge('b', 'c', 10, 1);
    g3.addEdge('c', 'd', 20, 1);
    g3.addEdge('c', 'e', 50, 1);

    return 0;
}
