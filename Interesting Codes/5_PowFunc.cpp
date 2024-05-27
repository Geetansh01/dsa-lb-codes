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
   cout<<b;
   
return 0;
}