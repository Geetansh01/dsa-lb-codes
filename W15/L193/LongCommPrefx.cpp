#include<iostream>
#include<vector>
using namespace std;

/****Longest Common Prefix [LeetCode : https://leetcode.com/problems/longest-common-prefix/description/]****/

//Can be done in TC : O(n*m) & SC : O(1) if we don't use Tries :p (See " Q 72 : Longest Common Prefix")

//TC : O(n*m) 
//SC : O(n*m)
//n : total no of strings
//m : length of longest string
class TrieNode{
    public:
    char value;
    TrieNode* children[26]; //Array of TrieNode pointers
    bool isTerminal;
    int childCount;

    TrieNode(char val){
        this->value = val;
        for(int i = 0; i < 26; i++){
            children[i] = NULL; //Initially, the node will not have any children!
        }
        this->isTerminal = false;
        this->childCount = 0;
    }

};

//insertion in Trie
void insertWord(TrieNode* root, string word){
    //Base Case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    //1 kam hm 
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if((root->children)[index] != NULL){
        //child present, so travel to that child
        child = (root->children)[index];
    }
    else{
        //child absent, so create child node & travel to it
        child = new TrieNode(ch);
        (root->children)[index] = child;
        (root->childCount)++;
    }

    //baki RE
    insertWord(child, word.substr(1));
}

void findLCP(string& ans, TrieNode* root){
    //WARNING : "if(root->childCount == 0)" can NOT be a base case, try dry running for " strs = ["","b"] "
    //Base Case
    if(root->isTerminal == true){
        return;
    }


    //1 kam hm
    TrieNode* child = NULL;
    if(root->childCount == 1){
        // child tk jao and "ans" me store kra lo
        for(int i = 0; i < 26; i++){
            if((root->children)[i] != NULL){
                child = (root->children)[i];
            }
        }
        ans.push_back(child->value);
    }   
    else{
        return;
    }    

    //Baki RE
    findLCP(ans, child); 
}

string longestCommonPrefix(vector<string>& strs) {
    TrieNode* root = new TrieNode('#');  

    //Insert all strings in Trie
    for(auto str : strs){
        insertWord(root, str);
    }

    string ans = "";
    findLCP(ans, root);
    return ans;
}

int main(){
   
return 0;
}