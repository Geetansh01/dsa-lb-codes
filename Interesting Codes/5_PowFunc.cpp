#include<iostream>
#include<math.h>
using namespace std;

/*
Pow() is a troublesome function. It's defined as :
    double pow (double x, double y);

So, while it works fine with "double", it does NOT work with ints on all compilers

To be safe, never use or store it's result in an "int"
*/

int main(){
   int a = pow(10.0,2.0); //100
   cout<<a<<endl;

   int b = pow(10, 2); //99 🤣
   cout<<b<<endl;

   //To use pow() with "int":  add "0.1" to the return value of pow. (Why? (See "Working of pow() Function with Integers" heading in this gfg artcle) : https://www.geeksforgeeks.org/power-function-c-cpp/)
   int c = pow(10, 2) + 0.1; //100 
   cout<<c;

   
return 0;
}