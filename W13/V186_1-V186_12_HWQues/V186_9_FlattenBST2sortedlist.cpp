#include<iostream>
#include<queue>
using namespace std;

/*****V186_8 : Flatten BST to sorted list [GFG : https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/]******/

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


//M2 : [TC : O(N); SC : O(H)]
/***********************MAIN FUNCTION IS THIS*****************************/
void helperRE(Node* root, Node*& prev){
    //Doing simple Inorder Traversal
    //Base Case
    if(root == NULL) return;

    //L
    helperRE(root->left, prev);
    
    //N
    prev->left = NULL;
    prev->right = root;
    prev = root;

    //R
    helperRE(root->right, prev);

    return;
}

Node* flatten(Node* root){
    if(root == NULL) return NULL;

    Node* dummy = new Node(-1);
    Node* prev = dummy;

    helperRE(root, prev);
    prev->left = NULL;
    prev->right = NULL;
    root = dummy->right;
    
    return root;
}



/***********************HELPER CODE STARTS*****************************/

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

void printLL(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}


int main(){
    /*
        5
        /\
       3  7
      /\  /\
     2  4 6 8
    */

    //5 3 2 4 7 6 8 -1

    Node* root = createBST();

    cout<<"BST is : "<<endl;
    LevelOrder(root);
    
    cout<<"BST after Flattening to LL : "<<endl;
    root = flatten(root);
    printLL(root);
   
return 0;
}