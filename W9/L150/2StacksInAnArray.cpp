#include<iostream>
using namespace std;

class Stack{
    private:
    int* arr;
    int top1;
    int top2;
    int size;

    public:
    Stack(int size){
        arr = new int[size]();
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2 - top1 == 1){
            cout<<"Stack OverFlow"<<endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data){
        if(top2 - top1 == 1){
            cout<<"Stack OverFlow"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1 == -1){
            cout<<"Stack1 UnderFlow"<<endl;
        }
        else{
            // arr[top1] = 0;
            top1--;
        }
    }

    void pop2(){
        if(top2 == size){
            cout<<"Stack2 UnderFlow"<<endl;
        }
        else{
            // arr[top2] = 0;
            top2++;
        }
    }

    // void print(){
    //     for(int i = 0; i < size; i++){
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<endl;
    // }
};

int main(){
   Stack st(10);
   
   st.push1(10);
   st.push1(20);
   st.push1(30);
   st.push1(40);
   st.push1(50);

   st.push2(1);
   st.push2(2);
   st.push2(3);
   st.push2(4);
   st.push2(5);

//    st.print();

   st.pop1();
   st.pop2();
//    st.print();

   
return 0;
}