#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

/*****V182 : Vertical Order Traversal [LeetCode : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/]*****/

//My Solution below (TC : O(n^2) ; SC : O(n))
//My Soln performs similar (better?) to soln in V182, i used a custom class "Triplet" but V182 uses heavy STL (multiset etc..)

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//I made this class 
class Triplet{
    public:
    TreeNode* node;
    int HL;
    int VL;

    Triplet(TreeNode* node, int HL, int VL){
        this->node = node;
        this->HL = HL;
        this->VL = VL;
    }
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans; 

    queue<Triplet> q;
    Triplet firstTriplet (root, 0, 0);
    q.push(firstTriplet);
    map<int, vector<Triplet> > mp;

    while(!q.empty()){
        Triplet temp = q.front();
        q.pop();
        if(mp.find(temp.VL) == mp.end()){
            vector<Triplet> tempV = {};
            pair<int, vector<Triplet> > p = {temp.VL, tempV}; //line (1)
            mp.insert(p); //line (2)

            // mp[temp.VL] = tempV; //line (3)

            /*
                [A] line(3) can be used instead of (1) & (2) but that would be slightly less efficient. (Runtime goes from 7ms to 3ms on leetCode)
                
                [B] Why? (from chatGPT): using "insert", the map performs a single lookup to determine if the key exists, and if not, it directly inserts the new key-value pair. On the other hand, using the square bracket operator involves two lookups: one to check existence and another to perform the assignment.

            */

            mp[temp.VL].push_back(temp);
        }
        else{
            mp[temp.VL].push_back(temp);
            int level = temp.VL;
            int i = mp[level].size()-1;
            while(i > 0){
                if(mp[level][i].HL == mp[level][i-1].HL && mp[level][i].node->val < mp[level][i-1].node->val){
                    swap(mp[level][i], mp[level][i-1]);
                    i--;
                }
                else{
                    break;
                }
            }
        }

        if(temp.node->left != NULL){
            Triplet Lchild (temp.node->left, temp.HL + 1, temp.VL - 1);
            q.push(Lchild);
        }

        if(temp.node->right != NULL){
            Triplet Rchild (temp.node->right, temp.HL + 1, temp.VL + 1);
            q.push(Rchild);
        }

    }

    //Now the map is ready, make the "ans" vector
    for(auto it = mp.begin(); it != mp.end(); it++){
        vector<int> temp = {};
        for(int i = 0; i < it->second.size(); i++){
            temp.push_back((it->second)[i].node->val);
        }
        ans.push_back(temp);
    }

    return ans;        
}


int main(){
   
return 0;
}