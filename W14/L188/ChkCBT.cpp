#include<iostream>
#include<queue>
using namespace std;

/******Check Completeness of a Binary Tree [LeetCode : https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/]*******/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    bool nullFound = false;
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();

        if(front == NULL){
            nullFound = true;
        }
        else{
            if(nullFound){
                return false;
            }
            q.push(front->left);
            q.push(front->right);
        }
    }

    return true;
}

bool isCompleteTree(TreeNode* root) {
    return levelOrderTraversal(root);
}

int main(){
   
return 0;
}