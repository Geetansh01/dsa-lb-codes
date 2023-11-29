#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        //opening bracket
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            //Closing bracket
            if(!st.empty()){
                char topCh = st.top();
                if(ch == ')' && topCh == '('){
                    st.pop();
                }
                else if(ch == '}' && topCh == '{'){
                    st.pop();
                }
                else if(ch == ']' && topCh == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
   cout<<isValid("()[]{}");
return 0;
}