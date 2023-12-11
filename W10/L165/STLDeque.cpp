#include<iostream>
#include<deque>
using namespace std;


int main(){
   //Creation
   deque<int> dq;

   dq.push_front(1);
   dq.push_front(2);
   dq.push_back(3);
   dq.push_back(4);

   cout<<"Size : "<<dq.size()<<endl;
   dq.pop_front();

   cout<<"Size : "<<dq.size()<<endl;
   dq.pop_back();
   cout<<"Size : "<<dq.size()<<endl;

    cout<<"Front : "<<dq.front()<<endl;
    cout<<"Front : "<<dq.back()<<endl;
return 0;
}