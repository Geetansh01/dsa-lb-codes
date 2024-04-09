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

    void shortestPathDijkstra(int sourceNode, int totNodes){
        vector<int> distance(totNodes, INT_MAX);
        set< pair<int, int> > st; //stores {distance of Node, Node itself}

        //Set distance of source to 0
        distance[sourceNode] = 0;
        st.insert(make_pair(0, sourceNode));

        while(!st.empty()){
            //Fetch the Node with Least elemnt from "st", it will be in the beginning of the set 
            auto topElement = *(st.begin()); //st.begin() is iterator to 1st element in set, dereference it to get the actual element itself (This actual element will be a std::pair<int, int> )
            int nodeDistance = topElement.first;
            int node = topElement.second;

            //Bcz "topElement" has been fetched so remove it from set 
            st.erase(st.begin());

            //Try to Update distances of neighbours of "node"
            for(auto neighbourPair : adjList[node]){
                int neighbour = neighbourPair.first;

                if(nodeDistance + neighbourPair.second < distance[neighbour]){
                    //Now, distance of neighbour needs to be updated in "distance[]" array and in the "st" (if it is present there!)
                    
                    //Search in "st"
                    auto searchResult = st.find(make_pair(distance[neighbour], neighbour));
                    //If found then remove from "st"
                    if(searchResult != st.end()){
                        //"st" me already neighbour ki entry pdi hai (with it's old distance). Iss entry ko htao
                        st.erase(searchResult); //"searchResult" is the iterator to the found entry of neighbour
                    }

                    distance[neighbour] = nodeDistance + neighbourPair.second; //Update in "distance[]"
                    st.insert(make_pair(distance[neighbour], neighbour)); //Update in "st"
                }

            }
        }

        cout<<"Printing Distance[] array"<<endl;
        for(int i = 0; i < totNodes; i++){
            cout<<distance[i]<<", ";
        }
        cout<<endl;

    }
};


int main(){
    Graph g;

    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(3, 1, 9, 0);
    g.addEdge(3, 2, 10, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(4, 5, 6, 0);

    // g.printAdjList();
    
    int sourceNode = 6;
    int totNodes = 7;  //Why 7 when there are only 6 nodes in the graph? Because, we are considering the nodes from 0 to 6 [See size of distance[] array from notebook]
    g.shortestPathDijkstra(sourceNode, totNodes);


return 0;
}