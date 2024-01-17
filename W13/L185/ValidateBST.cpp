#include<iostream>
#include<limits.h>
using namespace std;




// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//M1 : USing range concept
//TC: O(n) (n is number of nodes in BST)

bool helperRE(TreeNode* root, long int lowerBound, long int upperBound){
    //Base Case
    if(root == NULL) return true;

    bool cond1 = (root->val > lowerBound);
    bool cond2 = (root->val < upperBound);
    bool leftAns = helperRE(root->left, lowerBound, root->val);
    bool rightAns = helperRE(root->right, root->val, upperBound);

    if(cond1 && cond2 && leftAns && rightAns){
        return true;
    }
    else{
        return false;
    }
}

bool isValidBST(TreeNode* root) {
    long int lowerBound = LONG_MIN;
    long int upperBound = LONG_MAX;

    bool ans = helperRE(root, lowerBound, upperBound);
    return ans;
}

int main(){
   
return 0;
}