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

    void dfs1(int sourceNode, stack<int>& st, unordered_map<int, bool>& visited){
        //1 case Hm
        visited[sourceNode] = true;

        //RE Calls for all neighbours
        for(int neighbour : adjList[sourceNode]){

            if(visited[neighbour] == false){
                //RE Call only if neighbour not already visited!
                dfs1(neighbour, st, visited);
            }
        }

        st.push(sourceNode);
    } 

    void dfs2(int sourceNode, unordered_map<int, bool>& visited, unordered_map<int, list<int> >& revAdjList){
        //1 case Hm
        visited[sourceNode] = true;
        cout<<sourceNode<<", ";

        //RE Calls for all neighbours
        for(int neighbour : revAdjList[sourceNode]){

            if(visited[neighbour] == false){
                //RE Call only if neighbour not already visited!
                dfs2(neighbour, visited, revAdjList);
            }
        }
    }  

    int countSCC(int totNodes){
        stack<int> st;
        unordered_map<int, bool> visited;

        //Step 1 : Call DFS for all nodes
        for(int i = 0; i < totNodes; i++){
            if(visited[i] == false){
                dfs1(i, st, visited);
            }
        }

        //Step 2 : Reverse the Graph
        unordered_map<int, list<int> > revAdjList;
        for(auto i : adjList){
            int u = i.first;
            for(auto v : i.second){
                //Insert edge v ---> u
                revAdjList[v].push_back(u);
            }
        }

        //Step 3 : Again call DFS and Count SCCs
        int sccCount = 0;
        unordered_map<int, bool> visited2;
        while(!st.empty()){
            int topNode = st.top();
            st.pop();

            if(visited2[topNode] == false){
                cout<<"Printing SCC"<<sccCount + 1<<" : ";

                dfs2(topNode, visited2, revAdjList);
                sccCount++;
                
                cout<<endl;
            }
        }

        return sccCount;

    }
};


int main(){
    //Graph g is drawn in notebook
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);

    int totNodes = 8;

    cout<<"Total SCC count : "<<g.countSCC(totNodes);
    return 0;
}

