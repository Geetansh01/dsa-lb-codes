#include<iostream>
using namespace std;

class Deque{
    public:
    int * arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size](); //Initializing with 0's 
        front = -1;
        rear = -1;
    }

    void pushRear(int data){
        //Q full
        //Single Element
        //Cir Nature
        //Normal Nature of Queue

        if((front == 0 && rear == size -1) || (front == rear + 1)){
            cout<<"Q is Full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data){
        //Q full
        //Single Element
        //Cir Nature
        //Normal Nature of Queue

        if((front == 0 && rear == size -1) || (front == rear + 1)){
            cout<<"Q is Full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(front == 0 && rear != size-1 ){
            front = size - 1;
            arr[front] = data;
        }
        else{
            front--;
            arr[front] = data;
        }
    }

    void popFront(){
            //Q empty
            //Single Element
            //Cir Nature
            //Normal Nature of Queue

            if(front == -1){
                cout<<"Q Empty"<<endl;
            }
            else if(front == rear){
                front = -1;
                rear = -1;
            }
            else if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
    }

    void popRear(){
            //Q empty
            //Single Element
            //Cir Nature
            //Normal Nature of Queue

            if(front == -1){
                cout<<"Q Empty"<<endl;
            }
            else if(front == rear){
                front = -1;
                rear = -1;
            }
            else if(rear == 0){
                rear = size - 1;
            }
            else{
                rear--;
            }
    }
};

int main(){
   Deque dq(10);

   dq.pushRear(10);
   dq.pushRear(20);
   dq.pushRear(30);
   dq.pushRear(40);
   dq.pushRear(50);
   dq.pushRear(60);



return 0;
}