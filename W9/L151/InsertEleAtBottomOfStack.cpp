#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int target){
    //base Case
    if(s.empty()){
        s.push(target);
        return;
    }

    int topEle = s.top();
    s.pop();

    //RE Call
    solve(s, target);

    //Kind of BackTrack
    s.push(topEle);
}

void insertAtBottom(stack<int>& s){
    if(s.empty()){
        cout<<"Stack Empty"<<endl;
        return;
    }

    int target = s.top();
    s.pop();
    solve(s, target);


}

int main(){
   stack<int> s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);
   s.push(100);

   insertAtBottom(s);

   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
   }
return 0;
}