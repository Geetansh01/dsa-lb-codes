#include <iostream>
#include<vector>
#include<string>
using namespace std;

/****************Palindromic Substrings [LeetCode : https://leetcode.com/problems/palindromic-substrings/description/]**********************/

int palindromeCount(string s, int i, int j){
    int count = 0;
    while(i >= 0 && j < s.length() && s[i] == s[j]){
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s) {
    int count = 0;
    int n = s.length();
    
    for(int i = 0; i < n; i++){
        //Odd length substrings
        int oddKaAns = palindromeCount(s, i, i);
        count = count + oddKaAns;

        //Even length substrings
        int evenKaAns = palindromeCount(s, i, i+1);
        count = count + evenKaAns;
    }
    return count;
}

int main(){
    cout<<countSubstrings("aaa");
    return 0;
}

