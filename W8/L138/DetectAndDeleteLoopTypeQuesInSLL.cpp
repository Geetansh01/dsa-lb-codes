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

//FCD Algo
bool checkForLoop(Node* &head){
    if(head == NULL){
        cout<<"Empty LL"<<endl;
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            //Loop present
            return true;
        }
    }

    //fast becomes NULL
    return false;
}

//Find starting of loop (Assuming Loop is present)
Node* startingPointOfLoop(Node* &head){
    if(head == NULL){
        cout<<"Empty LL"<<endl;
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            slow = head;
            break;
        }
    }

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

//Remove Loop(Assuming Loop is present)
void removeLoop(Node* &head){
    if(head == NULL){
        cout<<"Empty LL"<<endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL){
        prev = fast;
        fast = fast->next;

        if(fast != NULL){
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            slow = head;
            break;
        }
    }

    while(slow != fast){
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL;
    return;
}



int main(){
   Node* first = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);
   Node* forth = new Node(40);
   Node* fifth = new Node(50);
   Node* sixth = new Node(60);
   Node* seventh = new Node(70);
   Node* eighth = new Node(80);
   Node* ninth = new Node(90);

   first->next = second;
   second->next = third;
   third->next = forth;
   forth->next = fifth;
   fifth->next = sixth;
   sixth->next = seventh;
   seventh->next = eighth;
   eighth->next = ninth;
   ninth->next = fifth;

  cout<<"Loop present? : "<<checkForLoop(first)<<endl;

  if(checkForLoop(first)){
    cout<<"Starting point of Loop is : "<<startingPointOfLoop(first)->data<<endl;

    cout<<"Removing Loop and Printing SLL"<<endl;
    removeLoop(first);
    printLL(first);
    cout<<"Loop present? : "<<checkForLoop(first)<<endl;
  }

return 0;
}