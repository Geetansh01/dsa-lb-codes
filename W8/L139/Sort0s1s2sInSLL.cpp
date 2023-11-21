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

//When Replacement of data is allowed
void sort1(Node* &head){
    if(head == NULL){
        cout<<"LL empty"<<endl;
        return;
    }

    if(head->next == NULL){
        cout<<"Only 1 Node"<<endl;
        return;
    }

    int zero = 0;
    int one = 0;
    int two = 0;

    //Step1 : Count 0s, 1, & 2s
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zero++;
        }
        else if(temp->data == 1){
            one++;
        }
        else if(temp->data == 2){
            two++;
        }
        temp = temp->next;
    }

    //Step2 : Fill 0s, 1s and 2s back
    temp = head;
    while(zero--){
        temp->data = 0;
        temp = temp->next;
    }

    while(one--){
        temp->data = 1;
        temp = temp->next;
    }

    while(two--){
        temp->data = 2;
        temp = temp->next;
    }
}

//When Replacement of data is NOT allowed
Node* sort2(Node* &head){
    if(head == NULL){
        cout<<"LL empty"<<endl;
        return head;
    }

    if(head->next == NULL){
        cout<<"Only 1 Node"<<endl;
        return head;
    }

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //Traverse the original SLL
    Node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            //Take out 0 wali Node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //Append temp Node to zeroHead SLL
            zeroTail->next = temp;
            zeroTail = temp;
        }

        else if(curr->data == 1){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //Append temp Node to zeroHead SLL
            oneTail->next = temp;
            oneTail = temp;

        }

        else if(curr->data == 2){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //Append temp Node to zeroHead SLL
            twoTail->next = temp;
            twoTail = temp;

        }
    }

    //Modify 1 wali LL
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;
 
    //Modify 2 wali LL
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    //Join LL
    if(oneHead != NULL){
        zeroTail->next = oneHead;

        if(twoHead != NULL){
            oneTail->next = twoHead;
        }
    }

    //One wali LL is empty
    else{
        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }

    //remove zeroHead dummy Node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    //Return head of sorted SLL
    return zeroHead;
}

int main(){
   Node* first = new Node(1);
   Node* second = new Node(2);
   Node* third = new Node(1);
   Node* forth = new Node(2);
   Node* fifth = new Node(0);
   Node* sixth = new Node(2);

   first->next = second;
   second->next = third;
   third->next = forth;
   forth->next = fifth;
   fifth->next = sixth;

    Node* head = first;
    printLL(head);
    cout<<"Now Sorted SLL : "<<endl;
    // sort1(head);
    head = sort2(head);
    printLL(head);

    return 0;
}