#include<iostream>
#include<queue>
#include<map>
using namespace std;

/****Boundary Traversal of binary tree [GFG : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?track=Placement]******/

/*
    Question(from GFG):
    Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
    1)Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 

    2)Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

    3)Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

    Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(){
    int value = -1;
    cout<<"Enter value : ";
    cin>>value;
    //Base Case
    if(value == -1){
        return NULL;
    }

    //Make 1 one node
    Node* root = new Node(value);

    //Baki Recursion
    root->left = createTree();
    root->right = createTree();

    return root;

}

void printLeftBoundary(Node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    ans.push_back(root->data);
    if(root->left != NULL){
        //Agr left jana possible hai to jao
        printLeftBoundary(root->left, ans);
    }
    else{
        //right tbhi jao jb laft jana not possible
        printLeftBoundary(root->right, ans);
    }
    return; 
}

void printLeafBoundary(Node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }

    //U can follow any traversal, i am doing NLR(PreOrder Here)
    if(root->left == NULL && root->right == NULL){
        //Print leaf Node
        ans.push_back(root->data);
    }
    printLeafBoundary(root->left, ans);
    printLeafBoundary(root->right, ans);
}

void printRightBoundary(Node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right != NULL){
        //Agr right jana possible hai to jao
        printRightBoundary(root->right, ans);
    }
    else{
        //left tbhi jao jb right jana not possible
        printRightBoundary(root->left, ans);
    }
    ans.push_back(root->data);
    return;
}

vector <int> BoundaryTraversal(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    //Printing Root separately ----(1)
    cout<<root->data<<" ";

    //Printing Left Boundary
    printLeftBoundary(root->left, ans);

    //Printing leaf Nodes
    /*
        printLeafBoundary(root); ---> Can't do this

        Bcz consider the case where the tree has just one node (the root node). 
        In this case the root Node is also a leaf Node.
        So, we will print the root node 2X (once here & once in ----(1)) 
    */
    printLeafBoundary(root->left, ans);
    printLeafBoundary(root->right, ans);

    //Printing Right Boundary
    printRightBoundary(root->right, ans);
    
    return ans;
}

int main(){
   /*
        PreOrder Traversal of Tree with NULL as (-1) for reference:
        10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    */
    Node* root = createTree();
    vector<int> Answer = BoundaryTraversal(root);

    for(auto x : Answer){
        cout<<x<<" ";
    } 
return 0;
}