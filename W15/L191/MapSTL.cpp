#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
   //creation
   unordered_map<string, int> mp;
   

   //Insertion
   pair<string, int> p = make_pair("Scorpio", 9);
   mp.insert(p);

   pair<string, int> p2("Alto", 2);
   mp.insert(p2);

   mp["Audi"] = 10;


   //Access 
   cout<<mp["Scorpio"]<<endl;
   cout<<mp.at("Alto")<<endl;
   // cout<<mp.at("Ferrari")<<endl; //Compiler dependent output here, "Ferrari" is not a key in "mp"


   //Searching 
   cout<<mp.count("Scorpio")<<endl;
   cout<<mp.count("Ferrari")<<endl;

   if(mp.find("Scorpio") != mp.end()){
      cout<<"Fortuner in map"<<endl;
   }
   else{
      cout<<"Fortuner not in map"<<endl;
   }

   //Size of map
   cout<<"Size of map:"<<mp.size()<<endl;

   cout<<"Initially Size : "<<mp.size()<<endl; //3
   cout<<mp["RollsRoyce"]<<endl;
   cout<<"After trying to access RollsRoyce, size : "<<mp.size()<<endl; //4
   //Reason : using this syntax "mp[<key>]", if the key does not already exist, it will be inserted & some default value will be give to it (Like for "int" values, 0 will be given)

   //Iteration of map
   cout<<"Printing all the entries"<<endl;
   for(auto x : mp){
      cout<<x.first<<" -> "<<x.second<<endl;
   }


return 0;
}