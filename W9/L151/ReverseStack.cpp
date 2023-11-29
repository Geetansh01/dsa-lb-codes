#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target){
    //base Case
    if(s.empty()){
        s.push(target);
        return;
    }

    int topEle = s.top();
    s.pop();

    //RE Call
    insertAtBottom(s, target);

    //Kind of BackTrack
    s.push(topEle);
}

void reverseStack(stack<int>& s){
    //base case
    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();
    
    //Reverse Stack
    reverseStack(s);

    //Insert at bottom target
    insertAtBottom(s, target);
}

int main(){
   stack<int> s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);

   reverseStack(s);

   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
   }
return 0;
}