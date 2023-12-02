#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

/*********Q155 : Next Greater Element In LL [LeetCode : https://leetcode.com/problems/next-greater-node-in-linked-list/description/]************/
//My approach is similar to but slightly better than the one discussed in V155. I don't copy the contents of given SLL into an array and hence save both TC and SC.
//My approach is more closely based on "Next And Prev Smaller Element using Stack" in L152 than V155, which also follows on similar lines.
//Overall, both approaches are TC : O(N)



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseLL(ListNode* &head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* frwd = NULL;

    while(curr != NULL){
        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

vector<int> nextLargerNodes(ListNode* &head) {
    head = reverseLL(head);

    ListNode* temp = head;
    stack<int> stk;
    vector<int> ans;
    while(temp != NULL){
        while(!stk.empty()){
            if(stk.top() > temp->val){
                ans.push_back(stk.top());
                stk.push(temp->val);
                break;
            }
            else{
                stk.pop();
            }
        }
        if(stk.empty()){
            ans.push_back(0);
            stk.push(temp->val);
        }

        temp = temp->next;
    }

    reverse(ans.begin(), ans.end());
    return ans;        
}
int main(){
    //Don't have Test Cases to run code (SLL bnani pdage, LeetCode pe bnane ka code user ko accessible nhi hai!!)
return 0;
}