#include<iostream>
#include<vector>
using namespace std;

/***V175 : Morris Traversal [Interview] [LeetCode : https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/]****/

//TC: O(N)
//SC: O(1)

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
    TreeNode* current = root;

    while(current != NULL){
        //If current's left child is null then store the current Node and go right (acc. to LRN)
        if(current->left == NULL){
            ans.push_back(current->val);
            current = current->right;
        }
        else{
        //If current Node has a non-null left child
        
            //Find current's predecessor and make a link
            TreeNode* pred = current->left;
            while(pred->right != current && pred->right != NULL){
                pred = pred->right;
            }

            //If predecessor's right pointer is null, use it to link to current
            if(pred->right == NULL){
                pred->right = current;
                current = current->left;
            }
            else{
                //If predecessor's right pointer is not null that means it was already linked before, delink it
                pred->right = NULL;
                ans.push_back(current->val);
                current = current->right;
            }

        }

    }

    return ans;
}

int main(){
   
return 0;
}