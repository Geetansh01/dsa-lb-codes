#include<iostream>
using namespace std;

/*********************L97 Add Strings RE [LeetCode : https://leetcode.com/problems/add-strings/submissions/1075672381/]****************************************/

void addRE(string& num1, int i, string& num2, int j, int& carry, string& ans){
    //Base Case
    if(i < 0 && j < 0){
        if(carry != 0){
            ans.push_back(carry + '0'); //ans needs to be reversed before we can get the final answer
            return; 
        }
        return;
    }

    //solve 1 case
    int sum = 0;
    if(i >= 0 && j >= 0){
        sum = carry + (num1[i] - '0') + (num2[j] - '0');
    }
    else{
        if(j < 0){
            sum = carry + (num1[i] - '0') + 0;
        }
        else{
            sum = carry + 0 + (num2[j] - '0');
        }
    }
    carry = sum/10;
    sum = sum%10;
    ans.push_back(sum + '0');
    i--; j--;
    addRE(num1, i, num2, j, carry, ans);
}

string addStrings(string& num1, string& num2) {
    int carry = 0;
    string ans = "";
    addRE(num1, num1.length()-1, num2, num2.length()-1, carry, ans);
    int s = 0;
    int e = ans.length() - 1;
    while(s < e){
        swap(ans[s++], ans[e--]);
    }
    return ans;
}

int main(){
    string a = "990";
    string b = "99";
    string ans = addStrings(a, b);
    cout<<ans<<endl;
   
return 0;
}