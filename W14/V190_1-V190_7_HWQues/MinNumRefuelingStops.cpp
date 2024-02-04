#include<iostream>
#include<queue>
using namespace std;

/****V190_6 : Minimum Number of Refueling Stops[LeetCode : https://leetcode.com/problems/minimum-number-of-refueling-stops/description/]*****/

//TC : O(n logn)

class compare{
    public:
    bool operator () (pair<int, int>& p1, pair<int, int>& p2){
        //max heap on basis of which station offers more petrol
        return p1.second < p2.second;
    }
};

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int stops = 0;
    int dist = 0; //distance travelled
    int i = 0; 
    int fuel = startFuel;
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> maxH; //{position, fuel}
    while(true){
        while(i < stations.size()){
            //push stations within the reach with my current fuel level from my current pos into max heap
            if(stations[i][0] <= dist + fuel){
                maxH.push({stations[i][0], stations[i][1]}); //{position, fuel}
            }
            else{
                break;
            }
            i++;
        }

        
        //travel with the entire fuel you have (& go as far as you can)
        dist += fuel;
        fuel = 0;

        //if reached
        if(dist >= target) break;

        //target pe nhi phuche & No fuel stations in max heap
        if(maxH.empty()){
            stops = -1;
            break;
        }

        //if not reached on target then refuel krenge from a previous station in the max heap
        //Also readjust dist & fuel based on distance travelled and fuel used till that station
        auto top = maxH.top();
        fuel = (dist - top.first) + top.second;
        dist = top.first;
        maxH.pop(); //means iss station se fuel bhrwa liya
        stops++; 
    }

    return stops;
}

int main(){
   
return 0;
}