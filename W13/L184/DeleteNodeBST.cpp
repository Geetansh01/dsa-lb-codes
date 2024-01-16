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

//TC: O(n) for worst case (i.e Skew Tree me sabse last level ki node delete krna) (n is number of nodes in tree)
Node* deleteFromBST(Node* root, int target){
    //S1 : Target Dhundo
    //S2 : Target delete kro

    //Base Case
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        //Target Mil Gya, ab Delete Krenege
        //4 possible cases for deletion

        //Case 1 : leaf Node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //Case 2 : Left child non Null and right child Null
        else if(root->left != NULL && root->right == NULL){
            Node* ChildSubtree = root->left;
            delete root;
            return ChildSubtree;
        }

        //Case 3 : Left child Null and Right child Non Null
        else if(root->left == NULL && root->right != NULL){
            Node* ChildSubtree = root->right;
            delete root;
            return ChildSubtree;
        }

        //Case 4 : Both left and right child Non Null
        else{
        //Option 1 : left subtree ki max value Lao
            Node* maxi = maxValueOfBST(root->left);

            //Replacement
            root->data = maxi->data;

            //Delete Maxi node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;

        //Option 2 : Right SubTree ki min value lao 

        }
    }
    else if(root->data > target){
        //left me jao
        root->left = deleteFromBST(root->left, target);
    }
    else{
        //right me jao
        root->right = deleteFromBST(root->right, target);
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

int main(){
    //50 30 60 25 40 70 80 55 -1

    Node* root = createBST();
    
    cout<<"LevelOrder : "<<endl;
    LevelOrder(root);

    //Deletion Starts
    int target;
    cout<<"Enter target to be deleted :";
    cin>>target;
    while(target != -1){
        root = deleteFromBST(root, target);
        cout<<"Level Order Trav : "<<endl;
        LevelOrder(root);
        cout<<"Enter target to be deleted :";
        cin>>target;
    }

    return 0;
}