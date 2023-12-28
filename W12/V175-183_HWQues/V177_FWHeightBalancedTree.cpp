#include<iostream>
#include<math.h>
using namespace std;

/*****V177 : FW To Find Height Balanced Tree [LeetCode : https://leetcode.com/problems/balanced-binary-tree/submissions/]*******/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Modified height() function
int heightRE(TreeNode* root, int ans){
    //Base Case
    if(root == NULL){
        return 0;
    }

    int leftHeight = heightRE(root->left, ans);
    int rightHeight = heightRE(root->right, ans);
    if(leftHeight == -1 || rightHeight == -1){
        return -1;
    }
    else if(fabs(leftHeight - rightHeight) > 1){
        return -1;
    }
    else{
        //return Height
        return max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(TreeNode* root) {
    int ans = -1;
    //Modified height() function
    ans = heightRE(root, ans);
    if(ans == -1){
        return false;
    }
    else{
        return true;
    }
}

int main(){
   
return 0;
}