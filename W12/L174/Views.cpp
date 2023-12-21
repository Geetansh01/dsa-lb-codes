#include<iostream>
#include<queue>
#include<map>
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

Node* createTree(){
    int value = -1;
    cout<<"Enter value : ";
    cin>>value;
    //Base Case
    if(value == -1){
        return NULL;
    }

    //Make 1 one node
    Node* root = new Node(value);

    //Baki Recursion
    root->left = createTree();
    root->right = createTree();

    return root;

}

void PreOrderTraversal(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //1 case mai 
    cout<<root->data<<" ";

    //Baki recursion
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
    return;
}

void InOrderTraversal(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //1 case mai Baki RE
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);

    return;
}

void PostOrderTraversal(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }

    //1 case mai Baki RE
    InOrderTraversal(root->left);
    InOrderTraversal(root->right);
    cout<<root->data<<" ";

    return;
}

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    if(root != NULL){
        q.push(root);
        q.push(NULL);
    }

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

    return;
}

void printLeftView(Node* root, int level, vector<int>& leftView){
    //Base Case
    if(root == NULL){
        return;
    }

    if(level == leftView.size()){
        //Means leftView ki node milgyi, store it
        leftView.push_back(root->data);
    }

    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level+1, leftView);
    return;
}

void printRightView(Node* root, int level, vector<int>& rightView){
    //Base Case
    if(root == NULL){
        return;
    }

    if(level == rightView.size()){
        //Means leftView ki node milgyi, store it
        rightView.push_back(root->data);
    }

    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
    return;
}

void printTopView(Node* root){
    map<int, int> hdToNodeMap;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //If there is no entry for "hd" in map then store in map
        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = frontNode->data;
        }

        //Push childs
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout<<"Printing Top View : "<<endl;
    for(auto i : hdToNodeMap){
        cout<<i.second<<" ";
    }
}

void printBottomView(Node* root){
    map<int, int> hdToNodeMap;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //Entries in lower level replace entries in from upper levels as we are viewing from bottom
        hdToNodeMap[hd] = frontNode->data;

        //Push childs
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout<<"Printing Bottom View : "<<endl;
    for(auto i : hdToNodeMap){
        cout<<i.second<<" ";
    }
}

int main(){
    /*
        PreOrder Traversal of Tree with NULL as (-1) for reference:
        10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    */
    Node* root = createTree();

    cout<<endl;
    
    LevelOrderTraversal(root);

    cout<<endl;


    //Left View Printing
    vector<int> leftView;
    printLeftView(root, 0, leftView);

    cout<<"Printing Left View : "<<endl;
    for(int i = 0; i < leftView.size(); i++){
        cout<<leftView[i]<<" ";
    }

    cout<<endl;

    //Right View Printing
    vector<int> rightView;
    printRightView(root, 0, rightView);

    cout<<"Printing Right View : "<<endl;
    for(int i = 0; i < rightView.size(); i++){
        cout<<rightView[i]<<" ";
    }

    cout<<endl;

    //Top View Printing
    printTopView(root);

    cout<<endl;

    //Top Bottom Printing
    printBottomView(root);

return 0;
}