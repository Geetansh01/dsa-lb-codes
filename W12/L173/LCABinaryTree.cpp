#include<iostream>
using namespace std;

/****Lowest Common Ancestor of a Binary Tree [Interview] [LeetCode] [https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/]***/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //Base Case
    if(root == NULL)return NULL;
    if(root == p)return p;
    if(root == q)return q;

    TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
    if(leftAns == NULL && rightAns == NULL){
        return NULL;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        //Both (leftAns != NULL && rightAns != NULL) i.e we are standing on LCA
        return root;
    }
}

int main(){
   
return 0;
}