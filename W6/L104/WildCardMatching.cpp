#include<iostream>
using namespace std;

/********************Wild Card Matching [LeetCode : https://leetcode.com/problems/wildcard-matching/]**************************************/
//This soln gives TLE on LeetCode(DP needed)
bool helperRE(string& s, int si, string& p, int pi){
    //Base Case
    if(si >= s.size() && pi >= p.size()){
        return true;
    }
    else if(si >= s.size() && pi < p.size()){
        while(pi < p.size()){
            if(p[pi] != '*') return false;
            pi++;
        }
        return true;
    }
    else if(si < s.size() && pi >= p.size()){
        return false;
    }

    //Solve 1 case
    if(p[pi] == '*'){
        //Case 1 : '*' consumes no character from s
        bool caseA = helperRE(s, si, p, pi + 1);

        //Case 2 : * consumes 1 character from s
        bool caseB = helperRE(s, si+1, p, pi);

        return caseA || caseB;
    }
    else if(s[si] == p[pi] || p[pi] == '?'){
        return helperRE(s, si + 1, p, pi + 1);
    }
    else{
        //when there is no '*' and the current chars from s and p simply don't match
        return false;
    }

}

bool isMatch(string& s, string& p) {
    int si = 0; //Index for string s
    int pi = 0; //Index for string p
    return helperRE(s, si, p , pi);
}

int main(){
   string s = "abcdefg";
   string p = "ab*ef?";
   cout<<"Do s and p match : "<<isMatch(s, p);
return 0;
}