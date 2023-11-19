#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printLL(Node* &head){
    Node* tmp = head;
    while(tmp != NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

//Length of LL (Length = no. of nodes)
int findLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//Insertion at head
void insert(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//Insertion at tail
void insertTail(Node* &head, Node* &tail, int data){
    //For empty LL
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = tail->next;
}

//Insert at given position (assume 0-indexed LL)
void insertPos(int position, Node* &head, Node* &tail, int data){
    if(position == 0){
        insert(head, tail, data);
    }
    else if(position >= findLength(head)){
        insertTail(head, tail, data);
    }
    else{
        Node* newNode = new Node(data);
        int i = 1;
        Node* prev = head;
        while(i < position){
            prev = prev->next;
            i++;
        }
        Node* current = prev->next;
        newNode->next = current;
        prev->next = newNode;
    }
}

//SLL Reversal using loop
Node* reverse(Node* &prev, Node* &curr){
    
    while(curr != NULL){
        Node* right = curr->next;
        curr->next = prev;
        prev = curr;
        curr = right;
    }
    return prev;
}

//SLL reversal using RE
Node* reverseRE(Node* &prev, Node* &curr){
    //Base Case
    if(curr == NULL){
        return prev;
    }

    //Solve 1 case
    Node* right = curr->next;
    curr->next = prev;
    prev = curr;
    curr = right;
    return reverseRE(prev, curr);
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insert(head, tail, 10);
    insert(head, tail, 20);
    insert(head, tail, 30);
    insert(head, tail, 40);

    printLL(head);

    Node* prev = NULL;
    tail = head;
    head = reverseRE(prev, head);

    printLL(head);


return 0;
}