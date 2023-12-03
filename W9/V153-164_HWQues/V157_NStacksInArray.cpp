#include<iostream>
using namespace std;

class NStack{
    int *a, *top, *next;
    int n; //No of Stacks
    int size; //Size of main array
    int freespot;

    public:
    NStack(int _n, int _s) : n(_n), size(_s){
        freespot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i = 0; i < n; i++){
            top[i] = -1;
        }

        for(int i = 0; i < size; i++){
            if(i != size-1){
                next[i] = i + 1;
            } 
            else{
                next[i] = -1;
            }
        }
    }

    ~NStack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }

    //INsert x in mth Stack
    bool push(int x, int m){
        if(freespot == -1){
            return false; //Stack Overflow
        }

        //Step 1
        int index = freespot;

        //Step 2
        freespot = next[index];

        //Step 3
        a[index] = x;

        //Step 4
        next[index] = top[m-1];

        //Step 5
        top[m-1] = index;

        return true; //Push Successful
    }

    //pop from mth Stack
    int pop(int m){
        if(top[m-1] == -1){
            return -1; //Stack Underflow
        }

        int index = top[m-1];
        top[m-1] = next[index];
        int popped_element = a[index];
        next[index] = freespot;
        freespot = index;
        return popped_element;
    }


};

int main(){
   NStack st(3,6);
   cout<<st.push(100, 1)<<endl;
   cout<<st.push(200, 1)<<endl;
   cout<<st.push(300, 1)<<endl;
   cout<<st.push(11, 2)<<endl;
   cout<<st.push(12, 2)<<endl;
   cout<<st.pop(1)<<endl;
   cout<<st.pop(2)<<endl;
   cout<<st.pop(2)<<endl;
   cout<<st.pop(1)<<endl;
   cout<<st.pop(1)<<endl;
   cout<<st.pop(1)<<endl;

return 0;
}