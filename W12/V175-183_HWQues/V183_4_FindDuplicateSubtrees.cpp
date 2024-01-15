#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/****V183_4 : Find Duplicate Subtrees [LeetCode : https://leetcode.com/problems/find-duplicate-subtrees/description/]******/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> ans;
unordered_map<string, int> mp;

//Encode Given Tree using PreOrder(NLR) traversal
string encodeTree(TreeNode* root){
    //Base Case
    if(root == NULL) return "N";

    string l = encodeTree(root->left);
    string r = encodeTree(root->right);
    string encodedStr = to_string(root->val) + "," + l + "," + r;

    //Below, I am repeatedly using find(), [] operator, insert() for better readability. But if we consider the worst case TC for insertion/look-up in unordered_map (i.e TC:O(n) ; n being the size of unordered_map) then this is a wastage.

    //See how to efficiently do what is done below in "V182 : Vertical Order Traversal" (Note that a ordered map is used there! So optimization there was a must as Average case there is not o(1)!)
    
    if(mp.find(encodedStr) != mp.end()){
        if(mp[encodedStr] == 1){
            ans.push_back(root);
        }
        mp[encodedStr]++;
    }
    else{
        mp.insert({encodedStr, 1});
    }
    return encodedStr;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    encodeTree(root);
    return ans;
}

int main(){
   
return 0;
}