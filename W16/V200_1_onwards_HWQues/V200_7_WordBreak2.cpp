#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
using namespace std;

/********/

/*
    Note 2 things about this question : 
    1)Initially while writing the Plain RE solution, i wrote "solveUsingRE()" [Which surprisingly beats 100% on LC, with 0ms TC].
    2)But then when i had to write the RE + Mem solution, dp could not be applied with "solveUsingRE()" bcz it makes answer by going upto the Base Case, but dp helps whenn there is already an anwer stored for a smaller subproblem. So i had to write another plain RE solution i.e "solveUsingRE2()" and then apply Memoization to it
    3)Also, the dp we made here is " unordered_map<int, vector<string> > dp; ", it stores all valid sentences for a given index of string "s" [i.e given index se lekr "s" ke end tk ki "s" ko consider krte hue all the valid sentences]
*/
void solveUsingRE(string& s, vector<string>& wordDict, int sptr, string& sentence, vector<string>& allSentences){
    //BC
    if(sptr >= s.length()){
        allSentences.push_back(sentence);
        return;
    } 

    string ogSentence = sentence; //will be used for backtracking

    string tempWord = "";
    for(int i = sptr; i < s.length(); i++){
        tempWord += s[i];
        for(auto& word : wordDict){
            if(tempWord == word){
                if(i != (s.length() - 1)){
                    sentence = (sentence + tempWord + " ");
                }
                else{
                    sentence += tempWord;
                }
                solveUsingRE(s, wordDict, i + 1, sentence, allSentences);
                sentence = ogSentence; //backtracking
            }
        }
    }
    return;
}

vector<string> solveUsingRE2(string& s, vector<string>& wordDict, int sptr){
    //BC
    if(sptr >= s.length()){
        return {""}; //so, vector containing "" means BC se hoke aa rhe hai
    } 

    vector<string> allSentences;
    string tempWord = "";
    for(int i = sptr; i < s.length(); i++){
        tempWord += s[i];
        for(auto& word : wordDict){
            if(tempWord == word){
                vector<string> REKaAns = solveUsingRE2(s, wordDict, i + 1);
                if(REKaAns.size() > 0){
                    //Means kuch aya age se i.e valid sentences bnke aye
                    for(auto& sentence : REKaAns){
                        if(sentence == ""){
                            sentence = tempWord + sentence;
                        }
                        else{
                            sentence = tempWord + " " + sentence;
                        }
                        allSentences.push_back(sentence);
                    }
                }
            }
        }
    }
    return allSentences;
}

//Memoized version of "solveUsingRE2()"
vector<string> solveUsingMem(string& s, vector<string>& wordDict, int sptr, unordered_map<int, vector<string> >& dp){
    //BC
    if(sptr >= s.length()){
        return {""}; //so, vector containing "" means BC se hoke aa rhe hai
    } 

    if(dp.find(sptr) != dp.end()){
        return dp[sptr];
    }

    vector<string> allSentences;
    string tempWord = "";
    for(int i = sptr; i < s.length(); i++){
        tempWord += s[i];
        for(auto& word : wordDict){
            if(tempWord == word){
                vector<string> REKaAns = solveUsingMem(s, wordDict, i + 1, dp);
                if(REKaAns.size() > 0){
                    //Means kuch aya age se i.e valid sentences bnke aye
                    for(auto& sentence : REKaAns){
                        if(sentence == ""){
                            sentence = tempWord + sentence;
                        }
                        else{
                            sentence = tempWord + " " + sentence;
                        }
                        allSentences.push_back(sentence);
                    }
                }
            }
        }
    }
    dp[sptr] = allSentences;

    return dp[sptr];
}

vector<string> wordBreak(string s, vector<string>& wordDict) {

    //Plain RE 1
    // vector<string> allSentences;
    // string sentence = "";
    // int sptr = 0; //string "s" pointer (iterates over it - not programming wala pointer) 
    // solveUsingRE(s, wordDict, sptr, sentence, allSentences);
    // return allSentences;

    // //Plain RE 2
    // int sptr = 0; //string "s" pointer (iterates over it - not programming wala pointer) 
    // return solveUsingRE2(s, wordDict, sptr);

    //Mem
    int sptr = 0; //string "s" pointer (iterates over it - not programming wala pointer) 
    unordered_map<int, vector<string> > dp;
    return solveUsingMem(s, wordDict, sptr, dp);
}

int main(){
   
return 0;
}