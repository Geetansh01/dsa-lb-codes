#include<iostream>
#include<stack>
using namespace std;


int main(){
    string name = "Geetansh Bhardwaj";


    stack<char> st;
    for(int i = 0; i < name.size(); i++){
        st.push(name[i]);
    }

    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    
return 0;
}