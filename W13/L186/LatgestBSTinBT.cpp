#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;


/********[GFG : https://www.geeksforgeeks.org/problems/largest-bst/1]*********/

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

/*************************MAIN FUNCTION IS THIS***********************************/
class NodeData{
    public:
        int size;
        int maxVal;
        int minVal;
        bool validBST;

        //Constructor
        NodeData(){}

        //Constructor
        NodeData(int size, int max, int min, bool flag){
            this->size = size;
            this->maxVal = max;
            this->minVal = min;
            this->validBST = flag;
        }
};

//Method : Bottom to Up (TC: O(n) n is number of nodes in BST)
NodeData* findLargestBST(Node* root, int& ans){
    //Base Case
    if(root == NULL){
        NodeData* temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    //Doing traversal in LRN 
    //L
    NodeData* leftAns = findLargestBST(root->left, ans);

    //R
    NodeData* rightAns = findLargestBST(root->right, ans);

    //N
    NodeData* currNodeAns = new NodeData();
    
    currNodeAns->size = leftAns->size + rightAns->size + 1;
    currNodeAns->maxVal = max(root->data, rightAns->maxVal);
    currNodeAns->minVal = min(root->data, leftAns->minVal);

    if(leftAns->validBST && rightAns->validBST && (root->data > leftAns->maxVal) && (root->data < rightAns->minVal)){
        currNodeAns->validBST = true;
    }
    else{
        currNodeAns->validBST = false;
    }

    if(currNodeAns->validBST){
        ans = max(ans, currNodeAns->size);
    }

    return currNodeAns;
}



/*************************HELPER CODE STARTS HERE***********************************/

//Returns root node of created tree
Node* createTree(){
    int data;
    cout<<"Enter value for Node: "<<endl;
    cin>>data;
    
    //Base Case
    if(data == -1){
        return NULL;
    }


    //Step1: Create Node
    Node* root = new Node(data);

    //Step2: Create Left SubTree
    cout<<"Left of Node :"<<root->data<<endl;
    root->left = createTree();
    
    //Step3: Create Right SubTree
    cout<<"Right of Node :"<<root->data<<endl;
    root->right = createTree();

    return root;
}

//Level order trav to print tree
void LevelOrder(Node* root){
    cout<<endl; //Start Printing from new line
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}

int main(){
    //50 30 5 -1 -1 20 -1 -1 60 45 -1 -1 70 65 -1 -1 80 -1 -1
    //Ans for above tree : 5

    Node* root = createTree(); //Creates BT from given input (Function copied frm "L182 : MakingBST")
    cout<<"Printing Binary Tree: "<<endl;
    LevelOrder(root);

    int ans = 0;
    findLargestBST(root, ans);
    cout<<"Largest BST Size is : "<<ans<<endl;
    
    return 0;
}