#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

/*****Remove Stones to Minimize the Total [LeetCode : https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/]******/

//TC : O(N) + O(k LogN) + O(N)

/*
    Approach : Greedy (implemented via max-heap)

    1)Total "sum" as small as possible chaiye to hr bar largest element nikalo and use chota krke wapis dal do (using Line(1)). 
    2)Note that floor(x/2) will do MAXIMUM DAMAGE to "sum" if we take the largest element each time !  
*/

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> maxHeap;

    // TC : O(N)
    for(int i = 0; i < piles.size(); i++){
        maxHeap.push(piles[i]);
    }

    // TC : O(k LogN)
    //Use of max-heap : Largest element nikalo, use chota krke (Line (1)) wapis heap me dal do
    while(k > 0){
        int maxElement = maxHeap.top();
        maxHeap.pop();
        maxElement = maxElement - floor(maxElement/2);  //....Line (1)
        maxHeap.push(maxElement);

        k--;
    }

    // TC : O(N)
    int sum = 0;
    while(!maxHeap.empty()){
        int temp = maxHeap.top();
        maxHeap.pop();
        sum += temp;
    }

    return sum;
}

int main(){
   
return 0;
}