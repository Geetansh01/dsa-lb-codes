#include <iostream>
#include<vector>
using namespace std;

/***Important Question : Interview me yhi puchega !*****/

class TrieNode
{
public:
    char value;
    TrieNode *children[26]; // Array of TrieNode pointers
    // 0 index -> 'a' ke liye
    // 1 index -> 'b' ke liye
    //...
    // 25 index -> 'z' ke liye

    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; // Initially, the node will not have any children!
        }
        this->isTerminal = false;
    }
};

// insertion in Trie
// TC : O(N); N is length of string to be inserted
void insertWord(TrieNode *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    // 1 kam hm
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if ((root->children)[index] != NULL)
    {
        // child present, so travel to that child
        child = (root->children)[index];
    }
    else
    {
        // child absent, so create child node & travel to it
        child = new TrieNode(ch);
        (root->children)[index] = child;
    }

    // baki RE
    insertWord(child, word.substr(1));
}

void storeStringsRE(TrieNode* root, string& word, vector<string>& ans){
    bool isLeaf = true;
    for(int i = 0; i < 26; i++){
        if((root->children)[i] != NULL){
            isLeaf = false;
            break;
        }
    }

    //Base Case
    if(isLeaf){
        word += root->value;
        ans.push_back(word);

        //backtrack
        word.pop_back();
        return;
    }

    //1 Case hm
    word += root->value;
    
    if(root->isTerminal == true){
        ans.push_back(word);
    }   

    TrieNode* child = NULL;
    for(int i = 0; i < 26; i++){
        if((root->children)[i] != NULL){
            //child exists, to is child pe RE Call i.e Baki kam RE
            child = (root->children)[i];
            storeStringsRE(child, word, ans);
        }
    }

    //backtrack
    word.pop_back();
    return;
}

void findAllPrefixStrings(TrieNode* root, string prefixCopy, string& prefix, vector<string>& ans){
    //Base Case
    if(prefixCopy.length() == 0){
        //when "prefix" itself is a valid string in the Trie
        //eg: prefix : "cat", "cat", "cater" are present int the Trie
        if(root->isTerminal){
            ans.push_back(prefix);
        }

        TrieNode* lastCharOfPrefix = root;
        string word = prefix + "";

        TrieNode* child = NULL;
        for(int i = 0; i < 26; i++){
            if((lastCharOfPrefix->children)[i] != NULL){
                child = (lastCharOfPrefix->children)[i];
                storeStringsRE(child, word, ans);
            }
        }
        return;
    }

    //1 kam hm
    char ch = prefixCopy[0];
    int index = ch - 'a';
    TrieNode* child = NULL;
    if((root->children)[index] != NULL){
        //child present, go to that child
        child = (root->children)[index];
    }
    else{
        //child not found, so given "prefix" se matching koi strings nhi hai so return
        return;
    }

    //baki RE
    findAllPrefixStrings(child, prefixCopy.substr(1), prefix, ans);
    return;
}

vector<vector<string> > getSuggestions(TrieNode* root, string input){
    vector<vector<string> > output;
    TrieNode* currRoot = root;
    string prefix = "";

    for(int i = 0; i < input.length(); i++){
                
        char lastChar = input[i];
        int index = lastChar - 'a';
        TrieNode* child = NULL;

        if((currRoot->children)[index] != NULL){
            //child found
            child = (currRoot->children)[index];
            vector<string> ans;

            storeStringsRE(child, prefix, ans);
            output.push_back(ans);

            prefix += input[i];

            //Update "currRoot" : Important optimisation
            currRoot = child;
        }
        else{
            //child not found, means Trie me matching words nhi hai
            break;
        }
    }

    return output;
}

int main()
{

    TrieNode *root = new TrieNode('#');
    insertWord(root, "cccccccc");
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "cat");
    insertWord(root, "car");
    insertWord(root, "love");
    insertWord(root, "lol");
    insertWord(root, "load");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "lovedone");
    insertWord(root, "lovedones");
    insertWord(root, "lllllllll");

    cout << "Insertion Done" << endl;

    //Get All words given a "prefix"
    // // string prefix = "";
    // string prefix = "lo";
    // // string prefix = "love";

    // vector<string> ans;

    // findAllPrefixStrings(root, prefix, prefix, ans);

    // for(auto x : ans){
    //     cout<<x<<" ";
    // }

    //Get All suggestions given a input word
    string input = "cat";
    vector<vector<string> > ans = getSuggestions(root, input);

    for(auto x : ans){
        cout<<"-> ";
        for(auto y : x){
            cout<<y<<" ";
        }

        cout<<endl;
    }

    return 0;
}