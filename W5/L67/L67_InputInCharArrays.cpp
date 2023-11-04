#include<iostream>
using namespace std;


int main(){

   /*************************Method 1 How to input in character arrays : One character at a time********************************************/
   // char name[100];
   // cin>>name[0];
   // cin>>name[1];
   // cout<<"name :"<<name<<endl;

   /*************************Method 2 How to input in character arrays : cin********************************************/
   // char fname[100];
   // char lname[100];
   // (cin>>fname)>>lname;
   // cout<<"Ur Name is : "<<fname<<lname<<endl;
   // cout<<int(fname[99])<<endl;

   /*************************Method 3 How to input in character arrays : getline********************************************/
   // char name[100];
   // cout<<sizeof(name)<<endl;
   // cin.getline(name, sizeof(name));
   // cout<<name<<endl;

   // //Using getline() with std::string
   // string place;
   // getline(cin, place);
   // cout<<place;
return 0;
}