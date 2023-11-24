#include<iostream>
#include<limits.h>
#include<unordered_map>
using namespace std;

/********Q145 : Copy List with Random Pointer [LeetCode : https://leetcode.com/problems/copy-list-with-random-pointer/submissions/]*********/

//M1 : Best Method  (Playing with pointers) (TC: O(n); SC: O(1)) (SC calculation does not include the Space needed to make the new Deep Copy SLL bcz that's what the question wants)

// Definition for a Node
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(head == NULL) return NULL;

    //Making Cloned SLL intertwined with original SLL
    Node* temp = head;
    while(temp != NULL){
        Node* copy = new Node(temp->val);
        copy->next = temp->next;
        temp->next = copy;
        temp = temp->next->next;
    }

    //Cloning random ptrs
    temp = head;
    while(temp != NULL){
        if(temp->random != NULL){
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    
    //Detach new and old SLLs
    Node* ogNode = head;
    Node* cloneHead = ogNode->next;
    while(ogNode != NULL){
        Node* cloneNode = ogNode->next;
        ogNode->next = ogNode->next->next;
        ogNode = ogNode->next;
        if(ogNode != NULL){
            cloneNode->next = ogNode->next;
        }
    }

    return cloneHead;       
}

//M2 : using unordered_map (TC: O(n); SC: O(n)) (SC calculation does not include the Space needed to make the new Deep Copy SLL bcz that's what the question wants)
// // Definition for a Node
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

// Node* helperRE(Node* head, unordered_map<Node*, Node*>& mp){
//     if(head == NULL) return NULL;

//     Node* newNode = new Node(head->val);
//     mp[head] = newNode;
//     newNode->next = helperRE(head->next, mp);

//     if(head->random != NULL){
//         newNode->random = mp[head->random]; 
//     }
//     return newNode;            
// }

// Node* copyRandomList(Node* head) {
//     unordered_map<Node*, Node*> mp;
//     Node* ans = helperRE(head, mp);
//     return ans;
// }

//M2 : without unordered_map (TC: O(n^2); SC: O(1)) (SC calculation does not include the Space needed to make the new Deep Copy SLL bcz that's what the question wants)

// Node* copyRandomList(Node* head) {
//     if(head == NULL) return NULL;

//     Node* dc = new Node(INT_MIN); //Dummy Starting Node
//     Node* dcTemp = dc;
//     Node* ogTemp = head;
//     while(ogTemp != NULL){
//         Node* newNode = new Node(ogTemp->val);
//         dcTemp->next = newNode;
//         dcTemp = newNode;
//         ogTemp = ogTemp->next;
//     }

//     dc = dc->next; //Removed Dummy Node 
//     Node* ans = dc;
//     Node* og = head;
//     while(dc != NULL){
//         ogTemp = head;
//         dcTemp = ans;

//         if(og->random == NULL){
//             dc->random = NULL;
//         }
//         else{
//             if(ogTemp == og->random){
//                 //Do nothing
//             }
//             else{
//                 while(ogTemp != og->random){
//                     ogTemp = ogTemp->next;
//                     dcTemp = dcTemp->next;
//                 }
//             }
//             dc->random = dcTemp;
//         }
//         og = og->next;
//         dc = dc->next;
//     }

//     return ans;
// }

int main(){
   
return 0;
}