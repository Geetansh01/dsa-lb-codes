#include<iostream>
#include<queue>
using namespace std;

void interleaveQ(queue<int>& q){
    //Step1 : Separate both halfs
    int n = q.size();
    if(q.empty()){
        return;
    }
    int k = n/2;
    int count = 0;

    queue<int> q2;

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        q2.push(ele);
        count++;

        if(count == k){
            break;
        }
    }

    //Step 2 : Push back from q2 (InterLeaving)
    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }

    //If q is ODD lengthed
    if(n & 1){
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}

int main(){
   queue<int> q;
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);
   q.push(5);
   q.push(6);
   q.push(7);
   q.push(8);
   q.push(9);

   interleaveQ(q);

   while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
   }
return 0;
}