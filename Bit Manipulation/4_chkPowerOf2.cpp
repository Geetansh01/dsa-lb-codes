#include<iostream>
using namespace std;

//M1
bool chkPowerOf2(int n){
    //Count set bit
    int count = 0;

    while(n != 0){
        int lastBit = n & 1;
        if(lastBit == 1){
            count++;
        }
        n = n >> 1;
    }

    if(count == 1){
        return true;
    }
    else{
        return false;
    }
}

//M2
bool fastChkPowerOf2(int n){
    if((n & (n-1)) == 0){
        return true;
    }
    else{
        return false;
    }
}

//Fast way to count set bits
int fastCountSetBits(int n){
    int count = 0;
    while(n != 0){
        count++;
        n = (n & (n-1));
    }

    return count;
}

int main(){
    int n = 16;

    //M1
    cout<<"Is n power of true: ";
    cout<<chkPowerOf2(n)<<endl;

    //M2
    cout<<"Is n power of true: ";
    cout<<fastChkPowerOf2(n)<<endl;

    int m = 1024;
    cout<<"Is m power of true: ";
    cout<<fastChkPowerOf2(m)<<endl;

    //Fast way to count set bits
    int k = 7; //has 3 set bit : 0111
    cout<<fastCountSetBits(k); 

return 0;
}