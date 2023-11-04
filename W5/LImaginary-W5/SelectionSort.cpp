#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr) {
    // Write your code here.
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int minIndex = i;

        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main(){
   vector<int> arr = {2,0,4,4,1,5,6};
   selectionSort(arr);
   for(auto iter : arr){
    cout<<iter<<' ';
   }
return 0;
}