#include<iostream>
#include<vector>
using namespace std;

/********V186_10 : Replace every element with the least greater element on its right [GFG : https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1]**************/

class Node{
  public:
  
  int data;
  Node* left;
  Node* right;
  
  Node(int x){
    this->data = x;
    this->left = NULL;
    this->right = NULL;
  }
  //Also make ~Node(){...} in interview!
};

class Solution{
    public:
    
    Node* insertInBST(Node* root, int val, int& InOrderSucc){
        if(root == NULL) return new Node(val);
        
        if(val >= root->data){
            root->right = insertInBST(root->right, val, InOrderSucc);
        }
        else{
            InOrderSucc = root->data;
            root->left = insertInBST(root->left, val, InOrderSucc);
        }
        
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), -1);
        
        Node* root = NULL;
        for(int i = arr.size()-1; i >= 0; i--){
            int InOrderSucc = -1;
            root = insertInBST(root, arr[i], InOrderSucc);
            ans[i] = InOrderSucc;
        }
        
        return ans;
    }
};

int main(){
   
return 0;
}