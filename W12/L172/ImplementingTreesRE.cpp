#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }

};

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

int main(){
   Node* root = createTree(); 
return 0;
}