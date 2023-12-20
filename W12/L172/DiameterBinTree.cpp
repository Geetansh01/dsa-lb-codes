#include<iostream>
using namespace std;

/***Diameter of Binary Tree [Interview] [LeetCode : https://leetcode.com/problems/diameter-of-binary-tree/description/]*****/

//M1 : Top to Down Approach [Poor TC] (bottomm to Up approach done later [Better TC])


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);
    return max(option1, max(option2, option3));
}

int main(){
   
return 0;
}