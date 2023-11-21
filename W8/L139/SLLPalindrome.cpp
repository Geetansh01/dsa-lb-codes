#include<iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseSLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool chkPalindrome(Node* &head){
    if(head == NULL){
        cout<<"SLL empty"<<endl;
        return true;
    }
    if(head->next == NULL){
        return true;
    }

    //Step1 : Find Middle Node
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    //slow is now pointing to the middle Node of SLL

    //Step2 : Reverse SLL after Middle Node
    Node* revLLKaHead = reverseSLL(slow->next);
    slow->next = revLLKaHead;

    //Step3 : Start Comparison
    Node* temp1 = head;
    Node* temp2 = revLLKaHead;

    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            //Not a palindrome
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main(){
   Node* first = new Node(10); 
   Node* second = new Node(20); 
   Node* third = new Node(30); 
   Node* forth = new Node(20); 
   Node* fifth = new Node(10); 


   first->next = second;
   second->next = third;
   third->next = forth;
   forth->next = fifth;


   cout<<"Is SLL Palindrome? : "<<chkPalindrome(first)<<endl;
return 0;
}