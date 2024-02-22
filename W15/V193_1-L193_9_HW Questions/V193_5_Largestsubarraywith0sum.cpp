#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/***Largest subarray with 0 sum [GFG : https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1]****/

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