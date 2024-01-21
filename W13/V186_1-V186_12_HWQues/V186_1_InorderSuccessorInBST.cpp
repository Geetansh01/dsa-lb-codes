#include<iostream>
using namespace std;

/*******QL186_1 :Inorder Successor in BST [GFG : https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1]*********/

//M3 : Best Approach(TC: O(H); H is height of BST)

//Structure of Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// returns the inorder successor of the Node x in BST (rooted at 'root')
Node * inOrderSuccessor(Node *root, Node *x)
{
    Node* successor = NULL;
    Node* temp = root;
    while(temp != NULL){
        if(temp->data <= x->data){
            temp = temp->right;
        }
        else{
            successor = temp;
            temp = temp->left;
        }
    }
    
    return successor;
}


int main(){
   
return 0;
}