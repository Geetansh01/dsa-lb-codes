#include<iostream>
#include<limits.h>
#include<unordered_map>
#include<queue>
using namespace std;

/***V183_3 : Burning Tree 🔥 [GFG : https://www.geeksforgeeks.org/problems/burning-tree/1]****/



//M1 : My Approach (TC: O(N))
//GFG Hard Marked, I did in 1st try 
//Also, my solution is much better than the one in solution video (although same TC), dozens of DS used there.

//Node Structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int getHeightUnburnt(Node* root, unordered_map<Node*, bool>& burntNodes){
    if(root == NULL) return 0;
    if(burntNodes.find(root) != burntNodes.end()) return 0; //A burnt Node encountered
    
    int leftH = getHeightUnburnt(root->left, burntNodes);
    int rightH = getHeightUnburnt(root->right, burntNodes);
    return max(leftH, rightH)+1;
}

void helperRE(Node* root, int& target, bool& onFire, int& tp, int& TotTime, unordered_map<Node*, bool>& burntNodes){
    //Base cases
    if(root == NULL) return;
    if(root->data == target){
        onFire = true;
        int height = getHeightUnburnt(root, burntNodes)-1;
        TotTime = max(TotTime, height);
        burntNodes.insert({root, true}); //Node marked burnt
        // root->data = INT_MIN; //Alter marking method but it will destroy the original tree
        return;
    }
    
    helperRE(root->left, target, onFire, tp, TotTime, burntNodes);
    if(onFire){
        tp++;
        int height = getHeightUnburnt(root, burntNodes)-1;
        TotTime = max(TotTime, height + tp);
        burntNodes.insert({root, true}); //Node marked burnt
        return;
    }
    
    helperRE(root->right, target, onFire, tp, TotTime, burntNodes);
    if(onFire){
        tp++;
        int height = getHeightUnburnt(root, burntNodes)-1;
        TotTime = max(TotTime, height + tp);
        burntNodes.insert({root, true}); //Node marked burnt
        return;
    }
    
}

int minTime(Node* root, int target){
    int TotTime = 0;
    bool onFire = false;
    int tp = 0; //Time Passed since 🔥 started
    unordered_map<Node*, bool> burntNodes; //storing burnt nodes
    helperRE(root, target, onFire, tp, TotTime, burntNodes);
    return TotTime;
}

//M2: From soln video (Also TC: O(N) but takes more Space)
// Node* makeNode2ParentMapAndFindTarget(Node* root, int& target, unordered_map<Node*, Node*>& Parent){
//     Node* targetNode = NULL;
    
//     //Level Order Traversal
//     queue<Node*> q;
//     q.push(root);
//     Parent[root] = NULL;
//     while(!q.empty()){
//         Node* front = q.front();
//         q.pop();
        
//         if(front->data == target){
//             targetNode = front; 
//         }
        
//         if(front->left != NULL){
//             q.push(front->left);
//             Parent.insert({front->left, front});
//         }
//         if(front->right != NULL){
//             q.push(front->right);
//             Parent.insert({front->right, front});
//         }
//     }
    
//     return targetNode;
// }

// void burnTree(Node* targetNode, int& T, unordered_map<Node*, Node*>& Parent){
//     unordered_map<Node*, bool> burntNodes;
//     queue<Node*> q; //Stores the nodes being burnt currently
    
//     q.push(targetNode); //Start Burning at target
//     burntNodes[targetNode] = true;
//     while(!q.empty()){
        
//         int currSize = q.size();
//         bool isFireSpread = false;
//         for(int i = 0; i < currSize; i++){
//             Node* front = q.front();
//             q.pop();
            
//             //Spread the fire
//             if(front->left != NULL && (burntNodes.find(front->left) == burntNodes.end())){
//                 q.push(front->left);
//                 burntNodes.insert({front->left, true});
//                 isFireSpread = true;
//             }
//             if(front->right != NULL && !burntNodes[front->right]){
//                 q.push(front->right);
//                 burntNodes[front->right] = true;
//                 isFireSpread = true;
//             }
//             if(Parent[front] && !burntNodes[Parent[front]]){
//                 q.push(Parent[front]);
//                 burntNodes[Parent[front]] = true;
//                 isFireSpread = true;
//             }
//         }
        
//         if(isFireSpread == true) T++;
//     }
// }

// int minTime(Node* root, int target) {
//     unordered_map<Node*, Node*> Parent; //Node -> Parent Node
//     Node* targetNode = makeNode2ParentMapAndFindTarget(root, target, Parent);
    
//     //Now Burn the tree
//     int T = 0; //time
//     burnTree(targetNode, T, Parent);
//     return T;
// }

int main(){
   
return 0;
}

