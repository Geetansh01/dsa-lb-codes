#include<iostream>
using namespace std;

void printDigits(int n){
    //Base Case
    if(n == 0){
        return;
    }

    //Baki recursion sambhal lega
    int newValueOfN = n/10;
    printDigits(newValueOfN);

    //1 case i will solve
    int digit = n%10;
    cout<<digit;

}

int main(){
   int n = 123400;

   //Handling n = 0
   if(n == 0){
    cout<<0;
   }
   
   printDigits(n);
return 0;
}