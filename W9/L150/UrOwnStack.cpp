#include<iostream>
using namespace std;

class Stack{
    private:
    int* arr;
    int top;
    int size;

    public:
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data){
        if(size - top > 1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"Stack UnderFlow"<<endl;
        }
        else{
            top--;
        }
    }

    int getTop(){
        if(top == -1){
            cout<<"No Element in stack"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
   Stack st(4);
   st.push(10);
   st.push(20);
   st.push(30);
   st.push(40);
   st.push(40);

   while(!st.isEmpty()){
    cout<<st.getTop()<<" ";
    st.pop();
   }
   cout<<endl;

   cout<<"No of Elements in Stack : "<<st.getSize()<<endl;
   
return 0;
}