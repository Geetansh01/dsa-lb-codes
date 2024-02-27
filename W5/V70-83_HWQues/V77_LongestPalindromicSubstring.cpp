#include<iostream>
#include<limits.h>
using namespace std;

/******************Q 77 : Longest Palindromic Substring [LeetCode : https://leetcode.com/problems/longest-palindromic-substring/description/]*********************************************/

//Method 1: Dynamic Programming (TC : O(n^2))
//DP will be done later on

//Method 2: Brute force (TC : O(n^3))
bool chkPalindrome(string& s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}

string longestPalindrome(string s) {
    int maxPalinLen = INT_MIN;
    int startIndexOfAns = -1;
    for(int start = 0; start < s.length(); start++){
        for(int end = start; end < s.length(); end++){
            int currLen = end - start + 1;
            if(currLen > maxPalinLen && chkPalindrome(s, start, end)){
                maxPalinLen = currLen;
                startIndexOfAns = start;
            }
        }
    }

    string ansStr = s.substr(startIndexOfAns, maxPalinLen);

    return ansStr;   
}

//Method 2.1: Brute force (TC : O(n^3)) 
//Below Code is not efficient even for Brute force! [It runs in 1000+ ms]
// bool chkPalindrome(int s, int e, string& str){
//     while (s < e){
//         if(str[s] != str[e]){
//             return false;
//         }
//         s++;
//         e--;
//     }
//     return true;
// }

// string longestPalindrome(string s) {
//     //Handling strings like "a"
//     if(s.size() == 1){
//         return s;
//     }

//     //For all other strings
//     string ans;
//     string temp;
//     int n = s.size();
//     for(int i = 0; i < n-1; i++){
//         //checking ODD length palindromes
//         int a = i;
//         int b = i;
//         while(a>=0 && b<n && chkPalindrome(a, b, s)){
//             temp = s.substr(a, b-a+1);
//             a--;
//             b++;
//         }

//         if(temp.size() > ans.size()){
//             ans = temp;
//         }

//         //checking EVEN length Palindromes
//         a = i;
//         b = i + 1;
//         while(a>=0 && b<n && chkPalindrome(a, b, s)){
//             temp = s.substr(a, b-a+1);
//             a--;
//             b++; 
//         }

//         if(temp.size() > ans.size()){
//             ans = temp;
//         }
//     }
//     return ans;
// }


int main(){
    string s = "PNOONOOBLTC";
    // string s = "a";
    string ans = longestPalindrome(s);

    cout<<"Longest Palindromic Substring : "<<ans;
}
