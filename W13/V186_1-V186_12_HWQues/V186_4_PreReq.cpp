#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*****Binary Tree Inorder Traversal WITHOUT RE [LeetCode : https://leetcode.com/problems/binary-tree-inorder-traversal/description/*******/
//This is a method to perform Inorder Traversal of a Binary Tree (so, also applies to BST) without RE
//So, instead of using RE call stack, we will make our own stack (Same TC/ SC as normal recursion)


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    
    //My own stack to replace RE Call Stack
    stack<TreeNode*> st;
    TreeNode* temp = root;

    while(!st.empty() || temp != NULL){
        //LNR

        //L
        while(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }

        //N
        TreeNode* stTop = st.top();
        st.pop();
        ans.push_back(stTop->val);

        //R
        temp = stTop->right;
    }

    return ans;
}


int main(){
   
return 0;
}