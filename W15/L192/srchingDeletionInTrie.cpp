#include<iostream>
using namespace std;

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

bool searchWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if((root->children)[index] != NULL){
        //"ch" to mil gya ab next srch krna hai
        child = (root->children)[index];
    }
    else{
        //"ch" nhi mila
        return false; 
    }

    //Baki RE
    return searchWord(child, word.substr(1));
}

void deleteWord(TrieNode* root, string word){
    //Base Case
    if(word.length() == 0){
        //mark it non-terminal
        root->isTerminal = false;
        return;
    }

    //1 case Hm
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if((root->children)[index] != NULL){
        //"ch" present
        child = (root->children)[index];
    }
    else{
        //word hi nhi hai Trie me to delete kya kru
        return;
    }

    //baki RE
    deleteWord(child, word.substr(1));
}

int main(){

     TrieNode* root = new TrieNode('#');
     insertWord(root, "cater");
     insertWord(root, "care");
     insertWord(root, "com");
     insertWord(root, "lover");
     insertWord(root, "loved");
     insertWord(root, "load");
     insertWord(root, "lov");
     insertWord(root, "bat");
     insertWord(root, "cat");
     insertWord(root, "car");

    cout<<"Insertion Done"<<endl;

    //Searching
    if(searchWord(root, "love")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
 
    if(searchWord(root, "load")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    if(searchWord(root, "Geetansh")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    //Deletion
    cout<<"Deletion from Trie"<<endl;
    if(searchWord(root, "cater")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    deleteWord(root, "cater");

    if(searchWord(root, "cater")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }


return 0;
}