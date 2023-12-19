#include<iostream>
#include<queue>
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

void preOrderTraversal(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //NLR
    //N
    cout<<root->data<<" ";

    //L
    preOrderTraversal(root->left);

    //R
    preOrderTraversal(root->right);
}

void InOrderTraversal(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //LNR
    //L
    InOrderTraversal(root->left);

    //N
    cout<<root->data<<" ";


    //R
    InOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //LRN
    //L
    PostOrderTraversal(root->left);

    //R
    PostOrderTraversal(root->right);

    //N
    cout<<root->data<<" ";
}

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    //Traversal Starts
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        cout<<front->data<<" ";

        if(front->left != NULL){
            q.push(front->left);
        }

        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

void LevelOrderTraversalStage2(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    //Traversal Starts
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
   Node* root = createTree();
   
   cout<<"pre Order : "<<endl;
   preOrderTraversal(root);
   cout<<endl;

   cout<<"In Order : "<<endl;
   InOrderTraversal(root);
   cout<<endl;

   cout<<"post Order : "<<endl;
   PostOrderTraversal(root);
   cout<<endl;

   cout<<"Level Order : "<<endl;
   LevelOrderTraversal(root);
   cout<<endl;

   cout<<"Level Order Stage 2: "<<endl;
   LevelOrderTraversalStage2(root);
   cout<<endl;
return 0;
}

/*
Possible Output for an input:
Enter value for Node:
10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1 
Left of Node :10
Enter value for Node: 
Left of Node :20
Enter value for Node: 
Left of Node :40
Enter value for Node: 
Right of Node :40
Enter value for Node: 
Right of Node :20
Enter value for Node: 
Right of Node :10
Enter value for Node: 
Left of Node :30
Enter value for Node: 
Left of Node :50
Enter value for Node: 
Right of Node :50
Enter value for Node: 
Right of Node :30
Enter value for Node: 
Left of Node :60
Enter value for Node: 
Right of Node :60
Enter value for Node: 
pre Order : 
10 20 40 30 50 60 
In Order : 
40 20 10 50 30 60 
post Order : 
40 20 50 60 30 10 
Level Order :
10 20 30 40 50 60
Level Order Stage 2:
10
20 30
40 50 60
*/