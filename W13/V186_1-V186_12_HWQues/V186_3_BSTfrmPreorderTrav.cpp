#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/****V186_3 : Construct Binary Search Tree from Preorder Traversal [LeetCode : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/]*****/

//M3: Best Way (TC: O(n))

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* buildRE(int& i, int min, int max, vector<int>& preorder){
    //BC
    if(i >= preorder.size()) return NULL;

    TreeNode* root = NULL;
    if(preorder[i] > min && preorder[i] < max){
        root = new TreeNode(preorder[i++]);
        root->left = buildRE(i, min, root->val, preorder);
        root->right = buildRE(i, root->val, max, preorder);
    }

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int min = INT_MIN; int max = INT_MAX;
    int i = 0;
    return buildRE(i, min, max, preorder);
}

int main(){
   
return 0;
}