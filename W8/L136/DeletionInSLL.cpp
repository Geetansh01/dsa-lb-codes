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
    ~Node(){
        delete next;
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

/***************************DELETION CODE STRTS HERE*******************************************/
//Deleting a node at given position(0 indexed LL)
void deletePos(int pos, Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"LL Empty, can't delete"<<endl;
        return;
    }
    //Deleting node at index 0
    if(pos == 0){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    
    //Deleting last Node
    if(pos == findLength(head) - 1){
        Node* prev = head;
        int i = 0;
        while(i < pos - 1){
            prev = prev->next;
            i++;
        }
        delete tail;
        tail = prev;
        prev->next = NULL;
        return;
    }

    //Deleting Middle Node
    else{
        int i = 0;
        Node* prev = head;
        if(i < pos - 1){
            prev = prev->next;
        }
        Node* current = prev->next;
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertPos(0,head,tail,10);
    insertPos(1,head,tail,20);
    insertPos(2,head,tail,30);
    insertPos(3,head,tail,40);

    printLL(head);

    deletePos(3, head, tail);

    printLL(head);
   

return 0;
}