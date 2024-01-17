#include<iostream>
#include<vector>
using namespace std;

//This Ques is a Pre Requisite for "Two Sum IV - Input is a BST"
//This Ques should have been done in Week-3 Arrays but somehow missed!
//TC : O(n) (n is size of given Array)

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int s = 0;
    int e = numbers.size() - 1;

    while(s < e){
        int sum = numbers[s] + numbers[e];
        if(sum == target){
            ans.push_back(s+1);
            ans.push_back(e+1);
            return ans;
        }
        else if(sum > target){
            e--;
        }
        else{
            s++;
        }
    }

    return ans; 
}

int main(){
   
return 0;
}