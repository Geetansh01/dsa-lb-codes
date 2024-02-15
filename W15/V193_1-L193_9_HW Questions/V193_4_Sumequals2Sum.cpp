#include<iostream>
#include<unordered_map>
using namespace std;

/**V193_4 : Sum equals to Sum [GFG : https://www.geeksforgeeks.org/problems/sum-equals-to-sum4006/1]***/

//TC : O(n^2) {Avg Case}
//TC : O(n^3) {Worst Case} --> taking searching in unordered_map to be TC : O(n)
//SC : O(n^2) {Bcz of unordered map}
int findPairs(long long a[], long long n)
{
    unordered_map<long long, bool> mp; //sum --> present or not
    
    for(long long i = 0; i < n; i++){
        for(long long j = i+1; j < n; j++){
            int sum = a[i] + a[j];
            if(mp[sum] == true){
                return 1;
            }
            else{
                mp[sum] = true;
            }
        }
    }
    
    return 0;
}

int main(){
   
return 0;
}