#include<iostream>
#include<queue>
using namespace std;

/*****Sliding Window Maximum [LeetCode : https://leetcode.com/problems/sliding-window-maximum/description/]*******/

//M1 : Simple approach [TC : O(n Log n); SC : O(n)]
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> maxH; //pair<val, index>
    vector<int> ans;

    //Process 1st window
    for(int i = 0; i < k; i++){
        maxH.push({nums[i], i});
    }

    //Store ans of 1st window
    ans.push_back(maxH.top().first);

    //Process remaining windows
    int start = 1;
    int end = start + k - 1;
    while(end < nums.size()){
        //Add new element to max heap
        maxH.push({nums[end], end});

        //Remove any max elements that are from previous windows (i.e out of bounds)
        while(maxH.top().second < start){
            maxH.pop();
        }
        ans.push_back(maxH.top().first);

        //window moves ahead
        start++;
        end++; 
    }

    return ans;
}

//M2 : Slightly complex Approach
//Same Approach as in "L167 : Sliding Window Maximum" bss vahan deque se solve kiya yahan max-heap se
//Code bhi exactly same hai except 1 difference, see the comment below
//TC : O(n + k) {Same as "L167 : Sliding Window Maximum"}
// class Info{
//     public:
//     int val;
//     int index;
//     Info(int value, int index){
//         this->val = value;
//         this->index = index;
//     }
// };

// class compare{
//     public:
//     bool operator () (Info* a, Info* b){
//         return (a->val) < (b->val);
//     }
// };

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     priority_queue<Info*, vector<Info*>, compare> maxH; //max Heap, it will store indexes rather than elements

//     //Traverse 1st window
//     for(int i = 0; i < k; i++){
//         //Remove chote elements when a bigger one is coming
//         while(!maxH.empty() && nums[i] >= (maxH.top()->val)){
//             Info* temp = maxH.top();
//             maxH.pop();
//             delete temp;
//         }
//         //inser current element
//         Info* temp2 = new Info(nums[i], i);
//         maxH.push(temp2);
//     }

//     //Store answer of 1st window
//     vector<int> ans;
//     ans.push_back(maxH.top()->val);

//     //Process the remining windows (i.e 2nd & onwards)
//     int start = 1; 
//     int end = start + k - 1; //start & end define the window
//     while(end < nums.size()){
//         //Agr koi out of window ho gya to use remove kro
//         /*
//             DIFFERENCE : the only difference in this code (vs deque code) is this "while" instead of "if" 
//                 1)To see why, Dry Run "nums = [10,1,4,0,0,0] ; k = 3" with deque & max-heap (Taking "if" i.e just 1 check to remove out of bound indexes - U will get wrong answer with max heap)
//                 2)Hand-wavy Reason : deque me new element deque ki back side se ata hai, killing all smaller ones, but max-heap me new element just heap ke top se compare hota hai !
//                 2)deque me "while" bhi chl jaega (but vo "while" loop 1 bar hi chlega so better use "if").
//                 3)Overall, "while" is the safest option (it's logic being, jitne bhi out of window hai unhe remove kro)
//         */
//         while(!maxH.empty() && end - (maxH.top()->index) >= k){
//             Info* temp3 = maxH.top();
//             maxH.pop();
//             delete temp3;
//         }

//         //New element ko push kro
//         //Remove chote elements when a bigger one is coming
//         while(!maxH.empty() && nums[end] >= (maxH.top()->val)){
//             Info* temp = maxH.top();
//             maxH.pop();
//             delete temp;
//         }
//         Info* temp2 = new Info(nums[end], end);
//         maxH.push(temp2);

//         //current window ka answer store krlo 
//         ans.push_back(maxH.top()->val);

//         //window moves ahead
//         start++; end++;
//     }

//     return ans;
// }

int main(){
   
return 0;
}



