#include<iostream>
using namespace std;

/*********Q141 : Intersection Of 2 Link Lists [LeetCode : https://leetcode.com/problems/intersection-of-two-linked-lists/description/]*************/

//TC : O(m + n) ; m,n are the no. of nodes in 2 SLLs
//SC : O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL){
        return NULL;
    }

    ListNode* tempA = headA;
    ListNode* tempB = headB;

    while(tempA->next != NULL && tempB->next != NULL){
        tempA = tempA->next;
        tempB = tempB->next;
    }

    int len = 0;
    char biggerSLL = '\0';
    if(tempB->next != NULL){
        biggerSLL = 'B';
        while(tempB->next != NULL){
            tempB = tempB->next;
            len++; 
        }
    }
    else{
        biggerSLL = 'A';
        while(tempA->next != NULL){
            tempA = tempA->next;
            len++; 
        }
    }

    if(biggerSLL == 'B'){
        while(len > 0){
            headB = headB->next;
            len--;
        }
    }
    else{
        while(len > 0){
            headA = headA->next;
            len--;
        }
    }

    while(headA != headB){
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

int main(){
   //Don't have Test Cases to run code (SLL bnani pdage, LeetCode pe bnane ka code user ko accessible nhi hai!!)
return 0;
}