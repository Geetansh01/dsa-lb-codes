#include<iostream>
#include<string>
using namespace std;


int main(){
    // //Input in string
    // string name="Geetansh";
    // // getline(cin, name);
    // cout<<name;
    // cout<<"lenth of str :"<<name.length()<<endl;
    // cout<<"empty? : "<<name.empty()<<endl;
    // name.push_back('A');
    // cout<<name<<endl;
    // name.pop_back();
    // cout<<name<<endl;
    // cout<<name.substr(1, 4)<<endl;

    // //Comparing string
    // string a = "zbcd";
    // string b = "abcd";
    // if(a.compare(b) == 0){
    //     cout<<"a and b are exactly same strings."<<endl;
    // }
    // else if(a.compare(b) < 0){
    //     cout<<a.compare(b)<<endl;
    // }
    // else if(a.compare(b) > 0){
    //     cout<<a.compare(b)<<endl;
    // }

    //Find something in a string
    // string sentence= "Hi my name is Geetansh";
    // string target = "myyy";
    // if(sentence.find(target) == string::npos){
    //     cout<<"Not Found"<<endl;
    // }
    // else{
    //     cout<<"Found at index : "<<sentence.find(target)<<endl;
    // }

    // // Replace in a string
    // string str = "My name is Geetansh";
    // string word = "Geetansh";

    // str.replace(0, 2 , word);
    // cout<<str<<endl;

    //Erase from string
    string str = "My goodname is Geetansh";
    str.erase(3, 8);
    cout<<str<<endl;
    


return 0;
}