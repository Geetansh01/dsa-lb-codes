#include<iostream>
#include<stack>

using namespace std;

/********V186_4 : Brothers From Different Roots [GFG : https://www.geeksforgeeks.org/problems/brothers-from-different-root/1]*************/

//M3 : Best way (TC : O(n))

// Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int countPairs(Node* root1, Node* root2, int x){
    int count = 0;
    
    stack<Node*> s1;
    stack<Node*> s2;
    
    Node* a = root1;
    Node* b = root2;

    while((!s1.empty() || a != NULL) && (!s2.empty() || b != NULL) ){
        //LNR for BST 1
        //RNL for BST 2
        
        while(a != NULL){
            s1.push(a);
            a = a->left;
        }
        
        while(b != NULL){
            s2.push(b);
            b = b->right;
        }
        
        Node* s1Top = s1.top();
        Node* s2Top = s2.top();
        
        if(s1Top->data + s2Top->data == x){
            count++;
            
            s1.pop();
            a = s1Top->right;
            
            s2.pop();
            b = s2Top->left;
        }
        else if(s1Top->data + s2Top->data > x){
            s2.pop();
            b = s2Top->left;
        }
        else{
            s1.pop();
            a = s1Top->right;
        }
    }
    
    return count;
}


int main(){
   
return 0;
}