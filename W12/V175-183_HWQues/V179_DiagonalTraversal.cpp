#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

/****Q179 : Diagonal Traversal of Binary Tree [GFG : https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1]******/

//Node structure
struct Node
{
    int data;
    Node* left, * right;
};

//M1 : using queues
vector<int> diagonal(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
  
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp != NULL){
            if(temp->left != NULL){
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

//M2 : using map
// void helperRE(Node* root, map<int, queue<int> >& mp, int diagonal_num){
//     //Base Case
//     if(root == NULL) return;
    
//     if(mp.find(diagonal_num) == mp.end()){
//         queue<int> tempQ;
//         tempQ.push(root->data);
//         mp[diagonal_num] = tempQ;
//     }
//     else{
//         mp[diagonal_num].push(root->data);    
//     }
    
//     //NLR Traversal
//     helperRE(root->left, mp, diagonal_num+1);
//     helperRE(root->right, mp, diagonal_num);
    
//     return;
// }

// vector<int> diagonal(Node *root){
//     vector<int> ans;
//     map<int, queue<int> > mp;
//     int diagonal_num = 0;
    
//     helperRE(root, mp, diagonal_num);
//     for(int i = 0; i < mp.size(); i++){
//         while(!mp[i].empty()){
//             ans.push_back(mp[i].front());
//             mp[i].pop();
//         }
//     }
//     return ans;
// }

int main(){
   
return 0;
}


