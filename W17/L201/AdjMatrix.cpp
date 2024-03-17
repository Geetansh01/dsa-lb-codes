#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n; 
    cout<<"Enter number of nodes: "<<endl;
    cin>>n;
    //Initialise AdjMatrix
    vector<vector<int> > adjMatrix(n, vector<int>(n, 0));   


    int e;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;

    //Instead of Having an "edge List" like in NoteBook code, we ask the user to input all the edges (TC remains same as user acts as "edge List")
    for(int i = 0; i < e; i++){
        int u, v;
        cin>>u>>v;
        adjMatrix[u][v] = 1; //For weighted graph, insert "weight" here instead of "1"
    }

    //Printing Adjacency Matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
return 0;
}