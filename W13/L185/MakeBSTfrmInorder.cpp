#include<iostream>
#include<queue>
using namespace std;

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

//insertIntoBST() is TC:O(n) in worst case i.e Skew Tree (n is number of nodes in BST)
Node* insertIntoBST(Node* root, int data){
    //Base Case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

Node* createBST(){
    Node* root = NULL; //Initially, when no data to make BST

    cout<<"Enter Data: ";
    int data;
    cin>>data;

    //-1 Means Stop Making the tree
    while(data != -1){
        root = insertIntoBST(root, data);
        cout<<"Enter Data: ";
        cin>>data;
    }

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

//This Func makes a balanced BST from given inorder traversal
Node* makeBalncedBSTInorder(vector<int>& v, int s, int e){
    //Base Case
    if(s > e) return NULL;

    //1 Case Hm
    int mid = s + (e-s)/2;
    Node* root = new Node(v[mid]);

    //Baki Recursion
    root->left = makeBalncedBSTInorder(v, s, mid-1);
    root->right = makeBalncedBSTInorder(v, mid+1, e);
    return root;
}

int main(){
    vector<int> inorder = {10, 20, 30, 40, 50, 60, 70};
    Node* root = makeBalncedBSTInorder(inorder, 0, inorder.size()-1);

    LevelOrder(root);

    return 0;
}