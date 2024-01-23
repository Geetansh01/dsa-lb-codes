#include<iostream>
#include<limits.h>
using namespace std;

/****V187_7 : Check whether BST contains Dead End [GFG : https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/0]*****/
//The Node structure is
struct Node {
int data;
Node * right, * left;
};

//My SOln Below (TC: O(N); SC: O(H) H is height of BST)
void helperRE(Node*& root, bool& deadEnd, int lowerLimit, int upperLimit){
    if(root == NULL) return;
    if(deadEnd == true) return; //Means deadEnd already found so return
    if(root->left == NULL && root->right == NULL){
        if(upperLimit - lowerLimit - 1 <= 1){
            deadEnd = true;
        }
    }
    
    helperRE(root->left, deadEnd, lowerLimit, root->data);
    helperRE(root->right, deadEnd, root->data, upperLimit);
    return;
}

bool isDeadEnd(Node *root){
    bool deadEnd;
    helperRE(root, deadEnd, 0, INT_MAX);
    return deadEnd;
}

int main(){
   
return 0;
}