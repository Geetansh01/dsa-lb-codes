#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

/**********************Count Primes [LeetCode : https://leetcode.com/problems/count-primes/description/]**************************************/

//M1 : Naive Approach (T.C : O(n^2))
// bool isPrime(int x){
//     for(int i = 2; i < x; i++){
//         if(x%i == 0){
//             return false;
//         }
//     }
//     return true;
// }

// int countPrimes(int n) {
//     if(n==0) return 0;
//     if(n==1) return 0;

//     int count = 0;
//     for(int i = 2; i < n; i++){
//         if(isPrime(i)){
//             count++;
//         }
//     }
//     return count;
// }

//M2 : Sqrt Approach (T.C : O(n Sqrt(n)))
// bool isPrime(int x){
//     int sqrtOfX = sqrt(x);
//     for(int i = 2; i <= sqrtOfX; i++){
//         if(x%i == 0){
//             return false;
//         }
//     }
//     return true;
// }

// int countPrimes(int n) {
//     if(n==0) return 0;
//     if(n==1) return 0;

//     int count = 0;
//     for(int i = 2; i < n; i++){
//         if(isPrime(i)){
//             count++;
//         }
//     }
//     return count;
// }

//M3 : Sieve of Eratosthenes (T.C : O(N log(logN)) )
int countPrimes(int n) {
    if(n==0) return 0;
    if(n==1) return 0;

    vector<bool> sieve(n, true); //true means no is prime
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
    cout<<countPrimes(10)<<endl;
   
return 0;
}