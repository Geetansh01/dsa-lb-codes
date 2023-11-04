#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//This function will return vector<int> with primes less than or equal to "n"
vector<int> NormalSoE(int n){
    vector<int> ans; //this will be the array containing all primes less than or equal to n

    vector<bool> sieve(n+1, true);
    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i*i <= n; i++){  //OR i <= sqrt(n)
        if(sieve[i]){

            int j = i*i;
            while(j <= n){
                sieve[j] = false;
                j = j + i;
            }
        }
    }

    for(int i = 0; i < sieve.size(); i++){
        if(sieve[i]){
            ans.push_back(i);
        }
    }

    return ans;
}

//Segmented Sieve of Eratosthenes (SSoE)
//This function will give the array containing all primes between "L" and "R" (including "L" and "R")
vector<int> SSoE(int L, int R){
    //0 and 1 are never primes
    if(L == 0) L = L+2;
    if(L == 1) L++; 
    if(L > R){
        return {-1};
    }

    vector<int> ans; //this will be the array containing all primes between "L" and "R" (including "L" and "R")

    //Generate primes needed to cancel factors in Segmented Sieve
    vector<int> primes = NormalSoE(sqrt(R));

    //Make Segmented Sieve (ss)
    vector<bool> ss(R-L+1, true);

    //Cancel the non-prime numbers
    for(int i = 0; i < primes.size(); i++){

        int first_factor = (L/primes[i]) * primes[i];
        if(first_factor < L){
            first_factor = first_factor + primes[i];
        }

        int j = max(first_factor, primes[i] * primes[i]);
        while(j <= R){
            ss[j-L] = false;
            j = j + primes[i];
        }
    }

    for(int i = 0; i < ss.size(); i++){
        if(ss[i]){
            ans.push_back(i+L);
        }
    }

    //return "ans"
    return ans;

}


int main(){

    // int L = 1;
    // int R = 1;

    // int L = 1;
    // int R = 0;

    // int L = 5;
    // int R = 5;
    
    int L = 110;
    int R = 130;
    vector<int> list = SSoE(L, R);

    for(int i = 0; i < list.size(); i++){
        cout<< list[i] <<" ";
    }

   
return 0;
}