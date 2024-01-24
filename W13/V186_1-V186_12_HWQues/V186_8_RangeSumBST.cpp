#include<iostream>
using namespace std;

/*****V186_7 : Range Sum of BST [LeetCode : https://leetcode.com/problems/range-sum-of-bst/description/]*******/
//TC (Worst Case) : O(N)
//TC (Avg Case) : O(H) / O(logN) (Bcz of the micro-optimizations in line (1) & (2))

//Note : The height of a height-balanced BST with N nodes in log(N)
/*
    So, for the Avg Case, we are assuming 2 things:
    1)Height Balanced BST
    2)Convenient Values of nodes 

    such that 1/2 of the BST will be discarded in every step!
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void helperRE(TreeNode*& root, int& ans, int& low, int& high){
    //Base Case
    if(!root) return;

    if(root->val >= low && root->val <= high ){
        ans += root->val;
    }
    if(root->val > low){
        //Agr val <= low to left me jana is useless  ....Line(1)
        helperRE(root->left, ans, low, high);
    }
    if(root->val < high){
        //Agr val >= high to right me jana is useless   ....Line(2)
        helperRE(root->right, ans, low, high);
    }
    return;
}

int rangeSumBST(TreeNode* root, int low, int high) {
    int ans = 0;
    helperRE(root, ans, low, high);
    return ans;
}


int main(){
   
return 0;
}