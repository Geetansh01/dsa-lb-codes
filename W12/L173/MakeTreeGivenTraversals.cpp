#include<iostream>
#include<queue>
#include<map>
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

//This searching is TC : O(n) 
int searchInOrder(int inOrder[], int size, int target){
    for(int i = 0; i < size; i++){
        if(inOrder[i] == target){
            return i;
        }
    }
    return -1;
}

//Using map to search in TC : O(log n) {could have used unordered_map for TC : O(1) but then worst case TC : O(n) hoti!}
void createMap(int inOrder[], int size, map<int, int>& valueToIndexMap){
    for(int i = 0; i < size; i++){
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

//Given : PreOrder & InOrder, make Tree
//Warning (Bhulega tu) : pass "int& preOrderIndex" by reference !!
Node* construct_tree_from_pre_and_inOrder_traversal(int preOrder[], int inOrder[], int& preOrderIndex, int inOrderStart, int inOrderEnd, int size,  map<int, int>& valueToIndexMap){
    //Base Case
    if(preOrderIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1 case i will solve 
    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    Node* root = new Node(element);

    //Search this element in inOrder traversal
    int position = valueToIndexMap[element]; //using map (TC : O(log N)) {could have used unordered_map for TC : O(1) but then worst case TC : O(n) hoti!}
    // int position = searchInOrder(inOrder, size, element); //using searchInOrder() function (TC : O(N))
    
    //Baki RE 
    //NOTE: Bcz PreOrder(NLR) given so pehle Left SubTree bnega then Right (So order of Call is important)
    root->left = construct_tree_from_pre_and_inOrder_traversal(preOrder, inOrder, preOrderIndex, inOrderStart, position-1, size, valueToIndexMap);

    root->right = construct_tree_from_pre_and_inOrder_traversal(preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, size, valueToIndexMap);

    return root;

}

//Given : PostOrder & InOrder, make Tree
//Warning (Bhulega tu) : pass "int& postOrderIndex" by reference !!
Node* construct_tree_from_post_and_inOrder_traversal(int postOrder[], int inOrder[], int& postOrderIndex, int inOrderStart, int inOrderEnd, int size,  map<int, int>& valueToIndexMap){
    //Base Case
    if(postOrderIndex < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1 case i will solve 
    int element = postOrder[postOrderIndex];
    postOrderIndex--;
    Node* root = new Node(element);

    //Search this element in inOrder traversal
    int position = valueToIndexMap[element]; //using map (TC : O(log N)) {could have used unordered_map for TC : O(1) but then worst case TC : O(n) hoti!}
    // int position = searchInOrder(inOrder, size, element); //using searchInOrder() function (TC : O(N))
    
    //Baki RE 
    //NOTE: Bcz PostOrder(LRN) given so pehle Right SubTree bnega then Left (So order of Call is important)
    root->right = construct_tree_from_post_and_inOrder_traversal(postOrder, inOrder, postOrderIndex, position + 1, inOrderEnd, size, valueToIndexMap);

    root->left = construct_tree_from_post_and_inOrder_traversal(postOrder, inOrder, postOrderIndex, inOrderStart, position-1, size, valueToIndexMap);


    return root;

}

int main(){
/*
The Tree for reference:
          2
        /   \
       8     4
      / \     \
    10   6     12
*/

    // //Given : PreOrder & InOrder
    int inOrder[] = {10,8,6,2,4,12};
    int preOrder[] = {2,8,10,6,4,12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size-1;
    map<int, int> valueToIndexMap;
    createMap(inOrder, size, valueToIndexMap);

    Node* root = construct_tree_from_pre_and_inOrder_traversal(preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size, valueToIndexMap);

    cout<<"Printing the created Tree : "<<endl;
    LevelOrderTraversalStage2(root);
    
    
    // //Given : PostOrder & InOrder
    // int inOrder[] = {10,8,6,2,4,12};
    // int postOrder[] = {10,6,8,12,4,2};
    // int size = 6;
    // int postOrderIndex = size-1;
    // int inOrderStart = 0;
    // int inOrderEnd = size-1;
    // map<int, int> valueToIndexMap;
    // createMap(inOrder, size, valueToIndexMap);

    // Node* root = construct_tree_from_post_and_inOrder_traversal(postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size, valueToIndexMap);

    // cout<<"Printing the created Tree : "<<endl;
    // LevelOrderTraversalStage2(root);

return 0;
}