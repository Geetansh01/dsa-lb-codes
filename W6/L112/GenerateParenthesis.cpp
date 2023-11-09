#include<iostream>
#include<vector>
using namespace std;

/************************Generate Parentheses [LeetCode : https://leetcode.com/problems/generate-parentheses/description/ ]*********************/

//Note : This question is NOT pick/don't pick method (LB made this error in the beginning of lec).
void solveHelper(string output, int open, int close, vector<string> &ans){
    //Base Case
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }

    //Call for '('
        if(open > 0){
            output.push_back('(');
            solveHelper(output, open-1, close, ans);
            //backtrack
            output.pop_back();
        }

    //Call for ')'
        if(close > open){
            output.push_back(')');
            solveHelper(output, open, close-1, ans);
            //backtrack
            output.pop_back();
        }
}

vector<string> generateParenthesis(int n) {
    int open = n;
    int close = n;
    vector<string> ans;
    string output;
    solveHelper(output, open, close, ans);
    return ans;
}

int main(){
    int n = 2;
    vector<string> ans = generateParenthesis(n);
    for(auto iter : ans){
        cout<<iter<<endl;
    }
   
return 0;
}