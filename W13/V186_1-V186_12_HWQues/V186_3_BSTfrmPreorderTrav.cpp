#include<iostream>
#include<vector>
using namespace std;

/****V186_3 : Construct Binary Search Tree from Preorder Traversal [LeetCode : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/]*****/

//M3: Best Way (TC: O(n))
//My own Solution below :)

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* helperRE(int start, int end, vector<int>& preorder){
    //Base Case
    if(start > end) return NULL;

    //Make Node
    TreeNode* root = new TreeNode(preorder[start]);

    int i = start+1;
    while(i <= end && preorder[i] < preorder[start]){
        i++;
    }

    //Make left subtree
    root->left = helperRE(start+1, i-1, preorder);

    //Make right subtree
    root->right = helperRE(i, end, preorder);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int start = 0;
    int end = preorder.size()-1;
    TreeNode* root = helperRE(start, end, preorder);
    return root;
}

int main(){
   
return 0;
}