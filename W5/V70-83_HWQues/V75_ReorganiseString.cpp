#include<iostream>
#include<limits.h>
using namespace std;

/***********************Q 75 : Reorganise String [LeetCode : https://leetcode.com/problems/reorganize-string/]******************************************************/

string reorganizeString(string s) {
    int n = s.size();
    int hash[26] = {0};
    
    for(int i = 0; i < n; i++){
        hash[s[i] - 'a']++;
    }

    //finding most frequent character
    char most_freq_char;
    int max_freq = INT_MIN;

    for(int i = 0; i < 26; i++){
        if(hash[i] > max_freq){
            max_freq = hash[i];
            most_freq_char = i + 'a';
        }
    }

    //trying to place the " most_freq_char " in s with gap of 1
    int index = 0;
    while(index<n && max_freq>0){
        s[index] = most_freq_char;
        max_freq--;
        index = index + 2;
    }

    //if failed to place " most_freq_char " in s 
    if(max_freq != 0){
        return "";
    }

    hash[most_freq_char - 'a'] = 0;


    //if able to place " most_freq_char " then place all other chars in s in a circular manner with gap of one
    for(int i = 0; i < 26; i++){
        while(hash[i] > 0){
            //circular manner : if you go out of bound, start with index = 1
            if(index >= n){
                index = 1;
            }
            
            s[index] = i + 'a';
            hash[i]--;
            index = index + 2;
        }
    }
    return s;
}

int main(){
   string s = "aabc";
   cout<<"Ans : "<<reorganizeString(s)<<endl;
return 0;
}