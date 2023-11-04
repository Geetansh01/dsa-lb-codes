#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> arr){
    int n = arr.size();

    //Outer loop runs (n-1) times    
    for(int i = 1; i < n; i++){
        
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp; 
    }
}

int main(){
   vector<int> arr = {2,0,4,4,1,5,6};
   insertionSort(arr);
   for(auto iter : arr){
    cout<<iter<<' ';
   }
return 0;
}