#include<iostream>
#include<vector>
#include<map>
using namespace std;

/***********/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solveUsingRE(TreeNode* root, bool parentLooted){
    //BC : leaf Node
    if(root == NULL){
        return 0;
    }

    int maxLoot = 0;
    //Case1 : parent was looted, don't loot current Node
    if(parentLooted){
        int skipCurrentNode = 0;
        skipCurrentNode += solveUsingRE(root->left, false);
        skipCurrentNode += solveUsingRE(root->right, false);
        maxLoot = skipCurrentNode;
    }
    else{
        //Case2 : parent was not looted, U may/ may Not loot current Node
        int lootCurrentNode = root->val;
        lootCurrentNode += solveUsingRE(root->left, true);
        lootCurrentNode += solveUsingRE(root->right, true);

        int skipCurrentNode = 0;
        skipCurrentNode += solveUsingRE(root->left, false);
        skipCurrentNode += solveUsingRE(root->right, false);

        maxLoot = max(lootCurrentNode, skipCurrentNode);
    }
    return maxLoot;
}

int solveUsingMem(TreeNode* root, bool parentLooted, map<pair<TreeNode*, bool>, int>& dp){
    //BC : leaf Node
    if(root == NULL){
        return 0;
    }

    if(dp.find({root,parentLooted}) != dp.end()) return dp[{root,parentLooted}];

    int maxLoot = 0;
    //Case1 : parent was looted, don't loot current Node
    if(parentLooted){
        int skipCurrentNode = 0;
        skipCurrentNode += solveUsingMem(root->left, false, dp);
        skipCurrentNode += solveUsingMem(root->right, false, dp);
        maxLoot = skipCurrentNode;
    }
    else{
        //Case2 : parent was not looted, U may/ may Not loot current Node
        int lootCurrentNode = root->val;
        lootCurrentNode += solveUsingMem(root->left, true, dp);
        lootCurrentNode += solveUsingMem(root->right, true, dp);

        int skipCurrentNode = 0;
        skipCurrentNode += solveUsingMem(root->left, false, dp);
        skipCurrentNode += solveUsingMem(root->right, false, dp);

        maxLoot = max(lootCurrentNode, skipCurrentNode);
    }
    dp[{root,parentLooted}] = maxLoot;

    return dp[{root,parentLooted}];
}

int rob(TreeNode* root) {
    int maxLoot = 0;
    
    // //Plain RE
    // bool parentLooted = false;
    // maxLoot = solveUsingRE(root, parentLooted);


    //Mem
    bool parentLooted = false;
    //If you want to use unordered_map then you will have to define custom hash function for "pair<TreeNode*, bool>"
    map<pair<TreeNode*, bool>, int> dp; //Stores answer for {A particular Node, parentLooted Status}
    maxLoot = solveUsingMem(root, parentLooted, dp);

    /*
        If you want to use 1D DP storage instead of 2d:

        1)To be able to use 1D DP storage, you need to design a recursive function that only accepts a particular tree node say X and returns the maximum loot for the entire tree below it (i.e entire tree with X as root). 

        2)In this function, you have two choices for each node: 
            1)loot the current node and make recursive calls to its grandchildren as: (total 4 RE calls will be there)
                X->leftchild->leftchild ko
                X->leftchild->rightchild ko

                X->rightchild->leftchild ko
                X->rightchild->rightchild ko
        
        or 2)exclude the current node and make recursive calls to its children.

        3)This modified recursive function takes only a node as a parameter, enabling you to implement it using 1D Dynamic Programming.
        
        4)"parentLooted" is dropped in this approach!
    */
   
    return maxLoot;
}

int main(){
   
return 0;
}