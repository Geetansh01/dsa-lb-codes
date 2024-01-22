#include<iostream>
#include<vector>
using namespace std;


/*****V186_5 : Balance a Binary Search Tree [LeetCode : https://leetcode.com/problems/balance-a-binary-search-tree/description/]*****/

//Bekar Method below (But this was the soln in the Soln Video by Lakshay Bhaiya)
//Logic: Given Unbalanced BST ---> Inorder Nikal Lo ---> Balanced BST bna lo frmm inorder (See "L185 : MakeBSTfrmInorder")
//I was expecting something along the lines of AVL tree and rotations ಠ_ಠ 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void getInorder(TreeNode* root, vector<int>& Inorder){
    //Base Case
    if(root == NULL) return;

    getInorder(root->left, Inorder);
    Inorder.push_back(root->val);
    getInorder(root->right, Inorder);
    return;
}

TreeNode* makeBalancedBST(int start, int end, vector<int>& Inorder){
    if(start > end) return NULL;

    int mid = start + (end-start)/2;
    TreeNode* root = new TreeNode(Inorder[mid]);
    root->left = makeBalancedBST(start, mid-1, Inorder);
    root->right = makeBalancedBST(mid+1, end, Inorder);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> Inorder;
    getInorder(root, Inorder);

    TreeNode* AnsRoot;
    int start = 0;
    int end = Inorder.size() - 1;
    AnsRoot = makeBalancedBST(start, end, Inorder);
    return AnsRoot;
}

int main(){
   
return 0;
}