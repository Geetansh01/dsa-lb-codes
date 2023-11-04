#include<iostream>
using namespace std;

/******************Q 77 : Longest Palindromic Substring [LeetCode : https://leetcode.com/problems/longest-palindromic-substring/description/]*********************************************/

//Method 1: Dynamic Programming (TC : O(n^2))
//DP will be done later on

//Method 2: Brute force (TC : O(n^3))
bool chkPalindrome(int s, int e, string& str){
    while (s < e){
        if(str[s] != str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

string longestPalindrome(string s) {
    //Handling strings like "a"
    if(s.size() == 1){
        return s;
    }

    //For all other strings
    string ans;
    string temp;
    int n = s.size();
    for(int i = 0; i < n-1; i++){
        //checking ODD length palindromes
        int a = i;
        int b = i;
        while(a>=0 && b<n && chkPalindrome(a, b, s)){
            temp = s.substr(a, b-a+1);
            a--;
            b++;
        }

        if(temp.size() > ans.size()){
            ans = temp;
        }

        //checking EVEN length Palindromes
        a = i;
        b = i + 1;
        while(a>=0 && b<n && chkPalindrome(a, b, s)){
            temp = s.substr(a, b-a+1);
            a--;
            b++; 
        }

        if(temp.size() > ans.size()){
            ans = temp;
        }
    }
    return ans;
}

int main(){
    string s = "PNOONOOBLTC";
    // string s = "a";
    string ans = longestPalindrome(s);

    cout<<"Longest Palindromic Substring : "<<ans;
}
