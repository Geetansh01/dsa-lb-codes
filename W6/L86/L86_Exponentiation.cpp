#include<iostream>
using namespace std;

//Fast Exponentiation (TC : O(log b))
int fastExponentiation(int a, int b) {
    int ans = 1;

    while(b > 0){
        if(b & 1){
            // if b (i.e power) is odd
            ans = ans * a;
        }
        a = a*a;
        b = b>>1; //This is : b = b/2
    }
    return ans; 
}

//Slow Exponentiation (TC : O(b))
int slowExponentiation(int a, int b){
    int ans = 1;

    for(int i = 0; i < b; i++){
        ans = ans*a;
    }

    return ans;
}

int main(){
    cout<<fastExponentiation(2, 5);

    cout<<endl;

    cout<<slowExponentiation(2, 5);
   
return 0;
}