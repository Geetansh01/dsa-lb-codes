#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
   
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};

void printLL(Node* &head){
    Node* tmp = head;
    while(tmp != NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}

//This is not how u should be making LL , just for ex...
int main(){
   Node* first = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);
   Node* forth = new Node(40);

   first->next = second;
   second->next = third;
   third->next = forth;

   printLL(first);
return 0;
}