#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/***V193_2 : Union of Two Linked Lists [GFG : https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1]****/

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


struct Node* makeUnion(struct Node* head1, struct Node* head2)
{       
    //Note that std:map stores entries in sorted way (acc to keys)
    map<int, Node*> map; //key(int) -> pointer to LL Node
    
    //Hashing both the lls into std:map
    Node* curr = head1;
    while(curr != NULL){
        map[curr->data] = curr;
        curr = curr->next;
    }
    
    curr = head2;
    while(curr != NULL){
        map[curr->data] = curr;
        curr = curr->next;
    }
    
    Node* unionListHead = NULL;
    Node* tail = NULL;
    
    //Iterate map & make Union List
    for(auto itr = map.begin(); itr != map.end(); itr++){
        if(unionListHead == NULL){
            unionListHead = itr->second;
            tail = unionListHead;
        }
        else{
            tail->next = itr->second;
            tail = tail->next;
        }
    }
    
    tail->next = NULL;
    
    return unionListHead;
}

int main(){
   
return 0;
}