#include<iostream>
using namespace std;

//Simple function to chwck whether key is present or not using RE
bool checkKey(string str, int i, int n, char key){
    //base case
    if(i >= n){
        return false;
    }

    //1 case solve kro
    if(str[i] == key){
        return true;
    }

    //baki recursion sambhal lega
    return checkKey(str, i+1, n, key);
}

//Modified " checkKey() " to take as many variables by reference as possible (To reduce SC nad sometimes TC as well)
bool checkKey2(string& str, int i, int& n, char& key){
    //base case
    if(i >= n){
        return false;
    }

    //1 case solve kro
    if(str[i] == key){
        return true;
    }

    //baki recursion sambhal lega
    return checkKey2(str, i, n, key);
}

// //Below function is same as " checkKey2() " but with even "i" passed by reference.
// //But it's not recommended as it is confusing :P
// bool checkKey3(string& str, int& i, int& n, char& key){
//     //base case
//     if(i >= n){
//         return false;
//     }

//     //1 case solve kro
//     if(str[i] == key){
//         return true;
//     }

//     //baki recursion sambhal lega
//     i = i+1;
//     return checkKey3(str, i, n, key);
//     //direct " return checkKey(str, i+1, n, key); " me gives error
// }

//Function to print indexes for all occurrences where key is found
void index_of_key(string& str, int i, int& n, char& key){
    //base case
    if(i >= n){
        return ;
    }

    //1 case solve kro
    if(str[i] == key){
        cout<<"key Found at index : "<<i<<endl;
    }

    //baki recursion sambhal lega
    index_of_key(str, i+1, n, key);  //OR write "return index_of_key(str, i+1, n, key); " as return type is "void"
}



int main(){
   string str = "Geetansh";
   int n = str.length();
   int i = 0;

   char key = 'e';

    //using checkKey()
   cout<<"Answer : "<<checkKey(str, i, n, key)<<endl;
   cout<<"i after running checkKey() (remains same as in main() ): "<<i<<endl;

    //using checkKey2()
   cout<<"Answer : "<<checkKey(str, i, n, key)<<endl;
   cout<<"i after running checkKey2() (remains same as in main() ): "<<i<<endl;


//     //using checkKey3()
//    cout<<"Answer : "<<checkKey3(str, i, n, key)<<endl;
//    cout<<"i after running checkKey3() (i now equal to index where key is found): "<<i<<endl;

    //using index_of_key()
    index_of_key(str, i, n, key);




return 0;
}