#include<iostream>
using namespace std;

/****Kth Ancestor in a Tree [GFG : https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1]****/
//My own logic below
struct Node
{
	int data;
	struct Node *left, *right;
};


void helperRE(Node* root, int& k, int target, int& ans, bool& found){
    //Base Cases
    if(root == NULL){
        return;
    }
    if(root->data == target){
        found = true;
        return;
    }
    
    helperRE(root->left, k, target, ans, found);
    if(found == true){
        k--;
        if(k == 0){
            ans = root->data;
        }
        return;
    }
    helperRE(root->right, k, target, ans, found);
    if(found == true){
        k--;
        if(k == 0){
            ans = root->data;
        }
        return;
    }
    return;
}

int kthAncestor(Node *root, int k, int target)
{   
    bool found = false;
    int ans = -1;
    helperRE(root, k, target, ans, found);
    return ans;
}

int main(){
   
return 0;
}