#include<iostream>
#include<queue>
using namespace std;


int main(){
    /***Max heap*****/
    // //By default it's max heap
    // //create Max-heap
    // priority_queue<int> pq;

    // //Insertion
    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);
    // pq.push(50);

    // cout<<"Top of max-heap : "<<pq.top()<<endl;

    // pq.pop(); //50 popped, now 40 on top

    // cout<<"Top of max-heap : "<<pq.top()<<endl;

    // cout<<"Size of max-heap : "<<pq.size()<<endl;
    // if(pq.empty()){
    //     cout<<"Empty"<<endl;
    // }
    // else{
    //     cout<<"Not Empty"<<endl;
    // }


    /***Min heap*****/
    //creating min-heap
    priority_queue<int, vector<int>, greater<int> >pq;

    //insertion
    pq.push(100);
    pq.push(90);
    pq.push(70);

    cout<<"Top of min-heap : "<<pq.top()<<endl;

    pq.pop(); //70 popped, now 90 on top

    cout<<"Top of min-heap : "<<pq.top()<<endl;

    cout<<"Size of min-heap : "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }

return 0;
}