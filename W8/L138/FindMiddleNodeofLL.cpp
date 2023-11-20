#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

Node* midLL(Node* &head){
    if(head == NULL){
        cout<<"Empty LL"<<endl;
        return NULL;
    }
    if(head->next == NULL){
        cout<<"Only Single Node Present"<<endl;
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int main(){
   Node* first = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);
   Node* forth = new Node(40);
   Node* fifth = new Node(50);

   first->next = second;
   second->next = third;
   third->next = forth;
   forth->next = fifth;

   printLL(first);

   cout<<midLL(first)->data<<endl;
return 0;
}