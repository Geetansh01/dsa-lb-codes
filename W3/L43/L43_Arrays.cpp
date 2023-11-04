#include<iostream>
#include<limits.h> //For INT_MIN / INT_MAX
using namespace std;

/******************Printing Array*************************/
int PrintArray(int* arr, int size);

/******************Max/ Min No in an Array*************************/
int max(int* arr, int size);

/******************Printing Extremes In Array*************************/
int printExtremes(int* arr, int size);

/******************Reverse Array*************************/
int ReverseArray(int* arr, int size);

int main(){
   int arr[12] = {1,20,3,-4,5,78,8,-9,1,2,3,12};
   max(arr, 12);

   int arr2[7] = {1,2,3,4,5,6,7};
   printExtremes(arr2, 7);

   int arr3[7] = {1,2,3,4,5,6,7};
   ReverseArray(arr3, 7);
   PrintArray(arr3, 7);

return 0;
}


int max(int* arr, int size){
    /*
    Whenever u need to find Max No. , it's good practice to initialize with INT_MIN
    Whenever u need to find Min No. , it's good practice to initialize with INT_MAX
    */
    int max = INT_MIN;
    int min = INT_MAX;

    for(int i = 0; i < size; i++){
        //Found a number greater than max
        if(arr[i] > max){
            max = arr[i];

        //Found a number smaller than min
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout<<"Max No : "<<max<<endl;
    cout<<"Min No : "<<min<<endl;
}


int printExtremes(int* arr, int size){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        //To Avoid Double printing In cases where size of array is ODD number
        if(start == end){
            cout<<arr[start];
        }
        else{
            cout<<arr[start];
            cout<<arr[end];
        }     
        start++;
        end--;
    }

    return 0;
}


int ReverseArray(int* arr, int size){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        int temp;
        //Step 1: Swap
            //Using Predefined Function swap() to swap
            swap(arr[start], arr[end]);

            //Manual Way To swap
            // temp = arr[start];
            // arr[start] = arr[end];
            // arr[end] = temp;

        //Step 2 : Increment " start " and Decrement " end "
        start++;
        end--;
    }
    cout<<endl;

    return 0;
}


int PrintArray(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}