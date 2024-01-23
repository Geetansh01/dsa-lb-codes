#include<iostream>
#include<stack>
using namespace std;


/*****V186_6 : Median of BST [GFG : https://www.geeksforgeeks.org/problems/median-of-bst/1]*******/

// Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


//M1 : Slow-fast pointers (Your Solution below ╰(*°▽°*)╯)
//TC: O(n) n is number of nodes of given BST
//SC: O(Height of the Tree)
//This is the exact TC/SC demanded by the GFG question :)

/*
    Main Logic:
    1)there are 2 pointers - "slow" & "fast", both will start doing the inorder traversal of given BST. "fast" will move 2 steps ahead at once following which "slow" will move 1 step ahead in the LNR (Inorder) Traversal.
    2)When "fast" finishes the BST's Inorder Traversal, "slow" would be at the middle, in this way we find the median
    3)Note that it matters whether the BST has EVEN or ODD no. of nodes, based on which slightly different formulas of median exist!
*/


float findMedian(struct Node *root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    
    Node* slow = root;
    Node* fast = root;
    
    int TotNodes = 0; 
    float a;
    
    //"slow" and "fast" dono ko starting of Inorder trav Pe Lao by performing one step of the traversal
    if(!s2.empty() || fast != NULL){
        while(fast != NULL){
            s2.push(fast);
            fast = fast->left;
        }
        
        //N
        Node* s2Top = s2.top();
        s2.pop();
        TotNodes++;

        //R
        fast = s2Top->right;
        
        //Slow
        //L
        while(slow != NULL){
            s1.push(slow);
            slow = slow->left;
        }

        //N
        Node* s1Top = s1.top();
        s1.pop();
        a = s1Top->data;
        
        //R
        slow = s1Top->right;
    }
    
    
    //"slow" and "fast" ko slowly and fastly move krao, performing Inorder trav as they go (For every 2 steps of "fast", "slow" moves by 1 step) 
    //"a" will always hold the mid value of wherever fast is!
    //So when fast completes the traversal, "a" will be at the perfect mid for ODD length
    //& for EVEN length it will be on left of virtual mid (eg: for 1,2,3,4 "a" will be at 2)
    while((!s2.empty() || fast != NULL)){
        //Inorder LNR traversal

        //Fast
        //L
        while(fast != NULL){
            s2.push(fast);
            fast = fast->left;
        }
        
        //N
        Node* s2Top = s2.top();
        s2.pop();
        TotNodes++;

        //R
        fast = s2Top->right;
        
        if(!s2.empty() || fast != NULL){
            //L
            while(fast != NULL){
                s2.push(fast);
                fast = fast->left;
            }
            
            //N
            Node* s2Top = s2.top();
            s2.pop();
            TotNodes++;
    
            //R
            fast = s2Top->right;
        }
        else{
            break;
        }

        //Slow
        //L
        while(slow != NULL){
            s1.push(slow);
            slow = slow->left;
        }

        //N
        Node* s1Top = s1.top();
        s1.pop();
        a = s1Top->data;

        //R
        slow = s1Top->right;
    }
    
    //If EVEN length, we need the number next to "a" as well, let that be "b"
    //so to get "b" we will perform "slow" ka inorder trav 1 step more
    if(TotNodes%2 == 0){
        float b;
        if(!s1.empty() || slow != NULL){
            //L
            while(slow != NULL){
                s1.push(slow);
                slow = slow->left;
            }
    
            //N
            Node* s1Top = s1.top();
            s1.pop();
            b = s1Top->data;
            
            //R
            slow = s1Top->right;
        }
        
        return (a + b)/2.0;
    }
    
    //If ODD length, "a" directly has the answer! 
    else{
        return a;
    }
}


//M2 : Using Morris Traversal (TC: O(n); SC: O(1))
// int getNumberOfNodes(Node* root) {
//     //Using Morris Traversal in LNR fashion to count total Nodes
//     int NodeCount = 0;
//     Node* current = root;
    
//     while(current != NULL){
//         //If current's left child is null then store the current Node and go right (acc. to LRN)
//         if(current->left == NULL){
//             NodeCount++;
//             current = current->right;
//         }
//         else{
//         //If current Node has a non-null left child
        
//             //Find current's predecessor and make a link
//             Node* pred = current->left;
//             while(pred->right != current && pred->right != NULL){
//                 pred = pred->right;
//             }

//             //If predecessor's right pointer is null, use it to link to current
//             if(pred->right == NULL){
//                 pred->right = current;
//                 current = current->left;
//             }
//             else{
//                 //If predecessor's right pointer is not null that means it was already linked before, delink it
//                 pred->right = NULL;
//                 NodeCount++;
//                 current = current->right;
//             }

//         }

//     }

//     return NodeCount;
// }

// float getMedian(Node* root) {
//     //Using Morris Traversal in LNR fashion to go to desired Position
    
//     int n = getNumberOfNodes(root);
//     int i = 0;
//     int oddMedianPos = (n+1)/2; float oddMedianVal = 0;
//     int evenMedianTerm1Pos = n/2; float evenMedianTerm1Val = 0;
//     int evenMedianTerm2Pos = (n/2) + 1; float evenMedianTerm2Val = 0;
//     Node* current = root;
    
//     while(current != NULL){
//         //If current's left child is null then store the current Node and go right (acc. to LRN)
//         if(current->left == NULL){
//             i++;
//             if(i == oddMedianPos){
//                 oddMedianVal = current->data;
//             }
//             if(i == evenMedianTerm1Pos){
//                 evenMedianTerm1Val = current->data;
//             }
//             if(i == evenMedianTerm2Pos){
//                 evenMedianTerm2Val = current->data;
//             }
//             current = current->right;
//         }
//         else{
//         //If current Node has a non-null left child
        
//             //Find current's predecessor and make a link
//             Node* pred = current->left;
//             while(pred->right != current && pred->right != NULL){
//                 pred = pred->right;
//             }

//             //If predecessor's right pointer is null, use it to link to current
//             if(pred->right == NULL){
//                 pred->right = current;
//                 current = current->left;
//             }
//             else{
//                 //If predecessor's right pointer is not null that means it was already linked before, delink it
//                 pred->right = NULL;
//                 i++;
//                 if(i == oddMedianPos){
//                     oddMedianVal = current->data;
//                 }
//                 if(i == evenMedianTerm1Pos){
//                     evenMedianTerm1Val = current->data;
//                 }
//                 if(i == evenMedianTerm2Pos){
//                     evenMedianTerm2Val = current->data;
//                 }
//                 current = current->right;
//             }

//         }

//     }
    
    
//     //WARNING (Glti krega tu) : brackets in "(n&1) == 0" are important otherwise "==" phle evaluate hoga!!
//     if((n&1) == 0){
//         //Even No. of Nodes
//         return ((evenMedianTerm1Val + evenMedianTerm2Val)/2.0);
//     }
//     else{
//         //ODD No. of Nodes
//         return oddMedianVal;
//     }
// }

// float findMedian(struct Node *root)
// {
//     return getMedian(root);
// }

int main(){
   
return 0;
}