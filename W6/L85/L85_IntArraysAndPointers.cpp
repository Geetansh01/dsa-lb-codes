#include<iostream>
using namespace std;


int main(){
    //Base Address of an array
    int arr[3] = {1,2,3};
    cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<&arr<<endl;

    int* p = arr;
    cout<<p<<endl;
    cout<<&p<<endl;

    //Accessing elements of array
    cout<<arr[2]<<endl;
    cout<<2[arr]<<endl;
    cout<<*(arr + 2)<<endl;
    cout<<*(&arr[2])<<endl;

    //Array vs Pointer
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(p)<<endl;
    
return 0;
}