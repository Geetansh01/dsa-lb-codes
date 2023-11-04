#include<iostream>
#include<vector>
using namespace std;


int main(){
   vector<int> arr;

/******************Default Size of Vector************************/
//    int ans = sizeof(arr)/sizeof(int);
//    cout<<ans<<endl; //this will give different answers on different compilers

//    cout<<arr.size()<<endl;         //Most Compilers will give : 0
//    cout<<arr.capacity()<<endl;    //Most Compilers will give : 0

/**********************Insert/ Remove Elements*******************************/
// arr.push_back(5);
// arr.push_back(6);

// for(int i = 0; i < arr.size(); i++){
//     cout<<arr[i]<<endl;
// }

// arr.pop_back();

// for(int i = 0; i < arr.size(); i++){
//     cout<<arr[i]<<endl;   
// }

/************Another way to initialise**************************/
// vector<int> brr(10); 
// vector<int> brr2(10, -1);

// cout<<"Size : "<<brr.size()<<endl; //10
// cout<<"Capacity : "<<brr.capacity()<<endl; //10

// cout<<"Size : "<<brr2.size()<<endl; //10
// cout<<"Capacity : "<<brr2.capacity()<<endl; //10

// for (int i = 0; i < brr.size(); i++){
//     cout<<brr[i]<<" ";
// }

// cout<<endl;

// for (int i = 0; i < brr2.size(); i++){
//     cout<<brr2[i]<<" ";
// }

/************Another way to initialise**************************/
// int n;
// cin>>n;

// vector<int> vec(n, -2);
// for(int i = 0; i < vec.size(); i++){
//     cout<<vec[i]<<" ";
// }


return 0;
}