#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    unordered_map<int, list<int > > adjList; //Taking Unweighted graph
    
    public:
        void addEdge(int u, int v, bool direction){
            if(direction == 1){
                adjList[u].push_back(v); 
            }
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            // cout<<"Printing Adj List:"<<endl;
            // printAdjList();
            // cout<<endl;
        }

        void printAdjList(){
            for(auto i : adjList){
                cout<<i.first<<" -> {";
                for(auto neighbour : i.second){
                    cout<<"{"<<neighbour<<"},  ";
                }
                cout<<"}"<<endl;
            }
        }

        void topoSortDFS(int sourceNode, unordered_map<int, bool>& visited, stack<int>& ans){
            //1 case Hm
            visited[sourceNode] = true;
            // cout<<sourceNode<<" ";

            //RE Calls for all neighbours
            for(int neighbour : adjList[sourceNode]){

                if(visited[neighbour] == false){
                    //RE Call only if neighbour not already visited!
                    topoSortDFS(neighbour, visited, ans);
                }
            }

            //While returning, store the node in stack
            ans.push(sourceNode);
        }

        void topoSortBFS(int n, vector<int>& TS){
            queue<int> q;
            unordered_map<int, int> indegree; 

            //Calculate indegree of all nodes in the graph (So all nodes covered -- for connected as well as disconnected graph)
            //___for() loop 1
            for(auto itr : adjList){
                int sourceNode = itr.first;
                for(auto neighbour : itr.second){
                    indegree[neighbour] += 1;
                }
            }

            //Put all nodes in queue with indegree 0
            for(int i = 0; i < n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }

            //BFS Logic
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                TS.push_back(frontNode);

                for(auto neighbour : adjList[frontNode]){
                    indegree[neighbour]--;

                    //Check if kisi "neighbour" ki indegree 0 ho gyi ho
                    if(indegree[neighbour] == 0){
                        q.push(neighbour);
                    }
                }
            }
        }
};

int main(){
    /************TS Using DFS**********/
    // //graph "g" has been drawn in notebook
    // Graph g;
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 1);

    // g.addEdge(3, 5, 1);
    // g.addEdge(5, 6, 1);
    // g.addEdge(4, 6, 1);
    // g.addEdge(6, 7, 1);

    // // g.printAdjList();

    // unordered_map<int, bool> visited;
    // stack<int> ans;

    // //for() loop to handle disconnected graphs
    // for(int srcNode = 0; srcNode <= 7; srcNode++){
    //     if(visited[srcNode] == false){
    //         g.topoSortDFS(srcNode, visited, ans); //Topo Sort using DFS
    //     }
    // }

    // //Expected output : 0 1 2 3 5 4 6 7
    // cout<<"Topo Sort"<<endl;
    // while(!ans.empty()){
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // }

    /************TS Using BFS**********/
    // graph "g" has been drawn in notebook
    // "n" is number of nodes in graph
    int n = 8; 
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    g.addEdge(3, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(6, 7, 1);
  
    // unordered_map<int, bool<<visited;
    vector<int> ans; //"ans" will store the TS finally!
    
    //No need to handle disconnected graph separately here! [See "___for() loop 1" in function "topoSortBFS()"]
    g.topoSortBFS(n, ans);
    
    cout<<"Topo Sort"<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

    /**********Cycle Detection************/
    // //For graph g; g is Acyclic!
    // if(ans.size() == n){
    //     cout<<"Valid Topological Sort"<<endl;
    // }
    // else{
    //     //Invalid Topo Sort
    //     cout<<"Cycle Present in given graph!"<<endl;
    // }

    //g2 is Cyclic graph
    int m = 4; //m is no. of nodes in graph
    Graph g2;
    g2.addEdge(0, 1, 1);
    g2.addEdge(1, 2, 1);
    g2.addEdge(2, 3, 1);
    g2.addEdge(3, 1, 1);

    vector<int> ans2;
    g2.topoSortBFS(m, ans2);

    if(ans2.size() == m){
        cout<<"Valid Topological Sort"<<endl;
    }
    else{
        //Invalid Topo Sort
        cout<<"Cycle Present in given graph!"<<endl;
    }

return 0;
}
    