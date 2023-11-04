#include<iostream>
using namespace std;

int partition(int* arr, int s, int e){
    //step1 : choose pivot element
    int pivotIndex = s;
    int pivotElement = s;

    //Step2 : Find right position for pivot element and place pivot there
    int count = 0;
    for(int i = s+1; i <=e; i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    //Now place pivot element at correct position
    int correctIndexOfPivotElement = count + s;
    swap(arr[pivotIndex], arr[count + s]);
    pivotIndex = correctIndexOfPivotElement;

    //Step3 : left me chote right me bade
    int i = s;
    int j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivotElement){
            i++;
        }
        while(arr[j] > pivotElement){
            j--;
        }

        //2 cases possible
            //case 1 : you found the elements to swap (left me pivot se bade mil gye ya right me pivot se chote)
            //B : no need to swap
            if(i < pivotIndex && j > pivotIndex){
                swap(arr[i], arr[j]);
            }
    }

    return pivotIndex;
}

void quickSort(int* arr, int s, int e){
    //base case
    if(s >= e){
        return;
    }

    //partition logic , p is the index of pivot element
    int p = partition(arr, s, e);

    //recursive calls
    //pivot element ke left ki call 
    quickSort(arr, s, p-1);
    
    //pivot element ke right ki call 
    quickSort(arr, p+1, e);
}

int main(){
   int arr[] = {8,1,3,4,4,20,20,50,30};
   int n = 9;
   int s = 0;
   int e = n-1;
   quickSort(arr, s, e);

   for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
   }
return 0;
}