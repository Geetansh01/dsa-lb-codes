#include<iostream>
using namespace std;

/******V181 : Transform To Sum Tree [GFG : https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1]*******/


struct Node
{
    int data;
    Node* left, * right;
};

int helperRE(Node* node){
    if(node == NULL){
        return 0;
    }
    if(node->left == NULL && node->right == NULL){
        int currNodeData = node->data;
        node->data = 0;
        return currNodeData;
    }
    
    int leftTreeAns = helperRE(node->left);
    int rightTreeAns = helperRE(node->right);
    int currNodeData = node->data;
    node->data = leftTreeAns + rightTreeAns;
    return leftTreeAns + rightTreeAns + currNodeData;
}

void toSumTree(Node *node)
{
    helperRE(node);
    return;
}

int main(){
   
return 0;
}