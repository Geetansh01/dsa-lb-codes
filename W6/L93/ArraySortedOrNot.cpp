#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int>& v, int& n, int i){
    //Base Case
    if(i == n-1){
        return true;
    }

    //1 Case Hm solve krenge
    if(v[i+1] < v[i]){
        return false;
    }

    //baki cases recursion sambhalega 
    return checkSorted(v, n, i+1);

}

int main(){
   vector<int> v{10,20,30,50,60};
   int n = v.size();
   int i = 0;

   bool isSorted = checkSorted(v, n, i);

   if(isSorted){
    cout<<"Array Sorted"<<endl;
   }
   else{
    cout<<"Array Not Sorted"<<endl;
   }
return 0;
}