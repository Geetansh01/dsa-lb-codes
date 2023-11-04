#include<iostream>
using namespace std;

//std::strings are compared lexicographically if you use Relational Operators (<, >, <=, >=)

int main(){
   cout<<("30" <= "30")<<endl;
   cout<<("1" < "2")<<endl;
   cout<<("13" < "23")<<endl;
   cout<<("30" < "3")<<endl;

   //Output for all cases will be 1
return 0;
}