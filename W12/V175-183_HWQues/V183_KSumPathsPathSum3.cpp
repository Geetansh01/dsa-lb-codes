#include<iostream>
#include<vector>
using namespace std;

/***183 : K-Sum Paths (Path Sum III) [LeetCode : https://leetcode.com/problems/path-sum-iii/description/]****/

//My Solution Below : TC: O(n^2) 
// V183 me bhi TC : O(n^2) ka soln tha but leetcode pe logo ne better kr rkha hai!

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helperRE(TreeNode* root, int& targetSum, int& ans, long int& sum){
    //Base Case
    if(root == NULL){
        return;
    }

    sum += root->val;
    if(sum == targetSum){
        ans++;
    }

    helperRE(root->left, targetSum, ans, sum);
    helperRE(root->right, targetSum, ans, sum);
    sum -= root->val;

    return;
}

void traverse(TreeNode* root, int& targetSum, int& ans, long int& sum){
    //Base Case
    if(root == NULL) return;

    helperRE(root, targetSum, ans, sum);
    traverse(root->left, targetSum, ans, sum);
    traverse(root->right, targetSum, ans, sum);
    return;
}

int pathSum(TreeNode* root, int targetSum) {
    if(root == NULL) return 0;

    int ans = 0;
    long int sum = 0;
    traverse(root, targetSum, ans, sum);
    return ans;
}

int main(){
   
return 0;
}