#include<bits/stdc++.h>
using namespace std;

//Main Logic : Use Floyd Warshall to get the distance[][] matrix and then see for each citiy, how many cities can be reached within distanceThreshold

//TC : O(n^3) 
//My soln below!
//code for floydWarshall() copied from "L207 : FLoydWarshallAlgo.cpp"
void floydWarshall(int totNodes, vector<vector<int> >& distance, vector<vector<int>>& edges){
    //Fill diagonal with 0
    for(int i = 0; i < totNodes; i++){
        distance[i][i] = 0;
    }

    //Step D0 : Fill the weights from graph into "distance[][]"
    //So, get all edges from graph
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2]; //weight 

        //Note that pehle Diagonal pe 0's dale the vo override nhi krne
        if(u != v){
            distance[u][v] = weight;
            distance[v][u] = weight;
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
    return;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //Use Floyd Warshall to get the distance[][] matrix
    vector<vector<int> > distance(n, vector<int>(n, INT_MAX));
    floydWarshall(n, distance, edges);

    //traverse distance[][] matrix and get your answer
    int ansCity = 0;
    int minReachableCount = INT_MAX;
    for(int i = 0; i < n; i++){
        int reachableCities = 0;
        for(int j = 0; j < n; j++){
            if(distance[i][j] <= distanceThreshold) reachableCities++;
        }

        if(reachableCities < minReachableCount){
            ansCity = i;
            minReachableCount = reachableCities;
        }
        else if(reachableCities == minReachableCount && i > ansCity){
            ansCity = i;
        }
        else{
            //Nothing
        }
    }

    return ansCity;
}

//M2 : Use Dijkstra's Algorithm for each city and then see for each city, how many cities can be reached within distanceThreshold
/*
    TC : O(n^3 Log n) 
    
    => O(V * (E Log V)) ;   V = no. of cities/vertices = n 
                            E = no. of edges = n(n-1) = n^2

*/

int main(){
   
return 0;
}