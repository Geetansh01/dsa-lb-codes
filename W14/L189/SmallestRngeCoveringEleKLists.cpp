#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

/*****Smallest Range Covering Elements from K Lists [LeetCode : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/]*******/

class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int data, int rI, int cI){
        this->data = data;
        this->rowIndex = rI;
        this->colIndex = cI;
    }
};

class compare{
    public:
    bool operator () (Info* a, Info* b){
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Info*, vector<Info*>, compare> minHeap;
    int rows = nums.size();

    //Step 1 : Make Initial Heap
    for(int i = 0; i < rows; i++){
        int element = nums[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new Info(element, i, 0));
    }

    int ansStart = mini;
    int ansEnd = maxi;

    //Step 2 : Heap se top uthate jao & new element insert krte jao in heap
    while(!minHeap.empty()){
        Info* top = minHeap.top();
        int topElement = top->data;
        int topRow = top->rowIndex;
        int topCol = top->colIndex;
        minHeap.pop();

        delete top; //Prevent memory leak

        //mini updated
        mini = topElement;

        //Check for possible answer
        int currRange = maxi - mini;
        int ansRange = ansEnd - ansStart;
        if(currRange < ansRange){
            ansStart = mini;
            ansEnd = maxi;
        }

        //Check for new element in same list
        if(topCol + 1 < nums[topRow].size()){
            Info* newInfo = new Info(nums[topRow][topCol + 1], topRow, topCol + 1);
            maxi = max(maxi, newInfo->data);
            minHeap.push(newInfo);
        }
        else{
            //Nothing to push
            //So, Koi ek row khtm hogyi, STOP
            break;
        }
    }

    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);

    return ans;

}


int main(){
   
return 0;
}