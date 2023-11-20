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

int getLen(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//Using Recursion
Node* reverseK(Node* &head, int k){
    if(head == NULL){
        cout<<"Empty LL"<<endl;
        return NULL;
    }

    int len = getLen(head);
    if(k > len){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;
    while(count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    //If we still have node to reverse
    if(forward != NULL){
        head->next = reverseK(forward, k);
    }

    return prev;
}



int main(){
   Node* first = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);
   Node* forth = new Node(40);
   Node* fifth = new Node(50);
   Node* sixth = new Node(60);

   first->next = second;
   second->next = third;
   third->next = forth;
   forth->next = fifth;
   fifth->next = sixth;

   Node* head = first;
   printLL(head);

   head = reverseK(first, 7);

   printLL(head);


return 0;
}