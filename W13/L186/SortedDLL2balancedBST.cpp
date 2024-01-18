#include<iostream>
using namespace std;

#include<iostream>
#include<queue>
using namespace std;

/***Same approach as in "L185 : Make Balanced BST from Inorder traversal" but this time in DLL instead of arrays**/

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

//DLL has no significance here, only Linked List (LL) hoti to bhi same hota
Node* sortedDLL2BST(Node*& head, int n){
    /*
        1)We will try to make a Height balanced BST from given LL, so main idea is that middle node of LL will be the root of BST & equal nodes to left and right of it.
    */

    //Base Case
    if(n <= 0 || head == NULL){ 
        return NULL;
    }

    //To Understand : In the given LL, suppose you are standing on the main to-be-root-node of the entire BST (jo BST bnna hai), head is currently on the starting node of this LL

    //RE LeftSubtree bnake dega
    Node* leftSubtree = sortedDLL2BST(head, n/2); //(n/2) bcz Total (n) nodes in LL , out of which 1 root node, (n/2) nodes for left subtree, (n-1-n/2) nodes for right subtree 

    //At this point, head is on to-be-root-node of the entire BST, we will return this as root of BST 
    //head is now here bcz we update head in each RE call ... see Line(1)
    Node* root = head;

    //root ke left pe leftsubtree attach kr do
    root->left = leftSubtree;

    //Ab RE ko age ki LL se right subtree nikalne ko khenge bt uske liye head ko age wali LL ke starting node pe hona chaiye, so update head
    head = head->right; //.......................Line(1)

    //Ab RE right Subtree bnake dega
    Node* rightSubtree = sortedDLL2BST(head, n-1-n/2);

    //Right subtree ko attach kro 
    root->right = rightSubtree;

    return root;
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

    Node* root2 = NULL;
    root2 = sortedDLL2BST(head, 7);
    cout<<"Printing Balanced BST level Order Trav:"<<endl;
    LevelOrder(root2);

return 0;
}