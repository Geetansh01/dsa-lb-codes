#include <iostream>
#include<queue>
using namespace std;

/*****Find Median from Data Stream [LeetCode : https://leetcode.com/problems/find-median-from-data-stream/description/]******/

//M1, M2 are just diff coding styles, not diff approaches 
//To submit on LeetCode, same logic as below bss wahan class me implement krna hai

//M1 : Without switch case
void callMedian(double &median, int& element, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap){
    if(minHeap.size() == maxHeap.size()){
        if(element > median){
            //push element to right of median i.e in minHeap
            minHeap.push(element);
            median = minHeap.top();
        }
        else{
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }
    else if(maxHeap.size() > minHeap.size()){
        if(element > median){
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2.0;
        }
        else{
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2.0;
        }
    }
    else{
        // maxHeap.size() < minHeap.size()
        if(element > median){
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2.0;
        }
        else{
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2.0;
        }
    }
}

//M2 : using Switch case
// int signum(int a, int b){
//     if(a == b){
//         return 0;
//     }
//     if(a > b){
//         return 1;
//     }
//     if(a < b){
//         return -1;
//     }
// }

// void callMedian(double &median, int& element, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap){

//     switch(signum(minHeap.size(), maxHeap.size())){
//         case 0:
//             if(element > median){
//                 //push element to right of median i.e in minHeap
//                 minHeap.push(element);
//                 median = minHeap.top();
//             }
//             else{
//                 maxHeap.push(element);
//                 median = maxHeap.top();
//             }

//             break;
//         case 1:
//             // maxHeap.size() < minHeap.size()
//             if(element > median){
//                 int minTop = minHeap.top();
//                 minHeap.pop();
//                 maxHeap.push(minTop);
//                 minHeap.push(element);
//                 median = (minHeap.top() + maxHeap.top())/2.0;
//             }
//             else{
//                 maxHeap.push(element);
//                 median = (minHeap.top() + maxHeap.top())/2.0;
//             }

//             break;
//         case -1:
//             if(element > median){
//                 minHeap.push(element);
//                 median = (minHeap.top() + maxHeap.top())/2.0;
//             }
//             else{
//                 int maxTop = maxHeap.top();
//                 maxHeap.pop();
//                 minHeap.push(maxTop);
//                 maxHeap.push(element);
//                 median = (minHeap.top() + maxHeap.top())/2.0;
//             }

//             break;       
//     }
// }



int main(){
    // int stream[12] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4}; //Ans : 5 10 5 4 3 4 5 6 7 6.5 7 6.5 
    // int n = 12;

    int stream[6] = {5, 7, 2, 9, 3, 8}; //Ans : 5 6 5 6 5 6
    int n = 6;

    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(int i = 0; i < n; i++){
        int newElement = stream[i];
        callMedian(median, newElement, maxHeap, minHeap);

        cout<<"->"<<median<<" "<<endl;
    }
    cout<<endl;
    return 0;
}