#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>& s, int target){
    //base case
    if(s.empty()){
        s.push(target);
        return;
    }
    else if(s.top() >= target){
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    //RE Call
    insertSorted(s, target);

    //BackTrack
    s.push(topElement);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();

    //RE Call to Sort
    sortStack(s);

    //Insert topElement in sorted way
    insertSorted(s, topElement);
}

int main(){
    stack<int> s;
    s.push(9);
    s.push(5);
    s.push(3);
    s.push(11);
    s.push(7);

    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }   
return 0;
}