#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int target){
    int mid = s + (e-s)/2;

    while(s <= e){
        if(arr[mid]==target){
            return mid;
        }

        else if(target < arr[mid]){
            e = mid - 1;
        }

        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return mid;
}

int expSearch(int arr[], int n, int target){
    if(arr[0] == target){
        return 0;
    }

    int i = 1;
    while(i < n && arr[i] < target){
        i = i*2;
    }

    return binarySearch(arr, i/2, min(i, n-1), target);
}

int main(){
   int array[] = {1,2,7,11,13,14,15};
   int size = sizeof(array)/sizeof(array[0]);
   int target = 13;

   cout<<expSearch(array, size, target)<<endl;
return 0;
}