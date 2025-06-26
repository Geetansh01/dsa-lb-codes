#include<iostream>
using namespace std;

//std::strings are compared lexicographically if you use Relational Operators (<, >, <=, >=)

int main(){
   cout<<(string("30") <= string("30"))<<endl;  // 1 (i.e true)
   cout<<(string("1") < string("2"))<<endl;     // 1 (i.e true)
   cout<<(string("13") < string("23"))<<endl;   // 1 (i.e true)
   cout<<(string("30") < string("3"))<<endl;    // 0 (i.e false)
   
   /*
   Note: 
   (i) Directly writing "30" will lead to unexpected behaviour as this is not a C++ String, it's C-style string {array of characters}
   (ii) So, writing "30" < "3", you are comparing character pointers (i.e memory addresses), the result could be 0 or 1 (i.e Unpredictable)
   */
  //For Ex: 
  
    cout<<(string("30") < string("3"))<<endl;    // 0 (Correct and expected according to lexicographic comparison ✅ )
    cout<<("30"<"3")<<endl; // may give 0 or 1 (Compiler dependent, wrong coding practice ❌)

return 0;
}