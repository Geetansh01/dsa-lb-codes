#include<iostream>
#include<map>
using namespace std;

//TC: O(n logn) (Can be made O(n) if we use hashmap instead of map)
//SC: O(n)

//Function to count subarrays with 1s and 0s.
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    long long int subArrayCount = 0;
    
    int prefixSum = 0;
    map<int, int> freq; //sum --> freq
    freq[0] = 1;
    
    for(int i = 0; i < n; i++){
        //Consider 1 as 1; 0 as -1
        if(arr[i] == 1){
            prefixSum += 1;
        }
        else{
            prefixSum += -1;
        }
        
        //If this sum has already occurred before then we just found a SubArray with equal 0s & 1s
        //This is becauze this sum, say X has occurred before and again now, so all 0s and 1s in between cancelled out (we are taking 0s as -1s)
        if(freq.find(prefixSum) != freq.end()) subArrayCount += freq[prefixSum];
        
        freq[prefixSum]++; //update frequency of sum in map
    }
    
    return subArrayCount;
}

int main(){

return 0;
}