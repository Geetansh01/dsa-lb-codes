#include<iostream>
#include<limits.h>
using namespace std;

//Ques : Given a CBT, verify if it's a valid Max-Heap
//No online Judge to submit, yhi likh diya 1

class Info{
    public:
    int maxVal;
    bool isHeap;

    Info(int val, bool flag){
        this->maxVal = val;
        this->isHeap = flag;
    }
};

//Dummy Node Class so code compiles!
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Info chkMaxHeap(Node* root){
    //BC
    if(root == NULL){
        Info temp(INT_MIN, true);
        return temp;
    }
    if(root->left == NULL && root->right == NULL){
        Info temp(root->data, true);
        return temp;
    }

    Info leftAns = chkMaxHeap(root->left);
    Info rightAns = chkMaxHeap(root->right);

    //1 Case Hm baki RE
    int curr = root->data;
    if(leftAns.isHeap && rightAns.isHeap && curr > leftAns.maxVal && curr > rightAns.maxVal){
        Info ans(curr, true);
    }
    else{
        int maxi = max(curr, max(leftAns.maxVal, rightAns.maxVal));
        Info ans(maxi, false);
        return ans;
    }

}

int main(){
   
return 0;
}