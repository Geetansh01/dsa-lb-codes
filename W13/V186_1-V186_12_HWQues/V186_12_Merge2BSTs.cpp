#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*****V186_12 : Merge two BSTs [GFG : https://www.geeksforgeeks.org/problems/merge-two-bst-s/1]*****/
//TC :  O(M+N) where M and N are the sizes of the two BSTs
//SC : O(Height of BST1 + Height of BST2 + M + N(for storing the answer))

//Pre Req : "V186_4_PreReq" BST Traversal iteratively (using stack)
//U wrote the following soln in 1st try (& Lakshay Bhaiya ka bhi same tha) :p

//Main Logic:
//Just perform Inorder Travs of the 2 BSTs simultaneously, (Similar to merge 2 sorted Arrays)


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> merge(Node *rootA, Node *rootB)
{
    vector<int> ans;
    Node* ptrA = rootA;
    Node* ptrB = rootB;
    
    stack<Node*> sA;
    stack<Node*> sB;
    
    while((ptrA != NULL || !sA.empty()) && (ptrB != NULL || !sB.empty())){

        while(ptrA != NULL){
            sA.push(ptrA);
            ptrA = ptrA->left;
        }

        while(ptrB != NULL){
            sB.push(ptrB);
            ptrB = ptrB->left;
        }
        
        Node* topA = sA.top();
        Node* topB = sB.top();
        
        if(topA->data < topB->data){
            sA.pop();
            ans.push_back(topA->data);
            ptrA = topA->right;
        }

        else if(topA->data > topB->data){
            sB.pop();
            ans.push_back(topB->data);
            ptrB = topB->right;
        }
        
        else{
            sA.pop();
            ans.push_back(topA->data);
            ptrA = topA->right;
            
            sB.pop();
            ans.push_back(topB->data);
            ptrB = topB->right;
        }
    }

    while(ptrA != NULL || !sA.empty()){

        while(ptrA != NULL){
            sA.push(ptrA);
            ptrA = ptrA->left;
        }

        Node* topA = sA.top();

        sA.pop();
        ans.push_back(topA->data);
        ptrA = topA->right;

    }

    while(ptrB != NULL || !sB.empty()){

        while(ptrB != NULL){
            sB.push(ptrB);
            ptrB = ptrB->left;
        }

        Node* topB = sB.top();

        sB.pop();
        ans.push_back(topB->data);
        ptrB = topB->right;

    }
    
    return ans;
}

int main(){
   
return 0;
}





