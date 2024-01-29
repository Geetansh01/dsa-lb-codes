#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Info{
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int data, int rI, int cI){
            this->data = data;
            this->rowIndex = rI;
            this->colIndex = cI;
        }
};

//Writing a Function object / Functor 
class compare{
    public:
     bool operator()(Info* a, Info* b){
        return a->data > b->data;
     }
};


void mergeKSortedArrays(int arr[][4], int n, int k, vector<int>& ans){
    priority_queue<Info*, vector<Info*>, compare> pq;

    //Step 1 : Process First K elements
    for(int row = 0; row < k; row++){
        int element = arr[row][0];
        Info* temp = new Info(element, row, 0);
        pq.push(temp);
    } 

    while(!pq.empty()){
        Info* temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        delete temp; //Prevent Memory Leakage

        //Store ans in vector
        ans.push_back(topData);

        //Insert next element of the same array/row jiska abhi ans me push hua hai
        if(topCol + 1 < n){
            //Means row/array me more elements present hai
            Info* newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(newInfo);
        } 
    }
};

//////////////////////////////////////////////////////////////////
/*
    1)Same Logic as above but this time not using pointers but rather the objects of Info class directly (So, objects are being made statically in stack rather than in heap)
    2)This is not efficient at all, objects are being copied & object bht sari memory leta hai, so we are wasting both Time & Space by moving the objects themselves ! 
        For ex: in line ...(1), we made a heap of "Info" objects, every time an object is pushed into the heap, it is being copied
    3)So whenever objects are involved, make the objects in heap and use pointers to manipulate them, that woud be better!
*/

// // Writing a Function object / Functor
// class compare{
//     public:
//      bool operator()(Info a, Info b){
//         return a.data > b.data;
//      }
// };


// void mergeKSortedArrays(int arr[][4], int n, int k, vector<int>& ans){
//     priority_queue<Info, vector<Info>, compare> pq;

//     //Step 1 : Process First K elements
//     for(int row = 0; row < k; row++){
//         int element = arr[row][0];
//         Info temp = Info(element, row, 0);
//         pq.push(temp);
//     } 

//     while(!pq.empty()){
//         Info temp = pq.top();
//         pq.pop();
//         int topData = temp.data;
//         int topRow = temp.rowIndex;
//         int topCol = temp.colIndex;

//         //Store ans in vector
//         ans.push_back(topData);

//         //Insert next element of the same array/row jiska abhi ans me push hua hai
//         if(topCol + 1 < n){
//             //Means row/array me more elements present hai
//             Info newInfo = Info(arr[topRow][topCol + 1], topRow, topCol + 1);
//             pq.push(newInfo);
//         } 
//     }

// };

int main(){
    int arr[3][4] = {
                    {1, 4, 8, 10},
                    {2, 3, 6, 9},
                    {5, 7, 11, 12},
                    };
    int n = 4;
    int k = 3;

    vector<int> ans;
    mergeKSortedArrays(arr, n, k, ans);

    cout<<"Printing Ans Array : "<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

return 0;
}


