#include<iostream>
#include<vector>
using namespace std;

//TC : Exponential (2^n); n is length of string

vector<string> getSubsequences(string str){
    vector<string> ans;
    int n = str.length();

    //(1 << n) means (2^n). Eg: (1 << 3) is (2^3) i.e 8
    for(int num = 0; num < (1 << (n)); num++){
        string temp = ""; //we will create subsequence string in this "temp" string

        for(int i = 0; i < n; i++){
            char currCh = str[i];
            if(num & (1<<i)){
                //non-zero value ke liye include current character "currCh"
                temp.push_back(currCh);
            }
        }

        ans.push_back(temp);
    }

    return ans;
}

int main(){
    string str = "abc";
    vector<string> subsequences = getSubsequences(str);

    for(auto sbsq : subsequences){
        cout<<"||"<<sbsq<<endl;
    }
return 0;
}