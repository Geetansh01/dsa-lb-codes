#include<iostream>
using namespace std;

//Reverse Counting
void revCounting(int n){
    //Base Case
    if(n == 0){
        return;
    }

    cout<<n<<" ";

    revCounting(n-1);
}

//Sidhi Counting
void sidhiCounting(int n){
    //Base Case
    if(n == 0){
        return;
    }

    sidhiCounting(n-1);

    cout<<n<<" ";
}

//fibonacci
int fib(int n){
    if(n == 0){
        //Oth term
        return 0;
    }
    if(n == 1){
        //1st term
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(){
   revCounting(5);

   cout<<endl;
   
   sidhiCounting(5);

   cout<<endl;
   
   cout<<fib(7);    //7th term
return 0;
}