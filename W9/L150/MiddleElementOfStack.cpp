#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>& st, int &totalSize){
    //base Case
    if(st.size() == 0){
        cout<<"Empty Stack"<<endl;
        return;
    }
    if(st.size() == totalSize/2 + 1){
        cout<<"Middle Element : "<<st.top()<<endl;
        return;
    }

    int temp = st.top();
    st.pop();

    //RE Call
    printMiddle(st, totalSize);

    //BackTrack
    st.push(temp);

    return;
}

int main(){
   stack<int> st;

   st.push(10);
   st.push(20);
   st.push(30);
   st.push(40);
   st.push(50);
   st.push(60);
   st.push(70);

   int totalSize = st.size();

   printMiddle(st, totalSize);
return 0;
}