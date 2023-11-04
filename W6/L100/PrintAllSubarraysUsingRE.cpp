#include<iostream>
using namespace std;

/******************100. Print All Subarrays Using RE**************************/
void printSubArrays(string& str, int s = 0, int e = 0){
    //Base Case
    if(e >= str.length()){
        printSubArrays(str, s+1, s+1);
    }
    if(s >= str.length()){
        return;
    }

    //1 case solve kro
    cout<<str.substr(s, e-s+1)<<endl;

    printSubArrays(str, s, e+1);

}

int main(){
    string str = "abcdefghij";
    printSubArrays(str);
   
return 0;
}