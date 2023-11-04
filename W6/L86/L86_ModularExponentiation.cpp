// Iterative C++ program to compute modular power 
#include <iostream>
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int a, int b, int p){
    int ans = 1;
    
    while(b>0){
        //if power is odd
        if(b&1){
            ans = (ans%p * a%p) %p;
        }
        a = (a%p * a%p);
        b = b>>1;
    }
    
    return ans%p;
} 

// Driver code 
int main() 
{ 
	int x = 2; 
	int y = 5; 
	int p = 13; 
	cout << "Ans : " << power(x, y, p); 
	return 0; 
} 
