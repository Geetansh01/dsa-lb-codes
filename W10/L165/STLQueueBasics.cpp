#include<iostream>
#include<queue>
using namespace std;


int main(){
   //creation 
   queue<int> q;

   q.push(1);
   q.push(1);
   q.push(1);
   q.push(1);
   q.push(1);

   cout<<q.size()<<endl;

   q.pop();

   cout<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue Empty"<<endl;
    }
    else{
        cout<<"Queue Not Empty"<<endl;
    }

    cout<<q.front()<<endl;






return 0;
}