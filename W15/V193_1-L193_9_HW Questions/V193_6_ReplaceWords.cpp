#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/****V193_6 : Replace Words [LeetCode : https://leetcode.com/problems/replace-words/description/]****/

class TrieNode{
    public:
        char value;
        bool isTerminal;
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

void insertInTrie(Tn* root, int ptr, string& word){
    //B.C
    if(ptr >= word.length()){
        root->isTerminal = true;
        return;
    }

    char currChar = word[ptr];
    if(root->map.find(currChar) == root->map.end()){
        Tn* temp = new TrieNode(currChar);
        root->map[currChar] = temp;
    }
    insertInTrie(root->map[currChar], ptr + 1, word);
}

void makeTrie(Tn* root, vector<string>& dictionary){
    for(int i = 0; i < dictionary.size(); i++){
        string word = dictionary[i];
        insertInTrie(root, 0, word);
    }
    return;
}

void replaceWord(string& targetWord, Tn* root, bool& rootFound, string& rootWord, int ptr){
    //B.C
    if(ptr >= targetWord.length()){
        //"targetWord" khtm hogya
        rootFound = false;
        rootWord = "";
        return;
    }

    char currChar = targetWord[ptr];
    if((root->map.find(currChar) != root->map.end()) && root->map[currChar]->isTerminal){
        rootWord.push_back(currChar);
        rootFound = true;
        return;
    }

    if(root->map.find(currChar) != root->map.end()){
        rootWord.push_back(currChar);
        replaceWord(targetWord, root->map[currChar], rootFound, rootWord, ptr + 1);
    }
    else{
        rootFound = false;
        rootWord = "";
    }
    return;
}

string replaceWords(vector<string>& dictionary, string sentence) {
    //Making the trie
    Tn* root = new TrieNode('#');
    makeTrie(root, dictionary);

    //Replace words with roots
    string ans = "";
    for(int i = 0; i < sentence.length();){
        string targetWord = "";
        bool rootFound = false;
        string rootWord = "";
        int ptr = i;
        while(ptr < sentence.length() && sentence[ptr] != ' '){
            targetWord.push_back(sentence[ptr]);
            ptr++;
        }

        replaceWord(targetWord, root, rootFound, rootWord, 0);

        if(rootFound){
            ans += rootWord;
        }
        else{
            ans += targetWord;
        }
        ans.push_back(' ');
        i = ptr + 1;
    }
    
    // delete root; //Commenting to save Time on LeetCode
    ans.pop_back();
    return ans;  
}

int main(){
   
return 0;
}