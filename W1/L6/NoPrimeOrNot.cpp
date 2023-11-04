#include<iostream>
using namespace std;


int main(){
   int n = 0; //n is no. to be tested . Initializing it to 0
   cin>>n;
   for(int i = 2; i < n; i++ ){
        if(n%i == 0){
            cout<<"Not Prime"<<endl;
            return 0;
        }
   }

    cout<<"Prime Number"<<endl;
    return 0;
}
