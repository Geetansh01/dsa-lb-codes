#include<iostream>
#include<vector>
using namespace std;


//PreReq : Two Sum II - Input Array Is Sorted (See L185 folder)

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getInOrder(TreeNode* root, vector<int>& inorder){
    //base case
    if(root == NULL){
        return;
    }

    //LNR (InOrder)
    //L
    getInOrder(root->left, inorder);
    //N
    inorder.push_back(root->val);
    //R
    getInOrder(root->right, inorder);

    return;
}

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    getInOrder(root, inorder);

    //Find ans using 2 pointers
    int s = 0;
    int e = inorder.size() - 1;
    while(s < e){
        int sum = inorder[s] + inorder[e];
        if(sum == k){
            return true;
        }
        else if(sum > k){
            e--;
        }
        else if(sum < k){
            s++;
        }
    }

    return false;
}

int main(){
   
return 0;
}





