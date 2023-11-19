#include<iostream>
using namespace std;


//NOTE : I am taking 0-indexed DLL

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    // ~Node()
};

//Print DLL
void printDLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//Length
int getLen(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}

void insertAtpos(Node* &head, Node* &tail, int data, int pos){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(pos == 0){
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLen(head);
    if(pos >= len){
        insertAtTail(head, tail, data);
        return;
    }

    int i = 0;
    Node* prevNode = head;
    while(i < pos - 1){
        prevNode = prevNode->next;
        i++;
    }
    Node* curr = prevNode->next;

    Node* newNode = new Node(data);

    prevNode->next = newNode;
    newNode->prev = prevNode;

    curr->prev = newNode;
    newNode->next = curr;
    
}

void deletepos(Node* &head, Node* &tail, int pos){
    if(head == NULL){
        cout<<"DLL Empty";
        return;
    }

    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(pos == 0){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLen(head);
    if(pos > len-1){
        cout<<"Invalid position";
        return;
    }

    if(pos == len-1){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    //Deletion from middle (Any given position from 0 to len-1)
    int i = 0;
    Node* current = head;
    while (i < pos)     
    {
        current = current->next;
        i++;
    }
    Node* left = current->prev;
    Node* right = current->next;

    left->next = right;
    right->prev = left;
    
    current->next = NULL;
    current->prev = NULL;

    delete current;    
}

int main(){
   Node* first = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);

   first->next = second;
   second->prev = first;

   second->next = third;
   third->prev = second;
   Node* tail = third;
   Node* head = first;

   printDLL(first);

   insertAtHead(head, tail, 1);

   printDLL(head);

   insertAtTail(head, tail, 45);

   printDLL(head);

   insertAtpos(head, tail, 9, 1);

   printDLL(head);

   deletepos(head, tail, 2);

   printDLL(head);
return 0;
}