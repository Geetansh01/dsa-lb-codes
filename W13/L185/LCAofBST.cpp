#include<iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TC: O(n) ; n = number of nodes in BST (n = height of BST for Skew Tree)

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //base case
    if(root == NULL) return NULL;

    //Case 1 : p , q both in left subtree of root 
    if(p->val < root->val && q->val < root->val){
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        return leftAns;
    }

    //Case 2 : p, q both in right subtree of root
    else if(p->val > root->val && q->val > root->val){
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        return rightAns;
    }

    //Below 2 cases are not needed bcz dono me root hi return krna hai
    // //Case 3 : p in left subtree & q in right subtree of root
    // else if(p->val < root->val && q->val > root->val){
    //     return root;
    // }

    // //Case 4 : p in right subtree & q in left subtree of root
    // else if(q->val < root->val && p->val > root->val){
    //     return root;
    // }

    return root; 
}

int main(){
   
return 0;
}