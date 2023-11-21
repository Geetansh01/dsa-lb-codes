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

Node* solve(Node* &head1, Node* &head2){
    //Step1 : reverse Both LL
    head1 = reverseSLL(head1);
    head2 = reverseSLL(head2);

    //Step2 : Add both LL
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while(head1 != NULL && head2 != NULL){
        int sum = carry + head1->data + head2->data;
        int digit = sum%10;
        carry = sum/10;

        //Create new node for digit 
        Node* newNode = new Node(digit);
        
        //Add digit node to ansHead
        if(ansHead == NULL){
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //when head1 SLL ki length more than head2
    while(head1 != NULL){
        int sum = carry + head1->data ;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        head1 = head1->next;
    }

    //when head2 SLL ki length more than head1
    while(head2 != NULL){
        int sum = carry + head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        head2 = head2->next;
    }

    //carry bch gya ho to 
    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
    }

    ansHead = reverseSLL(ansHead);

    return ansHead;
}

int main(){
   Node* head1 = new Node(2);
   Node* second1 = new Node(4);
   head1->next = second1;

   Node* head2 = new Node(2); 
   Node* second2 = new Node(3); 
   Node* third2 = new Node(4); 
   head2->next = second2;
   second2->next = third2;

   printLL(head1);
   printLL(head2);

   cout<<"Now Adding : "<<endl;
   Node* ans = solve(head1, head2);
   printLL(ans);
return 0;
}