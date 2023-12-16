#include<iostream>
using namespace std;

/*****K Queues in an Array *****/

class KQueue{
    public:
    int n, k, freespot;
    int* arr, *front, *rear, *next;

    KQueue(int _n, int _k):n(_n), k(_k), freespot(0){
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i = 0; i < n; i++){
            next[i] = (i + 1);
        }
        next[n-1] = -1;
    }

    //push x into qith Queue
    bool push(int x, int qi){
        //S1 :  Check overflow
        if(freespot == -1){
            return false;
        }

        //S2: Find first index
        int index = freespot;

        //S3: update freespot
        freespot = next[index];

        //S4
        if(front[qi] == -1){
            //If x is the 1st element of qi
            front[qi] = index;
        }
        else{
            //If qi already has elements
            //then link new element to qi's rearest element
            next[rear[qi]] = index;
        }

        //S5: update next
        next[index] = -1;

        //S6,7: update rear and push x into qi
        rear[qi] = index;
        arr[index] = x;

        return true;
    }

    //pop element from qith Queue
    int pop(int qi){
        //S1: Check underflow
        if(front[qi] == -1){
            return -1;
        }

        //S2: find index to pop
        int index = front[qi];

        //S3: update front
        front[qi] = next[index];

        //S4: update next
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    ~KQueue(){
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main(){
    KQueue kq(8, 3);
    cout<<kq.push(11,0)<<endl;
    cout<<kq.push(12,0)<<endl;
    cout<<kq.push(100,1)<<endl;
    cout<<kq.push(13,0)<<endl;

    cout<<kq.pop(1)<<endl;
    cout<<kq.pop(1)<<endl;
    
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;



    return 0;
}