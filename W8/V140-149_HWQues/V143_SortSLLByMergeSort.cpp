#include<iostream>
#include<limits.h>
using namespace std;

/**********Q143 : Sort List Using Merge Sort[leetCode : https://leetcode.com/problems/sort-list/description/]***********/

//M1 : Merge Sort Approach
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Returns middle node of SLL
ListNode* getMidNode(ListNode* &head){
    //If SLL has a 1 or 0 node
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

//Merge Two Sorted SLLs
ListNode* mergeSorted(ListNode* headA, ListNode* headB){
    if(headA == NULL) return headB;
    if(headB == NULL) return headA;

    ListNode* mainhead = new ListNode(INT_MIN); //This Dummy Node will be deleted afterall
    ListNode* tail = mainhead;

    while(headA != NULL && headB != NULL){
        if(headB->val <= headA->val){
            tail->next = headB;
            tail = headB;
            headB = headB->next;
        }
        else{
            tail->next = headA;
            tail = headA;
            headA = headA->next;
        }
    }

    if(headA != NULL){
        tail->next = headA;
    }
    else{
        tail->next = headB;
    }

    //Deleting the Dummy Node
    ListNode* temp = mainhead;
    mainhead = mainhead->next;
    temp->next = NULL;
    delete temp;
    return mainhead;
}

//Merge Sort based approach
ListNode* solveHelper(ListNode* &head1){
    if(head1->next == NULL){
        return head1;
    }

    //RE Call
    ListNode* midNode = getMidNode(head1);
    ListNode* head2 = midNode->next;
    midNode->next = NULL;

    head1 = solveHelper(head1);
    head2 = solveHelper(head2);
    
    //Merge sorted SLLs
    ListNode* mainHead = mergeSorted(head1, head2);
    return mainHead;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL) return NULL;

    head = solveHelper(head);
    return head;
}




//M2 : Bubble Sort Approach (Gives TLE on LeetCode after 27/30 TestCases)
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// int getLen(ListNode* &head){
//     ListNode* temp = head;
//     int len = 0;
//     while(temp != NULL){
//         temp = temp->next;
//         len++;
//     }
//     return len;
// }

// //Bubble Sort Approach
// ListNode* sortList(ListNode* &head) {
//     if(head == NULL) return head;

//     ListNode* stop = NULL;
//     int loopCounter = 1;
//     int n = getLen(head);
//     while(loopCounter < n){
//         ListNode* temp = head;
//         bool swapMade = false;
//         while(temp->next != NULL && temp->next != stop){
//             if(temp->val > temp->next->val){
//                 int holder = temp->val;
//                 temp->val = temp->next->val;
//                 temp->next->val = holder;
//                 swapMade = true;
//             }
//             temp = temp->next;
//         }
//         stop = temp;
        
//         if(swapMade == false){
//             return head;
//         }

//         //increment loopCounter
//         loopCounter++;
//     }
//     return head;
// }

int main(){
    //Don't have Test Cases to run code (SLL bnani pdage, LeetCode pe bnane ka code user ko accessible nhi hai!!)
return 0;
}