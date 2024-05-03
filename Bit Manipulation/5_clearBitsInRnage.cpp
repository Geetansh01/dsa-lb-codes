#include<iostream>
using namespace std;

void clearBitsInRange(int n, int i, int j){
    int a = (-1 << (i+1));
    int b = (1 << j) - 1;
    int mask = a | b;
    n = n & mask;
    cout<<"n after clearing bits in range: "<<n<<endl;
}

int main(){
    int n = 15;
    int i = 2;
    int j = 1;
    clearBitsInRange(n, i, j);

    cout<<(~0)<<endl;
return 0;
}