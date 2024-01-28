#include<iostream>
#include<queue>
using namespace std;

/*************************HELPER CODE STARTS HERE***********************************/
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



/*************************MAIN FUNCTION IS THIS***********************************/

void storeInorderTrav(Node* root, vector<int>& inorder){
    //BC
    if(root ==  NULL) return;

    storeInorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    storeInorderTrav(root->right, inorder);
}

void replaceUsingPostOrder(Node* root, vector<int>& inorder, int& index){
    if(root == NULL){
        return;
    }

    //LRN
    replaceUsingPostOrder(root->left, inorder, index);
    replaceUsingPostOrder(root->right, inorder, index);
    root->data = inorder[index];
    index++;

}

void convertCBTBST2MaxHeap(Node* root){
    //STEP 1 : Store Inorder LNR
    vector<int> inorder;
    storeInorderTrav(root, inorder);

    //Step 2 : Replace node values with Inorder Trav using Post Order Trav
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);

    // return root;
}




int main(){
    //100 50 150 40 60 110 200 20 -1

    Node* root = createBST();
    
    cout<<"LevelOrder : "<<endl;
    LevelOrder(root);

    cout<<endl<<"Printing After Converting to Heap : "<<endl;
    convertCBTBST2MaxHeap(root);

    cout<<"LevelOrder : "<<endl;
    LevelOrder(root);

    return 0;
}