#include<iostream>
using namespace std;

/*
    Ques : Given a integer N, count All Set Bits in it. 
    (N is non-negative integer)                               
*/

//M1 : Bit manipulation
int countSetBits(int n){
    int count = 0;
    while(n > 0){
        int bit = n & 1;
        if(bit == 1) count++;
        n = n>>1;
    }
    return count;
}

//M2 : Converrt number to Binary
int countSetBits2(int n){
    int count = 0;
    while(n > 0){
        int bit = (n%2);
        if(bit == 1) count++;
        n = n / 2;
    }
    return count;
}

int main(){
//    int N = -8; //Does not work for (-ve)s
   int N = 8;
   cout<<countSetBits(N)<<endl;
   cout<<countSetBits2(N)<<endl;
return 0;
}