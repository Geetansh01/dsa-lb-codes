#include<iostream>
using namespace std;

/*******************Euclid's Algorithm for GCD of two Numbers [GFG : https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1]******************************/

//M1 : Non recursive approach
int gcd(int A, int B) 
{ 
    if (A == 0) return B;
    if (B == 0) return A;
    
    while(A>0 && B>0){
        if(B >= A) {
            B = B - A;
        }
        else{
            A = A - B;
        }
    }
    
    return (A == 0) ? B : A;

} 

//M2 : Recursion
// int gcd(int A, int B) 
// { 
//     if (A == 0){
//         return B;
//     }
//     else if (B == 0){
//         return A;
//     }
    
//     else{
//         if(B >= A) {
//                 B = B - A;
//         }
//         else{
//             A = A - B;
//         }
//     }
    
//     return gcd(A , B);
// } 

int main(){
   cout<<gcd(3,6);
return 0;
}