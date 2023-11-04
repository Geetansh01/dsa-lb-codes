#include<iostream>
using namespace std;

//Guess the outputs [Error is also a possible answer]

int main(){
    // //Ques
    // char ch = 'a';
    // char* ptr = &ch;
    // (*ptr)++;
    // cout<<*ptr<<endl;

    // //Ques
    // int a[] = {1,2,3,4};
    // int* ptr = a++;
    // cout<<*ptr<<endl;

    // //Ques
    // char st[] = "ABCD";
    // for(int i = 0; st[i] != '\0'; i++){
    //     cout<< st[i] << *(st)+i << *(i + st) << i[st];
    // }


    //Ques
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float* ptr1 = &arr[0];
    float* ptr2 = ptr1 + 3;

    cout<<*ptr2<<endl;
    cout<< ptr2 - ptr1 <<endl;

    int A = ptr2 - ptr1;
    cout<<"A : "<<A<<endl;

    //What if the below lines are uncommented?
    // int B = ptr2 + ptr1;
    // cout<<"B : "<<B<<endl;



    return 0;
}