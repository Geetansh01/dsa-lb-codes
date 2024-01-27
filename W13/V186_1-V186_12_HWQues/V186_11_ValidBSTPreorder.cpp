#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/*******V186_11 : Valid BST from Preorder [InterviewBit : https://www.interviewbit.com/problems/valid-bst-from-preorder/]*********/

//TC : O(N)

void buildRE(int& i, int min, int max, vector<int> &A){
    //BC
    if(i >= A.size()) return;
    
    if(A[i] > min && A[i] < max){
        //Make New Node - but not really
        int rootData = A[i];
        i++;
        
        //Left 
        buildRE(i, min, rootData, A);
        
        //Right
        buildRE(i, rootData, max, A);
    }
    
    return;
}

int solve(vector<int> &A) {
    int min = INT_MIN; int max = INT_MAX;
    int i = 0;
    buildRE(i, min, max, A);
    
    //If i reaches out of bound, means preorder trav was valid
    return (i >= A.size()) ? 1 : 0;
}

int main(){
   
return 0;
}