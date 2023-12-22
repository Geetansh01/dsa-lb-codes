#include<iostream>
#include<limits.h>
using namespace std;

/*****Check if given BT is Sum Tree or Not [GFG : https://practice.geeksforgeeks.org/problems/sum-tree/1]******/
//A slightly different question was discussed in class (Convert given BT to Sum Tree) but this Ques is covered in HW Videos (See L181)
//My solution Below

struct Node
{
    int data;
    Node* left, * right;
}; 

int helperRE(Node* root){
    //Base Case
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    
    int currNodeData = root->data;
    int leftTreeAns = helperRE(root->left);
    int rightTreeAns = helperRE(root->right);
    if(leftTreeAns == INT_MIN || rightTreeAns == INT_MIN){
        return INT_MIN;
    }
    else if(leftTreeAns + rightTreeAns != currNodeData){
        return INT_MIN;
    }
    else{
        return currNodeData + leftTreeAns + rightTreeAns;
    }
}


bool isSumTree(Node* root)
{
    int ans = INT_MIN;
    ans = helperRE(root);
    if(ans == INT_MIN){
        return false;
    }
    else{
        return true;
    }
}

int main(){
   
return 0;
}