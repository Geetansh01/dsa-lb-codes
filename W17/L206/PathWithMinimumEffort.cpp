#include<bits/stdc++.h>
using namespace std;

//Main Logic : Dijkstra's Algo
class Triplet{
    public:
        int distance; //distance from source
        int row;
        int col;

        Triplet(int d, int r, int c){
            distance = d;
            row = r;
            col = c;
        }
};
typedef Triplet Trp;

class Compare{
    public:
        bool operator () (Trp A, Trp B){
            return A.distance > B.distance;
        }
};

int dijkstra(vector<vector<int>>& heights){
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
    distance[0][0] = 0;

    priority_queue<Trp, vector<Trp>, Compare> pq;
    Trp src(0, 0, 0);
    pq.push(src);

    while(!pq.empty()){
        Trp currSrc = pq.top();
        pq.pop();

        //Optimization : Dijkstra will get shortest distances from our "src" to all others but we don't need that
        //Agr already destination pr aa gye to stop and return the answer!
        if(currSrc.row == rows-1 && currSrc.col == cols - 1){
            return currSrc.distance;   //line __(1)
        }

        //Try to update neighbours of "currSrc";
        vector<int> dx = {0, +1, 0, -1};
        vector<int> dy = {-1, 0, +1, 0};
        for(int index = 0; index < 4; index++){
            int newRow = currSrc.row + dy[index];
            int newCol = currSrc.col + dx[index];
            if(newRow < rows && newRow >= 0 && newCol < cols && newCol >= 0){

                //NOTE : I have modified the usual logic of neighbour's distance updation (So it's not same as simple Dijkstra)
                //This modification was needed bcz of how this Ques defined the distance from source to destination as "maximum absolute difference in heights between two consecutive cells of the route" (See ques) and NOT the sum of weights on all edges in the route!

                int newDistance = max(currSrc.distance, abs(heights[currSrc.row][currSrc.col] - heights[newRow][newCol]) ); //This is the modification. See how the "newDistance" is NOT "distance(u) + cost(u, v)" as it is in simple Dijkstra!

                //Rest same as simple Dijkstra
                int oldDistance = distance[newRow][newCol];
                if(newDistance < oldDistance){
                    //Update neighbour's distance
                    distance[newRow][newCol] = newDistance;

                    //push neighbour with new distance in "pq"
                    Trp nbr(newDistance, newRow, newCol);
                    pq.push(nbr);
                }
            }
        }
    }

    //I won't ever actually reach below line as i am returning answer above in line __(1)
    return distance[rows - 1][cols - 1];
}

int minimumEffortPath(vector<vector<int>>& heights) {
    //Solution using Dijkstra's Algo

    int minPair = dijkstra(heights);

    return minPair;
}

int main(){
   
return 0;
}