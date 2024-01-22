#include<iostream>
#include<stack>
using namespace std;


/*****V186_6 : Median of BST [GFG : https://www.geeksforgeeks.org/problems/median-of-bst/1]*******/

//Your Solution below ╰(*°▽°*)╯
//TC: O(n) n is number of nodes of given BST
//SC: O(Height of the Tree)
//This is the exact TC/SC demanded by the GFG question :)

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

int main(){
   
return 0;
}