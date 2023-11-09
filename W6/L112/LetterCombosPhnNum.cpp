#include<iostream>
#include<vector>
using namespace std;

/*****************Letter Combinations of a Phone Number [LeetCode : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/]*************************************/

void solveHelper(vector<string>& phone_keys, vector<string> &ans, string output, string &digits, int i){
    //Base Case
    if(i >= digits.size()){
        ans.push_back(output);
        return;
    }

    //Recursive call for all letters for i-th number in digits
    int num = digits[i] - '1' + 1;
    for(int j = 0; j < phone_keys[num].size(); j++){
        output.push_back(phone_keys[num][j]);
        //Recursive Call
        solveHelper(phone_keys, ans, output, digits, i+1);
        //Backtrack
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    //Separately handle 1 case 
    if(digits == ""){return ans;}
    
    vector<string> phone_keys(10, "");
    phone_keys[2] = "abc";
    phone_keys[3] = "def";
    phone_keys[4] = "ghi";
    phone_keys[5] = "jkl";
    phone_keys[6] = "mno";
    phone_keys[7] = "pqrs";
    phone_keys[8] = "tuv";
    phone_keys[9] = "wxyz";

    string output;

    int i = 0;
    solveHelper(phone_keys, ans, output, digits, i);
    return ans;
}

int main(){
    string digits = "23";

    vector<string> ans = letterCombinations(digits);

    for(auto iter : ans){
      cout<<iter<<endl;
    }

return 0;
}