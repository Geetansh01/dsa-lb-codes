#include<iostream>
using namespace std;

bool helperRE(string& str, int& s, int& e){
    //Base Case
    if(s >= e){
        return true;
    }

    //Solve 1 case
    if(str[s] != str[e]){
        return false;
    }
    else{
        s++; e--;
        return helperRE(str, s, e);
    }

}

bool checkPalindromeRE(string& str){
    int s = 0;
    int e = str.length()-1;
    bool ans = helperRE(str, s, e);
    return ans;
}

int main(){
   string a = "ABA";
   cout<<checkPalindromeRE(a);
return 0;
}