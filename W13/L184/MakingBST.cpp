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

Node* minValueOfBST(Node*& root){ //passing by reference to comply with the Habit we developed while doing Linked List
    if(root == NULL){
        cout<<"No min value"<<endl;
        return NULL;
    }
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValueOfBST(Node*& root){ //passing by reference to comply with the Habit we developed while doing Linked List
    if(root == NULL){
        cout<<"No min value"<<endl;
        return NULL;
    }
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
    //Base Case
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }

    bool found = false;
    if(target > root->data){
        found = searchInBST(root->right, target);
    }
    else{
        found = searchInBST(root->left, target);
    }

    return found;
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

//Preorder trav
void PreOrder(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //NLR  
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

//InOrder trav
void InOrder(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //LNR 
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
    return;
}

//PostOrder trav
void PostOrder(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //LRN 
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
    return;
}

int main(){
    //50 30 20 25 40 60 70 80 55 -1

    Node* root = createBST();
    
    cout<<"LevelOrder : "<<endl;
    LevelOrder(root);

    cout<<"PreOrder : ";
    PreOrder(root);

    cout<<"InOrder : ";
    InOrder(root);

    Node* minNode = minValueOfBST(root);
    if(minNode == NULL){
        cout<<"No node in BST"<<endl;
    }
    else{
        cout<<"Min Value: "<<minNode->data;
        cout<<endl;
    }

    Node* maxNode = maxValueOfBST(root);
    if(minNode == NULL){
        cout<<"No node in BST"<<endl;
    }
    else{
        cout<<"Max Value: "<<maxNode->data;
        cout<<endl;
    }

    //Searching in BST (TC: O(n) in worst cast i.e Skew Tree; n = no. of nodes in BST)
    int target;
    cout<<"Enter Target : ";
    cin>>target;

    while(target != -1){
        bool found = searchInBST(root, target);
        if(found){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }

        cout<<"Enter Target : ";
        cin>>target;
    }

return 0;
}