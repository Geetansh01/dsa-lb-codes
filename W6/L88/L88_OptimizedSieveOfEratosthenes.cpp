#include<iostream>
#include<vector>
using namespace std;

//This function will return vector<bool> with "true" on prime indexes less than "n"
vector<bool> Sieve(int n){
    vector<bool> sieve(n, true);
    sieve[0] = false;
    sieve[1] = false;

    // for(int i = 2; i<n; i++){...} //Unoptimized Way

    for(int i = 2; i*i <= n; i++){  //Optimization 2 (or i <= sqrt(n))
        if(sieve[i]){

            // int j = i*2; //Unoptimized approach
            
            int j = i*i; //Optimization 1
            while(j < n){
                sieve[j] = false;
                j = j + i;
            }
        }
    }

    return sieve;
}

int main(){
    int a = 5;
    vector<bool> list = Sieve(a);

    for(int i = 0; i < list.size(); i++){
        if(list[i]) cout<<i<<" ";
    }
    
    return 0;
}