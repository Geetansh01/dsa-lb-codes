#include<iostream>
#include<vector>
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

vector<TreeNode*> solveUsingRE(int start,int end){
    //BC
    if(start == end){
        TreeNode* temp = new TreeNode(start);
        return {temp}; 
    }
    if(start > end){
        return {NULL}; //Invalid range so return vector with NULL (i.e No BST present in vector)
    }

    vector<TreeNode*> allBSTs;
    for(int value = start; value <= end; value++){

        //RE Call for left range
        vector<TreeNode*> leftTrees = solveUsingRE(start, value - 1);

        //RE Call for right range
        vector<TreeNode*> rightTrees = solveUsingRE(value + 1, end);

        for(auto leftBST : leftTrees){
            for(auto rightBST : rightTrees){
                TreeNode* currRoot = new TreeNode(value);
                currRoot->left = leftBST;
                currRoot->right = rightBST;
                allBSTs.push_back(currRoot);
            }
        }
    }

    return allBSTs;
}

vector<TreeNode*> solveUsingMem(int start,int end, vector<vector<vector<TreeNode*> > >& dp){
    //BC
    if(start == end){
        TreeNode* temp = new TreeNode(start);
        return {temp}; 
    }
    if(start > end){
        return {NULL}; //Invalid range so return empty vector
    }

    if(dp[start][end].size() > 0){
        return dp[start][end];
    }

    vector<TreeNode*> allBSTs;
    for(int value = start; value <= end; value++){

        //RE Call for left range
        vector<TreeNode*> leftTrees = solveUsingMem(start, value - 1, dp);

        //RE Call for right range
        vector<TreeNode*> rightTrees = solveUsingMem(value + 1, end, dp);

        for(auto leftBST : leftTrees){
            for(auto rightBST : rightTrees){
                TreeNode* currRoot = new TreeNode(value);
                currRoot->left = leftBST;
                currRoot->right = rightBST;
                allBSTs.push_back(currRoot);
            }
        }
    }
    dp[start][end] = allBSTs;

    return dp[start][end];
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> allBSTs;

    //Plain RE
    // int start = 1;
    // int end = n;
    // allBSTs = solveUsingRE(start, end);

    //Mem
    int start = 1;
    int end = n;
    vector<TreeNode*> emptyV = {};
    vector<vector<vector<TreeNode*> > > dp(n + 1, vector<vector<TreeNode*>> (n + 1, emptyV) ); //roe x coll :: start x end
    //Mehnat wala way above, you could have simply used an unordered_map or map as your dp storage! 
    allBSTs = solveUsingMem(start, end, dp);

    return  allBSTs;
}

int main(){
   
return 0;
}