#include<iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k){
    priority_queue<int> pq;  //pq is a max-heap

    //1st k ko pq me dalo
    for(int i = 0; i < k; i++){
        int element = arr[i];
        pq.push(element);
    }

    //Remaining elements pushed only if it's smaller than root of max-heap
    for(int i = k; i < n; i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;
}

int getKthGreatestElement(int arr[], int n, int k){
    priority_queue< int, vector<int>, greater<int> > pq;  //pq is a min-heap

    //1st k ko pq me dalo
    for(int i = 0; i < k; i++){
        int element = arr[i];
        pq.push(element);
    }

    //Remaining elements pushed only if it's greater than root of max-heap
    for(int i = k; i < n; i++){
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;
}

int main(){
    int arr[] = {3,5,4,6,9,8,7}; //Sorted : 3,4,5,6,7,8,9
    int n = 7;
    int k = 4;
    cout<<"4th Smallest Element is : "<<getKthSmallestElement(arr, n, k);

    cout<<endl;

    cout<<"3rd Largest Element is : "<<getKthGreatestElement(arr, n, 3);
    

    return 0;
}