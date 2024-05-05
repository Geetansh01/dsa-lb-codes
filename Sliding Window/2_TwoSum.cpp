#include<bits/stdc++.h>
using namespace std;

//M1 : Brute force (TC : O(n^2)) {Using 2 nested for() loops}
//M3 : Using Binary Search (TC: O(n logn )) {Try Yourself : Pehle sort kro then use BS}

//M2 : using 2-pointers (TC: O(n logn ))
//Main Logic : Pehle sort kro then use 2 pointers!
static bool cc(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    vector<pair<int, int>> myNums;
    for(int i = 0; i < n; i++){
        int val = nums[i];
        int index = i;
        myNums.push_back({val, index});
    }

    sort(myNums.begin(), myNums.end(), cc);
    vector<int> ans;
    
    int start = 0;
    int end = myNums.size() - 1;
    int sum = myNums[start].first + myNums[end].first;
    while(start < end){
        if(sum == target){
            ans.push_back(myNums[start].second);
            ans.push_back(myNums[end].second);
            break;
        }
        else if(sum > target){
            end--;
        }
        else{
            start++;
        }
        sum = myNums[start].first + myNums[end].first; 
    }

    return ans;
}

int main(){
   
return 0;
}