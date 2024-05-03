#include<iostream>
using namespace std;

/*
    Note that you can also find if a number is even or odd using modulus operator(%), but it's a heavy operator so avoid it if you can. 
*/

void checkEvenOdd(int n){
    if(n & 1){
        cout<<"Odd"<<endl;
    }
    else{
        cout<<"Even"<<endl;
    }
}

int main(){
   int x = 19;
   checkEvenOdd(x);
return 0;
}