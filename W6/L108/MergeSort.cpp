#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;
    // int arr[n] //BAD PRACTICE

    //Dynamically making arrays
    int* left = new int[len1];
    int* right = new int[len2];

    //copy values
    int k = s;
    for(int i = 0; i < len1; i++){
        left[i] = arr[k];
        k++;
    }

    k= mid + 1;
    for(int i = 0; i < len2; i++){
        right[i] = arr[k];
        k++;
    }

    //Merging left and right
    int leftIndex = 0; 
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex < len1 && rightIndex < len2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex]  = left[leftIndex];
            mainArrayIndex++; leftIndex++;
        }
        else{
            arr[mainArrayIndex++]  = right[rightIndex++];
        }
    }

    while(leftIndex < len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }
    while(rightIndex < len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    //Delete left and right wala dynamic array
    delete[] left;
    delete[] right;


}

void mergeSort(int* arr, int s, int e){
    //Base Case
    //if s == e --> Single element
    //if s > e --> invalid array
    if(s >= e){
        return;
    }

    int mid = s+(e-s)/2;
    //Sort left part using recursion
    mergeSort(arr, s, mid);

    //Sort right part using recursion
    mergeSort(arr, mid + 1 , e);

    //Now merge two sorted left and right part arrays
    merge(arr, s, e);
}

int main(){
   int arr[] = {4,5,5,13,2,12};
   int n = 6;

   int s = 0;
   int e = n-1;
   mergeSort(arr, s, e);

   for(int i = 0; i <= e; i++){
    cout<<arr[i]<<" ";
   }

return 0;
}