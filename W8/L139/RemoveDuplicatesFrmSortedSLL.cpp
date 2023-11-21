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
    ~Node(){
        delete next; 
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

void removeDuplicate(Node* &head){
    if(head == NULL){
        cout<<"Empty SLL"<<endl;
        return;
    }
    if(head->next == NULL){
        cout<<"Only 1 Node"<<endl;
        return;
    }

    Node* curr = head;

    while(curr != NULL){
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            //Duplicate Nodes found
            Node* temp = curr->next;
            curr->next = curr->next->next;

            //Delete the duplicate Node
            temp->next = NULL;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
}

int main(){
   Node* first = new Node(1);
   Node* second = new Node(2);
   Node* third = new Node(2);
   Node* forth = new Node(3);
   Node* fifth = new Node(4);
   Node* sixth = new Node(4);
   Node* seventh = new Node(5);
   Node* eighth = new Node(5);
   Node* ninth = new Node(5);

   first->next = second;
   second->next = third;
   third->next = forth;
   forth->next = fifth;
   fifth->next = sixth;
   sixth->next = seventh;
   seventh->next = eighth;
   eighth->next = ninth;

   cout<<"Initial SLL :"<<endl;
   printLL(first);

   removeDuplicate(first);

   cout<<"Initial SLL :"<<endl;
   printLL(first);



return 0;
}