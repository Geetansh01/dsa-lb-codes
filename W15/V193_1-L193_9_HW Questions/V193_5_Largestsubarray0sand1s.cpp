#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/****Largest subarray of 0's and 1's [GFG : https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1]*****/
// Based on "V193_5 : 1)Largest subarray with 0 sum"

int maxLen(vector<int>&A, int n)
{   
    unordered_map<int, int> map; //sum ---> index
    int currSum = 0; //cumulative sum of array
    int ans = 0; //It will finally store max length of subarray with 0 sum
    
    //Iterate the array
    for(int i = 0; i < n; i++){
        currSum += A[i];
        if(currSum == 0){
            ans = max(ans, i+1);
        }
        else if(map.find(currSum) == map.end()){
            map[currSum] = i;
        }
        else{
            //map has currSum already
            int prevIndex = map[currSum];
            int length = i - prevIndex;
            ans = max(ans, length);
        }
    }
    
    return ans;
}
int main(){
   
return 0;
}