#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

/***V193_8 : Camelcase Matching [LeetCode : https://leetcode.com/problems/camelcase-matching/description/]***/

//M1 : My Method (Make Trie of queries) (Got beats 100% TC on LC)
//This method is better if queries are similar like "FooBar","FooBarTest","FootBall" etc..
//N : No. of queries
//qL : Avg length of a query
//TC : O(N*qL) + O(N*qL) (Making Trie & traversing trie)
//SC : O(N*qL) (Making Trie)

class TrieNode{
    public:
        char value;
        bool isTerminal;
        int index;
        unordered_map <char, TrieNode*> map;

        TrieNode(char value){
            this->value = value;
            this->isTerminal = false;
        }

        //No use in solution but good practice (Prevent Memory Leak)
        ~TrieNode(){
            for(auto itr = map.begin(); itr != map.end(); itr++){
                delete (itr->second);
            }
        }
};
typedef TrieNode Tn;

void insertInTrie(Tn* root, int ptr, string& word, int& i){
    //B.C
    if(ptr >= word.length()){
        root->isTerminal = true;
        root->index = i;
        return;
    }

    char currChar = word[ptr];
    if(root->map.find(currChar) == root->map.end()){
        Tn* temp = new TrieNode(currChar);
        root->map[currChar] = temp;
    }
    insertInTrie(root->map[currChar], ptr + 1, word, i);
}

void makeTrie(Tn* root, vector<string>& dictionary){
    for(int i = 0; i < dictionary.size(); i++){
        string word = dictionary[i];
        insertInTrie(root, 0, word, i);
    }
    return;
}

void helperRE(Tn* root, string& pattern, int ptr, bool NonMatchingCapitalFound, vector<bool>& ans){
    //BC
    if(root->isTerminal && root->map.empty()){
        if(ptr <= pattern.size()-2){
            //pattern to be matched is greater than 1 in length
            ans[root->index] = false;
        }
        else{
            //pattern to be matched is 1 or 0 in length
            if(NonMatchingCapitalFound){
                ans[root->index] = false;
            }
            else{
                if(ptr >= pattern.size()){ 
                    ans[root->index] = true;
                }
                else{
                    if(pattern[ptr] == root->value){
                        ans[root->index] = true;
                    }
                    else{
                        ans[root->index] = false;
                    }
                }
            }
        }
        return;
    }

    //You are on a Node of Trie
    if(root->isTerminal){
        if(ptr <= pattern.size()-2){
            //pattern to be matched is greater than 1 in length
            ans[root->index] = false;
        }
        else{
            //pattern to be matched is 1 or 0 in length
            if(NonMatchingCapitalFound){
                ans[root->index] = false;
            }
            else{
                if(ptr >= pattern.size()){ 
                    ans[root->index] = true;
                }
                else{
                    if(pattern[ptr] == root->value){
                        ans[root->index] = true;
                    }
                    else{
                        ans[root->index] = false;
                    }
                }
            }
        }
    }

    char currChar = '\0';
    if(ptr < pattern.size()) currChar = pattern[ptr];
    if(currChar == root->value){
        //current Char matched
        for(auto itr = root->map.begin(); itr != root->map.end(); itr++){
            helperRE(itr->second, pattern, ptr + 1, NonMatchingCapitalFound, ans);
        }
    }
    else{
        //currentn char not matched
        if((root->value >= 'A' && root->value <= 'Z')){
            NonMatchingCapitalFound = true;
        }
        for(auto itr = root->map.begin(); itr != root->map.end(); itr++){
            helperRE(itr->second, pattern, ptr , NonMatchingCapitalFound, ans);
        }
    }
    return;
}

void getAns(Tn* root, string& pattern, vector<bool>& ans){
    int ptr = 0;
    bool NonMatchingCapitalFound = false;
    helperRE(root, pattern, ptr, NonMatchingCapitalFound, ans);
}

vector<bool> camelMatch(vector<string>& queries, string pattern) {
    //make Trie
    Tn* root = new Tn('#');
    makeTrie(root, queries);

    //Get answer
    vector<bool> ans (queries.size(), false);
    getAns(root, pattern, ans);

    return ans;
}

//M2 : Make Trie of pattern (Lakshay bhaiya did this way)
//Here, no real use of trie, it's simple String matching ! 
//So M2 uses less space than M1 but if queries are similar then M1 will give better TC
//For M2, searching logic of trie would be modified i.e we will ignore non-matching lowercase alphabets (Acc To Ques)
//N : No. of queries
//qL : Avg length of a query
//pL : length of pattern
//TC : O(pL) + O(N*qL) (Making Trie & traversing trie for each query)
//SC : O(pL) (Making Trie) (More SC as compared to M1)

int main(){
   
return 0;
}