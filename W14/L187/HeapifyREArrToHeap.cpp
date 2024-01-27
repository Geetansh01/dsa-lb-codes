#include<iostream>
#include<limits.h>
using namespace std;

/***********Heapify using RE*************/ 
void heapify(int *arr, int n, int index){
    int leftChildIndex = 2*index;
    int rightChildIndex = 2*index + 1;
    int largestKaIndex = index;

    //Teeno me se largest

    // Note : every valid index should be less than or equal to "n"
    if(leftChildIndex <= n && arr[leftChildIndex] > arr[largestKaIndex]){
        largestKaIndex = leftChildIndex;
    }
    if(rightChildIndex <= n && arr[rightChildIndex] > arr[largestKaIndex]){
        largestKaIndex = rightChildIndex;
    }

    //Now "largestKaIndex" is pointing to largest element
    if(index != largestKaIndex){
        //Ek Step Hm
        swap(arr[index], arr[largestKaIndex]);
        index = largestKaIndex;

        //Baki RE
        heapify(arr, n, index);
    }
    else{
        //Base Case
        //STOP, heapify completed
        return;
    }
}

/*******Array to Heap**********/
void buildHeap(int arr[], int n){
    for(int index = n/2; index > 0; index--){
        heapify(arr, n, index);
    }
}


int main(){

    int arr[] = {INT_MIN, 12, 15, 13, 11, 14}; //As we are following 1 based indexing so index 0 is ignored completely!
    buildHeap(arr, 5); //passing size 5 as we are ignoring the existence of index 0!


    for(int i = 1; i < 6; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}


