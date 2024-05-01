#include <iostream>
#include <queue>
using namespace std;

struct Item{
    int value;
    int weight;
};

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int capacity, Item arr[], int n){
    vector<double> vwRatio; //value / weight ratio
    for(int i = 0; i < n; i++){
        // double ratio = (arr[i].value * 1.0)/ arr[i].weight; //Also works but using explicit type casting below
        double ratio = ( static_cast<double>(arr[i].value) ) / arr[i].weight;
        vwRatio.push_back(ratio);
    }

    priority_queue<pair<double, pair<int, int> > > maxH; //max heap : ratio, value, weight; Automatically maxHeap 1st argument i.e "ratio" ke basis pe bnega

    for(int i = 0; i < n; i++){
        maxH.push({vwRatio[i], {arr[i].value, arr[i].weight}});
    }

    //max Heap is ready, so start filling knapSack
    double totValue = 0;
    while(capacity != 0 && !maxH.empty()){
        auto item = maxH.top();
        maxH.pop();
        double ratio = item.first;
        int value = item.second.first;
        int weight = item.second.second;

        //either "item" FULL insert hoga
        if(capacity >= weight){
            totValue += value;
            capacity -= weight;
        }
        else{
            //or PARTIALLY i.e break hoke insert hoga
            double valueToInclude = ratio * capacity;
            totValue += valueToInclude;
            capacity = 0; //Bcz item break krke le ra hu to capacity to ab FULL hojaegi
            break;
        }
    } 

    return totValue;
}

int main()
{

    return 0;
}