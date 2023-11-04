#include<iostream>
#include<string>
using namespace std;

void reverse(string& str, int& s, int& e){
    //Base Case
    if (s >= e){
        return;
    }

    //1 case solve kro
    swap(str[s], str[e]);
    s++; e--;
    reverse(str, s, e);
}

int main(){
   string name = "Geetansh";
   int s = 0;
   int e = name.length() - 1;

   reverse(name, s, e);
   cout<<"Name :"<<name<<endl;
return 0;
}