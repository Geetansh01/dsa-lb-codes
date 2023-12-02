#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/********Q156 : Celebrity Problem [Interview][GFG : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1]***********/

//TC: O(N) 
//Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> >& M, int n) {
    stack<int> stk;
    for(int people = 0; people < n; people++){
        stk.push(people);
    }
    
    //Now Discard the people who are not a celebrity for sure
    while(stk.size() != 1){
        int personA = stk.top(); 
        stk.pop();
        int personB = stk.top(); 
        stk.pop();
        
        if(M[personA][personB] == 1){
            //personA knows personB, so A is not a celebrity for sure, B might be
            stk.push(personB);
        }
        else{
            //A does not know B but everyone knows a celebrrity, so B is not a celebrity for sure, A might be
            stk.push(personA);
        }
    }
    int possibleCelebrity = stk.top();
    
    
    //Now verify if the possible celebrity is a celebrity or not
    //Check 1 : A celebrity knows no one else
    for(int i = 0; i < n; i++){
        if(M[possibleCelebrity][i] == 1){
            return -1;
        }
    }
    
    //Check 2 : Everyone knows a celebrity
    for(int i = 0; i < n; i++){
        if(i == possibleCelebrity) continue; //Ignoring the diagonal position of M
        if(M[i][possibleCelebrity] == 0){
            return -1;
        }
    }
    
    
    //If both checks passed then we got a celebrity
    return possibleCelebrity;
    
}

int main(){
   vector<vector<int> > M = {{0, 1, 0},
                            {0, 0, 0}, 
                            {0, 1, 0}};
    cout<<celebrity(M, 3);

return 0;
}