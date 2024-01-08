#include<iostream>
using namespace std;

/*****V183_2 : Maximum sum of Non-adjacent nodes [GFG : https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1]******/

//Node Structure
struct Node
{
    int data;
    Node* left;
    Node* right;
};

//M1 : Best Approach (TC: O(N)) 
pair<int, int> helperRE(Node* root){
    //Base Case
    if(root == NULL){
        return {0, 0};
    }
    
    auto Lpair = helperRE(root->left);
    auto Rpair = helperRE(root->right);
    pair<int, int> p;
    
    //Including the current Node
    p.first = Lpair.second + Rpair.second + root->data;
    
    //Excludng the current Node
    p.second = max(Lpair.first, Lpair.second) + max(Rpair.first, Rpair.second);
    
    return p;
}

//Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root){
    auto pair = helperRE(root);
    int ans = max(pair.first, pair.second);
    return ans;
}

// M2 : Brute Force (TC: O(N^2)) (Done by Me, gives TLE after 120/231 cases)
// int helperRE(Node* root, bool aboveTaken){
//     //Base cases
//     if(root == NULL){
//         return 0;
//     }
    
//     if(aboveTaken == true){
//         int leftSum = helperRE(root->left, false);
//         int rightSum = helperRE(root->right, false);
//         return leftSum + rightSum;
//     }
//     else{
//         //Case 1 : Taking current Node
//         int LSum1 = helperRE(root->left, true);
//         int RSum1 = helperRE(root->right, true);
//         int totSum1 = LSum1 + RSum1 + root->data;
        
//         //Case 2 : Not Taking current Node
//         int LSum2 = helperRE(root->left, false);
//         int RSum2 = helperRE(root->right, false);
//         int totSum2 = LSum2 + RSum2;
        
//         return max(totSum1, totSum2);
//     }
// }

// //Function to return the maximum sum of non-adjacent nodes.
// int getMaxSum(Node *root){
//     bool aboveTaken = false;
//     int ans = helperRE(root, aboveTaken);
//     return ans;
// }

int main(){
   
return 0;
}