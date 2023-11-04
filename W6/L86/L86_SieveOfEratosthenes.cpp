#include<iostream>
#include<vector>
using namespace std;

/************[LeetCode : https://leetcode.com/problems/count-primes/description/]**********************************************/
//This is Unoptimized Sieve of Eratosthenes
//See L88 for optimized version

//This function will return count of primes less than "n"
int countPrimes(int n) {
    if(n==0) return 0;
    if(n==1) return 0;

    vector<bool> sieve(n, true);
    sieve[0] = false;
    sieve[1] = false;

    int count = 0;

    for(int i = 2; i<n; i++){
        if(sieve[i]){
            count++;
        
            int j = 2*i;

            while(j < n){
                sieve[j] = false;
                j = j + i;
            }
        }
    }

    return count;
}

int main(){
   cout<<countPrimes(11); //output : 4 (2,3,5,7)
return 0;
}