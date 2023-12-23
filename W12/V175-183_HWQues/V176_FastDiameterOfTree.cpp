#include<iostream>
using namespace std;

/******V176 : FW To Find Diameter [LeetCode : https://leetcode.com/problems/diameter-of-binary-tree/submissions/]********/

//TC : O(n)

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root, int& diameter){
    //Base Case
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);
    int currHeight = max(leftHeight, rightHeight) + 1;

    //This is the step that saves TC, No further calls, yhi pe "diameter" Bhi update kr do
    int currDiameter = leftHeight + rightHeight;
    diameter = max(diameter, currDiameter);

    return currHeight;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    //A modified height function
    height(root, diameter);
    return diameter;
}

int main(){
   
return 0;
}