#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/************V200_6 : Word Break [LeetCode : https://leetcode.com/problems/word-break/description/]*********/

bool solveUsingRE(string s, int sptr, vector<string>& wordDict, int smallestWordLen, int largestWordLen){
    //BC
    if(sptr >= s.length()) return true;

    string tempWord = s.substr(sptr, smallestWordLen);
    int end = sptr + tempWord.length() - 1;
    while(end < s.length() && tempWord.length() <= largestWordLen){
        for(auto& word : wordDict){
            if(word == tempWord){
                if(solveUsingRE(s, end + 1, wordDict, smallestWordLen, largestWordLen)){
                    return true;
                }
                else{
                    break;
                }
            }
        }

        end++;
        if(end < s.length()){
            tempWord.push_back(s[end]);
        }
    }
    return false;
}

bool solveUsingMem(string s, int sptr, vector<string>& wordDict, int smallestWordLen, int largestWordLen, vector<int>& dp){
    //BC
    if(sptr >= s.length()) return true;

    if(dp[sptr] != -1){
        return dp[sptr];
    }

    string tempWord = s.substr(sptr, smallestWordLen);
    int end = sptr + tempWord.length() - 1;
    while(end < s.length() && tempWord.length() <= largestWordLen){
        for(auto& word : wordDict){
            if(word == tempWord){
                if(solveUsingMem(s, end + 1, wordDict, smallestWordLen, largestWordLen, dp)){
                    dp[sptr] = true;
                    return dp[sptr];
                }
                else{
                    break;
                }
            }
        }

        end++;
        if(end < s.length()){
            tempWord.push_back(s[end]);
        }
    }
    dp[sptr] = false;
    return dp[sptr];
}

bool solveUsingTab(string s, vector<string>& wordDict, int smallestWordLen, int largestWordLen){
    vector<int> dp(s.length() + 1, -1);
    // -1 means no answer in dp; 0 means False in dp & 1 means True

    dp[s.length()] = true;

    for(int sptr_i = s.length() - 1; sptr_i >= 0; sptr_i--){
        string tempWord = s.substr(sptr_i, smallestWordLen);
        int end = sptr_i + tempWord.length() - 1;
        bool ansFound = false;
        while(end < s.length() && tempWord.length() <= largestWordLen){
            for(auto& word : wordDict){
                if(word == tempWord){
                    if(dp[end + 1]){
                        dp[sptr_i] = true;
                        ansFound = true;
                        break;
                        // return dp[sptr]; 
                    }
                    else{
                        break;
                    }
                }
            }

            if(ansFound){
                //current sptr_i ka answer mil gya, now move to the next one 
                break;
            }

            end++;
            if(end < s.length()){
                tempWord.push_back(s[end]);
            }
        }
        
        if(ansFound){
            //current sptr_i ka answer mil gya, now move to the next one 
            continue;;
        }
        dp[sptr_i] = false;
    }

    return dp[0];
}

bool wordBreak(string s, vector<string>& wordDict) {
    //using "smallestWordLen" , "largestWordLen" only for optimization, you can omit these in your RE logic if you want!
    int smallestWordLen = INT_MAX;
    int largestWordLen = INT_MIN;
    for(auto word : wordDict){
        // smallestWordLen = min(smallestWordLen, static_cast<int>(word.length()));
        // largestWordLen = max(largestWordLen, static_cast<int>(word.length()));
        // Check for smallest word length
        if (word.length() < smallestWordLen) {
            smallestWordLen = word.length();
        }

        // Check for largest word length
        if (word.length() > largestWordLen) {
            largestWordLen = word.length();
        }
    }

    //Plain RE
    // int sptr = 0;
    // bool ans = solveUsingRE(s, sptr, wordDict, smallestWordLen, largestWordLen);

    //Mem
    // vector<int> dp(s.length() + 1, -1);
    // //-1 means no answer in dp; 0 means False in dp & 1 means True
    // int sptr = 0;
    // bool ans = solveUsingMem(s, sptr, wordDict, smallestWordLen, largestWordLen, dp);

    //Tab
    bool ans = solveUsingTab(s, wordDict, smallestWordLen, largestWordLen);

    return ans;
}

int main(){
   
return 0;
}