#include<iostream>
using namespace std;

/***********Q142 : Merge Two Sorted Lists [LeetCode : https://leetcode.com/problems/merge-two-sorted-lists/description/]***********/
//M1 : Iterative (Similar to merging two sorted arrays)
//TC: O(m+n)
//SC: O(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* listA, ListNode* listB) {
    if(listA == NULL && listB == NULL) return NULL;
    if(listA == NULL && listB != NULL) return listB;
    if(listB == NULL && listA != NULL) return listA;

    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    
    while(listA != NULL && listB != NULL){
        if(listB->val <= listA->val){
            tail->next = listB;
            tail = tail->next;
            listB = listB->next;
        }
        else{
            tail->next = listA;
            tail = tail->next;
            listA = listA->next;
        }
    }

    if(listA != NULL){
        tail->next = listA;
    }
    else{
        tail->next = listB;
    }

    return head->next;
}

//M2 : Recursive (Exactly Similar to above iterative method but by Recursion)
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// void solveRE(ListNode* &listA, ListNode* &listB, ListNode* &tail){
//     if(listA == NULL){
//         tail->next = listB;
//         return;
//     }
//     else if(listB == NULL){
//         tail->next = listA;
//         return;
//     }

//     if(listB->val <= listA->val){
//         tail->next = listB;
//         tail = listB;
//         listB = listB->next;
//         solveRE(listA, listB, tail);
//     }
//     else{
//         tail->next = listA;
//         tail = listA;
//         listA = listA->next;
//         solveRE(listA, listB, tail);
//     }
// }

// ListNode* mergeTwoLists(ListNode* listA, ListNode* listB) {
//     if(listA == NULL && listB == NULL) return NULL;
//     if(listA == NULL && listB != NULL) return listB;
//     if(listB == NULL && listA != NULL) return listA;

//     ListNode* dummyNode = new ListNode(-1);
//     ListNode* tail = dummyNode;
//     solveRE(listA, listB, tail);

//     return dummyNode->next;
    
// }

int main(){
    //Don't have Test Cases to run code (SLL bnani pdage, LeetCode pe bnane ka code user ko accessible nhi hai!!)
return 0;
}