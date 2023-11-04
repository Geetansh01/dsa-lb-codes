#include<iostream>
#include<cmath>
#include<vector> //For Q 41
using namespace std;

//Q 36 : Factorial of a number (Can only be used to find factorial upto 12, above that it is out of the range of " int ")
int fact(int n);

//Q 37 : Chk if given no prime or not
int primechk(int x);

//Q 38 : Print All Prime From 1 to N
int printprime(int n);

//Q 39 : Reverse Integer [LeetCode : https://leetcode.com/problems/reverse-integer/]
int reverse(int n);

//Q : Decimal To Binary Print
int DecimalToBinaryMethd1(int n);  //Division Method
int DecimalToBinaryMethd2(int n);  //Bitwise Method

//Q : Binary to Decimal
int BinaryToDecimal(int n);

//Q 40 : Set The Kth Bit [GFG : https://practice.geeksforgeeks.org/problems/set-kth-bit3724/1]
// Method 1 : Masking
int setKthBit1(int N, int K)
{   
   int mask = 1<<K;
   return N | mask;
}

//Method 2 : My Code
int setKthBit2(int N, int K)
{
    int bit = 0;
    int i = 0;
    int ans = 0;
    while( N != 0 ){
        if( i == K ){
            bit = 1;
            N = N>>1;
        }
        else{
            bit = N & 1;
            N = N>>1;
        }
        
        //Power of 2
        int two = 1;
        for(int count = 0; count < i; count++){
            two = two * 2;
        }

        ans = ans + bit*two;
        i++;
    }
    
    return ans;
}


//Q 41 : Convert the Temperature [LeetCode : https://leetcode.com/problems/convert-the-temperature/submissions/]
//Revise Vectors from STL for this
vector<double> convertTemperature(double celsius) {
    double Kelvin =  celsius + 273.15;
    double Fahrenheit = celsius * 1.80 + 32.00;
    vector<double> vec;
    vec.push_back(Kelvin);
    vec.push_back(Fahrenheit);

    return vec;
}



int main(){
   // int a = fact(12);
   // cout<<a;

   // primechk(7);

   // printprime(100);

   // cout<<reverse(-2147483641);

   // cout<<DecimalToBinaryMethd1(16); 
   //If you are getting wrong answer that's beacause pow() has been used in " DecimalToBinaryMethd1() ".
   //Soln : Un-comment the Alter Method in " DecimalToBinaryMethd1() " and comment the pow() part. 

   // cout<<DecimalToBinaryMethd2(16);

   // cout<<BinaryToDecimal(11); //If getting wrong answer, remove  pow() and write code that does the work of pow() from " BinaryToDecimal() "

   // cout<<setKthBit1(10,2);
   // cout<<endl;
   // cout<<setKthBit2(10,2);

   // cout<<"100 celsius in Kelvin : "<<convertTemperature(100.00)[0]<<endl;
   // cout<<"100 celsius in Fahrenheit : "<<convertTemperature(100.00)[1]<<endl;

return 0;
}


int fact(int n){
   int fact = 1;
   for(int i = n; i > 0; i--){
      fact = fact * i;
   }

   return fact;
}


int primechk(int x){
   int i = 2;
   for(; i < x; i++){
      if(x%i == 0){
         cout<<"Not Prime"<<endl;
         return 0;
      }
   }

   cout<<"Prime"<<endl;
   return 0;
}


int printprime(int n){
   int cnum = 2; //current number being chked for prime
   for(; cnum <= n; cnum++){
      int i = 2;
      for(; i < cnum; i++){
         if(cnum%i == 0){
            break;
         }
         else{
            //else continue the current loop
         }
      }

      if(i == cnum){
         cout<<cnum<<" : Prime"<<endl;
      }
   }
   return 0;
}


int reverse(int n) {
   int ans = 0;
   int rem = n;
   while(n != 0){
      if(n > 0){
            if(ans > INT32_MAX/10){
               return 0;
            }
      }
      else if(ans < -(INT32_MAX/10)){
               return 0;
            }

      rem = n%10;
      n = n/10;
      ans = ans*10 + rem;
   }
   return ans;

}


int DecimalToBinaryMethd1(int n){
   int quotient = n, remainder = 0;
   int s = 0; int ans = 0; //ans represebt the final binary number formed for printing
   int m = 0; //will be used as exponent of 10

   while(quotient != 0){
      remainder = quotient % 2;
      quotient = quotient / 2;

      //making correct power of ten
      // int ten = pow(10, m++);

      // Alter Method (I wrote it because pow() is a troublesome function. Why? See " InterestingCodes.cpp ")
      int ten = 1;
      for(int i = 0; i < s; i++){
         ten = ten * 10;
      }
      s++;

      ans = ans + remainder*ten;

   }

   return ans;
}


int DecimalToBinaryMethd2(int n){
   int bit = 0, ans = 0;
   int s = 0;
   int m = 0; //will be used as exponent of 10

   while( n != 0){
      bit = n & 1; //bitwise & operator to extract last bit
      n = n>>1; //right shifting n 1 time

      //making correct power of ten
      // int ten = pow(10, m++);

      // Alter Method (I wrote it because pow() is a troublesome function. Why? See " InterestingCodes.cpp ")
      int ten = 1;
      for(int i = 0; i < s; i++){
         ten = ten * 10;
      }
      s++;

      ans = ans + bit * ten;
   }
   return ans;
}


int BinaryToDecimal(int n){
   int lastdigit = 0;
   int ans = 0;
   int exponent = 0;

   while( n != 0){
      lastdigit = n%10;
      n = n/10;
      ans = ans + lastdigit * pow(2, exponent++);
   }
   return ans;
}


