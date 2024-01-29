#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*******Merge k Sorted Lists [LeetCode : https://leetcode.com/problems/merge-k-sorted-lists/description/]*********/
// Although LeetCode hard marked but actually medium
// Can be done via same approach as "L189 : Merge K Sorted Arrays" (Which is what i have done below)

//Follow up : I feel it can be done without creating a new LL , just reusing the space of the one already given, try that!

//TC : O(nk * Log k) (Same as "L189 : Merge K Sorted Arrays")

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class compare{
    public: //REMEMBER to make public ---> Galti krega tu
    bool operator () (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    //Making New LL, initially empty, last me it will be the answer
    ListNode* head = NULL;
    ListNode* tail = NULL;

    // if(lists.size() == 0) return head; //Not needed Bcz is case me Step 1) wala loop chlega hi nhi to pq empty rhega to Step 2 wala loop bhi nhi chlega !

    //Step 1 : Make min-heap from 1st element of every LL
    for(int i = 0; i < lists.size(); i++){
        ListNode* listHead = lists[i];
        if(listHead != NULL){
            pq.push(listHead);
        }
    }


    //Step 2 : Min-heap se minimum element uthate jao and merged LL bnate jao
    while(!pq.empty()){
        ListNode* topNode = pq.top();
        pq.pop();

        //If inserting the 1st node in LL
        if(head == NULL){
            //Insert 1st node in LL (so LL is empty right now)
            head = topNode;
            tail = topNode;
            if(head->next != NULL){
                pq.push(tail->next);
            }
        }
        else{
            //If LL me already Nodes thi
            tail->next = topNode;
            tail = tail->next;
            if(tail->next != NULL){
                pq.push(tail->next);
            }
        }
    }

    return head;

}

int main(){
   
return 0;
}