#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

/*******V193_9 : Palindrome Pairs [LeetCode : https://leetcode.com/problems/palindrome-pairs/description/]****/

class TrieNode{
    public:
        char value;
        // bool isTerminal; //Not needed
        int index; //index of string in "words[]"
        unordered_map <char, TrieNode*> map;

        TrieNode(char value){
            this->value = value;
            // this->isTerminal = false;
            this->index = -1; 
        }

        //No use in solution but good practice (Prevent Memory Leak)
        ~TrieNode(){
            for(auto itr = map.begin(); itr != map.end(); itr++){
                delete (itr->second);
            }
        }
};
typedef TrieNode Tn;

void insertInTrie(Tn* root, int ptr, string& word, int& index){
    //B.C
    if(ptr >= word.length()){
        // root->isTerminal = true;
        root->index = index;
        return;
    }

    char currChar = word[ptr];
    if(root->map.find(currChar) == root->map.end()){
        Tn* temp = new TrieNode(currChar);
        root->map[currChar] = temp;
    }
    insertInTrie(root->map[currChar], ptr + 1, word, index);
}

bool isPalindrome(string& word, int i){
    if(i > word.size()){
        //ie word to be checked is effectively ""
        return true;
    }

    int start = i; 
    int end = word.size() -1;
    while(start <= end){
        if(word[start] == word[end]){
            start++; end--;
        }
        else{
            return false;
        }
    }
    return true;
}

void searchCase2(Tn* root, vector<int>& tempPairs, string& str){
    //BC
    if(root->map.empty() && root->index != -1){
        //Standing on a terminal Node with 0 children
        str += root->value;
        if(isPalindrome(str, 0)){
            tempPairs.push_back(root->index);
        }
        str.pop_back(); //BackTrack
        return;
    }

    str += root->value;
    if(root->index != -1){
        //Standing on a terminal Node
        if(isPalindrome(str, 0 )){
            tempPairs.push_back(root->index);
        }
    }

    //Go to all children of current Node
    for(auto itr = root->map.begin(); itr != root->map.end(); itr++){
        searchCase2(itr->second, tempPairs, str);
    }
    str.pop_back(); //BackTrack
    return;
}

void searchInTrie(string& srchWord, vector<int>& tempPairs, Tn* root){
    //Case 1 : when a prefix of srchWord matches with a complete word in trie
    int i = 0;
    while(i < srchWord.size()){
        char currChar = srchWord[i];

        if(root->index != -1){
            //Standing on a terminal Node, Check if the remaining srchWord is palindrome
            if(isPalindrome(srchWord, i)){
                tempPairs.push_back(root->index); //A palindromic pair of "word" found  
            }
        }
        
        if(root->map.find(currChar) != root->map.end()){
            //"currChar" matched with a child
            root = root->map[currChar];
            i++;
        }
        else{
            //"currChar" not matched with any children
            return;
        }
    }
    if(root->index != -1){
        //Standing on a terminal Node, Check if the remaining srchWord is palindrome
        if(isPalindrome(srchWord, i)){
            tempPairs.push_back(root->index); //A palindromic pair of "word" found  
        }
    }

    //Case 2 : when srchWord itself is a prefix of a word in a trie
    //Check remaining words in trie if they are palindrome
    //Go to all children of current Node
    for(auto itr = root->map.begin(); itr != root->map.end(); itr++){
        string str = "";
        searchCase2(itr->second, tempPairs, str);
    }
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    Tn* root = new Tn('#');

    //insert all string (in reverse) from "words[]" in trie
    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        reverse(word.begin(), word.end());
        insertInTrie(root, 0, word, i);
    }

    //Find palindromic pairs for each word in "words[]"
    for(int i = 0; i < words.size(); i++){
        vector<int> tempPairs; //Stores palindromic pairs of ith word
        searchInTrie(words[i], tempPairs, root);

        for(auto it : tempPairs){
            if(it != i){
                ans.push_back({i, it});
            }
        }
    }
    return ans;
}

int main(){
   
return 0;
}