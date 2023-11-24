#include<iostream>
#include<limits.h>
using namespace std;

/********Q144 : Flatten Linked List[GFG : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1]************/

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeSortedSLL(Node* newHead, Node* B){
    Node* dummy = new Node(INT_MIN);
    Node* tail = dummy;
    
    while(newHead != NULL && B != NULL){
        if(newHead->data <= B->data){
            tail->bottom = newHead;
            tail = newHead;
            newHead = newHead->bottom;
        }
        else{
            tail->bottom = B;
            tail = B;
            B = B->bottom;
        }
    }
        
    if(newHead != NULL){
        tail->bottom = newHead;
    }
    else{
        tail->bottom = B;
    }
    
    Node* temp = dummy;
    dummy = dummy->bottom;
    temp->bottom = NULL;
    delete temp;
    
    return dummy;
}

Node *flatten(Node *root){
    if(root == NULL) return NULL;
    
    Node* A = root;
    Node* B = A->next;
    Node* newHead = A;
    
    while(B != NULL){
        A->next = NULL;
        newHead = mergeSortedSLL(newHead, B);
        A = B;
        B = B->next;
    }
    return root;
}

int main(){
    //Don't have Test Cases to run code (SLL bnani pdage, better chk on GFG !!)
return 0;
}