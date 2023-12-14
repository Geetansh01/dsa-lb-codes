#include<iostream>
#include<stack>
using namespace std;

/******Implement Queue using Stacks [Interview] [LeetCode : https://leetcode.com/problems/implement-queue-using-stacks/description/]*******/

//M2

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int poped = -1;
        if(!s2.empty()){
            poped = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            poped = s2.top();
        }
        s2.pop();
        return poped;
    }
    
    int peek() {
        int front = -1;
        if(!s2.empty()){
            front = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main(){
   
return 0;
}