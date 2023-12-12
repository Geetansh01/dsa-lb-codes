#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueueWithStack(queue<int> &q){
    stack<int> stk;

    while(!q.empty()){
        int element = q.front();
        q.pop();

        stk.push(element);
    }

    while(!stk.empty()){
        int element = stk.top();
        stk.pop();

        q.push(element);
    }
    return;
}

//Using recursion
void reverseQueueWithRE(queue<int> &q){
    //Base Case
    if(q.empty()){
        return;
    }

    int element = q.front();
    q.pop();
    reverseQueueWithRE(q);
    q.push(element);
    return;
}

int main(){
   queue<int> q;
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);

    // reverseQueueWithStack(q);
    reverseQueueWithRE(q);

   while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
   }
    
    return 0;
}