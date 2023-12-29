#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/****V180 : Zig-Zag Traversal [LeetCode : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/]*****/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//My Solution : using Dequeue (TC : O(N)) {My soln is same TC as that of Lakshay Bhaiya but unnecessarily complicated, See Lakshay Bhaiya's soln in "V180 : Zig-Zag Traversal"}
/*
    My solution works as follows :
    1)Initially insert root and NULL in the dequeue. Now do (2), (3) alternately for each level:
    2)Dequeue ke front se pop kro and back me insert kro.
      Popped node ka phle left child then right child insert kro.
    3)Dequeue ke back se pop kro and front me insert kro.
      Popped node ka phle right child then left child insert kro.

*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > ans = {};
    if(root == NULL) return ans;

    deque<TreeNode* > dq;
    dq.push_front(NULL);
    dq.push_front(root);
    int level = 1;
    bool L2R = true;

    while(!dq.empty()){
        if(ans.size() < level){
            vector<int> v = {};
            ans.push_back(v);
        }

        if(L2R == true){
            TreeNode* temp = dq.front();
            dq.pop_front();
            
            if(temp != NULL){
                ans[level - 1].push_back(temp->val);

                if(temp->left != NULL){
                    dq.push_back(temp->left);
                }
                if(temp->right != NULL){
                    dq.push_back(temp->right);
                }
            }
            else{
                if(!dq.empty()){
                    dq.push_front(NULL);
                    level++;
                    L2R = !L2R;
                }
            }
        }
        else{
            //If L2R is false
            TreeNode* temp = dq.back();
            dq.pop_back();

            if(temp != NULL){
                ans[level - 1].push_back(temp->val);

                if(temp->right != NULL){
                    dq.push_front(temp->right);
                }
                if(temp->left != NULL){
                    dq.push_front(temp->left);
                }
            }
            else{
                if(!dq.empty()){
                    dq.push_back(NULL);
                    level++;
                    L2R = !L2R;
                }
            }
        }
    }
    return ans;
}

int main(){
   
return 0;
}