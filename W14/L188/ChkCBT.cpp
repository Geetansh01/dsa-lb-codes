#include<iostream>
#include<queue>
using namespace std;

/******Check Completeness of a Binary Tree [LeetCode : https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/]*******/

//M1 : Level Order Traversal
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


//M2 : using Node count
//M2 Gives "signed integer overflow" on leetCode as they have HUGE test cases 
//But it gets accepted on GFG [https://www.geeksforgeeks.org/problems/complete-binary-tree/1]

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val){
//         data = val;
//         left = right = NULL;
//     }
// };

// long int getNodeCount(Node* root){
//     //Base Case
//     if(root == NULL) return 0;

//     //LRN Traversal
//     long int left = getNodeCount(root->left);
//     long int right = getNodeCount(root->right);

//     return left + right + 1;     
// }

// void getMaxIndex(Node* root, long int rI, long int& maxIndex){
//     //Base Case
//     if(root == NULL) return;

//     //NLR Traversal
//     maxIndex = max(maxIndex, rI);
//     getMaxIndex(root->left, 2*rI, maxIndex);
//     getMaxIndex(root->right, 2*rI + 1, maxIndex);

//     return;     
// }

// bool isCompleteBT(Node* root){
//     long int tot = getNodeCount(root);
//     long int rootIndex = 1;
//     long int maxIndex = rootIndex;
//     getMaxIndex(root,rootIndex, maxIndex);

//     if(maxIndex != tot){
//         return false;
//     }
//     else{
//         return true;
//     }
// }



int main(){
   
return 0;
}