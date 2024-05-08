#include<bits/stdc++.h>
using namespace std;

void solveRE(string& s, unordered_set<string>& ans, int invalidOpen, int invalidClosed, int balance, int index, string& output){
    //base case
    if(index >= s.length()){
        //chk if expression is valid
        if(invalidOpen == 0 && invalidClosed == 0 && balance == 0){
            ans.insert(output);
        }
        return;
    }

    //Ab include/ exclude kro
    char ch = s[index];
    if(ch >= 'a' && ch <= 'z'){
        //alphabet ko to include krna hi hai
        output.push_back(ch);
        solveRE(s, ans, invalidOpen, invalidClosed, balance, index + 1, output);
        output.pop_back(); //BackTracking
    }
    else{
        //when char is a bracket => '(' or ')'
        if(ch == '('){
            //Exclude
            if(invalidOpen > 0){
                solveRE(s, ans, invalidOpen-1, invalidClosed, balance, index + 1, output);
            }

            //Include
            output.push_back('(');
            solveRE(s, ans, invalidOpen, invalidClosed, balance + 1, index + 1, output);
            output.pop_back();
        }
        else{
            //when ch is ')'
            //Exclude
            if(invalidClosed > 0){
                solveRE(s, ans, invalidOpen, invalidClosed - 1, balance, index + 1, output);
            }

            //Include
            //WARNING : Below is an optimistaion jo tu bhulega
            //Mai ek ')' pe khada hu. 
            //Is ')' ko Include tabhi krne ki sense bnti hai jb iske liye koi '(' pehle pda ho. 
            //Agr pehle koi '(' pda hai to "balance" > 0 hoga
            if(balance > 0){
                output.push_back(')');
                solveRE(s, ans, invalidOpen, invalidClosed, balance - 1, index + 1, output);
                output.pop_back(); //BackTrack
            }
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> ans;
    int invalidOpen = 0;
    int invalidClosed = 0;
    int balance = 0;

    for(auto ch : s){
        if(ch == '('){
            invalidOpen++;
        }
        else if(ch == ')'){
            if(invalidOpen > 0){
                invalidOpen--;
            }
            else{
                invalidClosed++;
            }
        }
    }

    int index = 0;
    string output = "";
    solveRE(s, ans, invalidOpen, invalidClosed, balance, index, output);
    return vector<string> (ans.begin(), ans.end());
}

int main(){
   
return 0;
}