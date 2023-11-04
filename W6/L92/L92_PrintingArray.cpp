#include<iostream>
using namespace std;

//Printing Array using RE
void print(int A[], int s, int i){
    //Base Case
    if(i >= s){
        return;
    }

    cout<<A[i]<<" ";
    print(A, s, i+1);
}


int main(){
   int arr[5] = {1,2,3,4,5};
   int size = 5;
   int i = 0;

   print(arr, size, i);
return 0;
}