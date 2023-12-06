#include<iostream>
#include<stack>
using namespace std;

/*******Q161 : Decode String [LeetCode : https://leetcode.com/problems/decode-string/description/]*********/

string decodeString(string s) {
    stack<char> stk;

    for(int i = s.length() - 1; i >= 0; i--){
        while(i >= 0 && s[i] != '['){
            stk.push(s[i]);
            i--;
        }

        if(i < 0) break;

        i--; //Now u are on a digit

        //Now get the expansion number
        int sum = 0;
        int pow = 0; //power of TEN
        while(i >= 0 && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';

            //Making correct power of Ten for place value of digit
            int TEN = 1;
            for(int n = 0; n < pow; n++){
                TEN = TEN*10;
            }
            pow++;
            sum = sum + (digit * TEN);
            i--;
        }

        i++;

        //Now you have the expansion number
        string t1;
        while(!stk.empty() && stk.top() != ']'){
            t1 = t1 +  stk.top();
            stk.pop();
        }
        if(!stk.empty()) stk.pop(); //Remove the ']'

        //Now expand the encoded string
        int loop = sum;
        string t2;
        for(int p = 0; p < loop; p++){
            t2 = t2 + t1;
        }

        //Push the expanded string back to stack from extreme right
        for(int m = t2.length() - 1; m >= 0; m--){
            stk.push(t2[m]);
        }
    }

    //Now the answer is in stack
    string ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

int main(){
   string encoded = "2[abc]3[cd]ef";
   string decoded = decodeString(encoded);
   cout<<decoded;
return 0;
}