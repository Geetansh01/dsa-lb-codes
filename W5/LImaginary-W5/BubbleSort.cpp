
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    //Outer Loop (n-1) times
    for(int i = 1; i < n; i++){
        
        bool swapmade = false;

        for(int j = 0; j < (n-i); j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapmade = true;
            }
        }

        if(swapmade == false){
            //Already sorted
            break;
        }
    }
}


int main(){
   vector<int> arr = {2,0,4,4,1,5,6};
   bubbleSort(arr);
   for(auto iter : arr){
    cout<<iter<<' ';
   }
return 0;
}