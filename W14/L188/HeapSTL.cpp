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

    /*
        Note:
        1)std::priority_queue ka 3rd template parameter is expected to be a "functor (function object) type" so we used "greater<int>".
            See : https://en.cppreference.com/w/cpp/container/priority_queue
        
        2)std::sort() ka parameter is expected to be a "functor (function object)" itself {& not a type} so we can use "gretaer<int>()".
            See : https://en.cppreference.com/w/cpp/algorithm/sort

        3)Function object is an object of (usually template) class that has a single member function : the overloaded () operator.
          So "gretaer<int>()" is a function object while "gretaer<int>" is the type (of function object)
    */

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