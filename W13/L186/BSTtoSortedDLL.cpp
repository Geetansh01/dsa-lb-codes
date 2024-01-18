#include<iostream>
using namespace std;

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

/*************************MAIN FUNCTION IS THIS***********************************/

void convertBST2SortedDLL(Node* root, Node*& head){
    //Base Case
    if(root == NULL){
        return;
    }

    //LNR -> NRL
    //R : Right subTree into DLL
    convertBST2SortedDLL(root->right, head);

    //Attach root to head
    root->right = head;
    if(head !=  NULL){
        head->left = root;
    }

    //Update head
    head = root;

    //L : left subtree to DLL
    convertBST2SortedDLL(root->left, head);
}

/*************************HELPER CODE STARTS HERE***********************************/

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


//PrintDll
void printDLL(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

int main(){
    //5 2 1 4 8 7 10 -1

    Node* root = createBST();
    
    cout<<"LevelOrder : "<<endl;
    LevelOrder(root);

    Node* head = NULL;
    convertBST2SortedDLL(root, head);

    cout<<"Printing Sorted DLL:";
    printDLL(head);

return 0;
}