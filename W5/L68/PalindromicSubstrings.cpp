#include <iostream>
#include<vector>
#include<string>
using namespace std;

/****************Palindromic Substrings [LeetCode : https://leetcode.com/problems/palindromic-substrings/description/]**********************/

//Method 1 [TC : O(n^2)]
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

//Method 2 : Manacher's Algorithm
//TC : O(n)
// vector<int> manacher_odd(string t){
//     int n = t.size();
//     string s = "$" + t + "^";
//     vector<int> p(n + 2, 0);
//     int l = 1, r = 1; 
//     for(int i = 1; i <= n; i++){
//         p[i] = max(0, min(r-i, p[l + (r-i)]));
//         //Trivial Algo
//         while(s[i - p[i]] == s[i + p[i]]){
//             p[i]++;
//         }
//         if(i + p[i] > r){
//             l = i - p[i]; 
//             r = i + p[i];
//         }
//     }
//     return vector<int>(begin(p) + 1, end(p) - 1);
// }

// int manacher(string t){
//     string s = ""; //An empty string
//     for(auto& chr : t){
//         s = s + "#" + chr;
//     }
//     s += "#";
//     vector<int> d = manacher_odd(s);

//     //Get d(odd) & d(even) for "t" from d
//     int n = t.size();
//     vector<int> d_odd(n, 0);
//     vector<int> d_even(n, 0);
//     for(int i = 0; i < n; i++){
//         d_odd[i] = d[2*i + 1]/2;
//         d_even[i] = (d[2*i] - 1)/2;
//     }

//     //Finally Total palindromic substrings
//     int tot = 0;
//     for(int i = 0; i < n; i++){
//         tot += d_odd[i] + d_even[i];
//     }
//     return tot;
// }

// int countSubstrings(string s) {
//     return (manacher(s));
// }

int main(){
    cout<<countSubstrings("aaa");
    return 0;
}

