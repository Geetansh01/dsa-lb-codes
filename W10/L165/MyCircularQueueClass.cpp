#include<iostream>
using namespace std;

class CirQueue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        CirQueue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int data){
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

        void pop(){
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



};

int main(){
   
return 0;
}