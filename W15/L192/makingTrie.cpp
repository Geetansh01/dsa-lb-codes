#include<iostream>
using namespace std;

//WARNING : neeche babbar bhaiya ka code hai, u won't remember it, write your own code

class TrieNode{
    public:
    char value;
    TrieNode* children[26]; //Array of TrieNode pointers
    //0 index -> 'a' ke liye
    //1 index -> 'b' ke liye
    //...
    //25 index -> 'z' ke liye

    bool isTerminal;

    TrieNode(char val){
        this->value = val;
        for(int i = 0; i < 26; i++){
            children[i] = NULL; //Initially, the node will not have any children!
        }
        this->isTerminal = false;
    }

};

//insertion in Trie
//TC : O(N); N is length of string to be inserted
void insertWord(TrieNode* root, string word){
    cout<<"receieved word : "<<word<<" for insertion"<<endl;
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
    }

    //baki RE
    insertWord(child, word.substr(1));
}

int main(){

     TrieNode* root = new TrieNode('#');
     insertWord(root, "donation");

return 0;
}