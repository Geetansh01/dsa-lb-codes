#include<iostream>
#include<stack>
using namespace std;

/**********Q154 : Minimum Bracket Reversal [GFG : https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1]************/

int countRev (string s){
    //if strinig is odd lengthed, it's impossible to balance brackets
    if(s.length() & 1) return -1;

    int count = 0;
    stack<char> stk;
    for(auto ch : s){
        if(ch == '{'){
            stk.push(ch);
        }
        else{
            if(!stk.empty() && stk.top() == '{'){
                stk.pop();
            }
            else{
                stk.push(ch);
            }
        }
    }

    //Now if the stack is not empty then count reversals
    while(!stk.empty()){
        char a = stk.top();
        stk.pop();
        char b  = stk.top();
        stk.pop();
        if(a == b){
            count++;
        }
        else{
            count += 2;
        }
    }
    return count;
}

int main(){
    string s = "((((";
   cout<<countRev(s);
return 0;
}