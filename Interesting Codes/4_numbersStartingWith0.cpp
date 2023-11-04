#include<iostream>
using namespace std;


int main(){
   int n = 0127;   //or  other numbers like 00012;
   cout<<n<<endl; 
   //output will be 87!!!

   /*
   Explanation (bing AI) : 
        The code you've written is in C++, and it assigns an octal value to the integer `n`. In C++, any number starting with `0` is considered an octal number (base 8).
        In this case, `0127` is an octal number.
        So, when you run this code, it will print `87`, which is the decimal equivalent of the octal number `0127`. If you want to print the number as it is (i.e., `0127`), 
        you should remove the leading zero.
        😊
   */

return 0;
}