#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/***V193_7 : Top K Frequent Words [LeetCode : https://leetcode.com/problems/top-k-frequent-words/]****/

class TrieNode{
    public:
        char value;
        bool isTerminal;
        int freq;
        unordered_map <char, TrieNode*> map;

        TrieNode(char value){
            this->value = value;
            this->isTerminal = false;
            this->freq = 0;
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
        root->freq++;
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


class cc{
    public:
    bool operator () (pair<string, int>& p1, pair<string, int>& p2){
        if(p1.second != p2.second){
            return p1.second > p2.second;
        }
        else{
            //Hard Way
            // int comp = (p1.first).compare((p2.first));
            // return comp < 0 ? true : false;

            //Giga chad way : use "<" for comparison :)
            return p1.first < p2.first;
        }
    }
};

void helperRE(string& str, priority_queue< pair<string, int>, vector< pair<string, int> >, cc>& minHeap, Tn* root, int& k){
    //B.C.
    if(root->isTerminal && root->map.empty()){
        str += root->value;
        
        //Try to push in minHeap
        if(!minHeap.empty()){
            auto temp = minHeap.top();
            if(minHeap.size() < k){
                minHeap.push({str, root->freq});
            }
            else if(minHeap.size() == k && (root->freq) == (temp.second)){
                if(str < temp.first){
                    minHeap.pop();
                    minHeap.push({str, root->freq});
                }
                else{
                    //Do Nothing
                }
            }
            else if(minHeap.size() == k && (root->freq) > (temp.second)){
                minHeap.pop();
                minHeap.push({str, root->freq});
            }
            else{
                //Dont push in minHeap
            }
        }
        else{
            minHeap.push({str, root->freq});
        }

        str.pop_back(); //backtrack
        return;
    }

    if(root->value != '#') str += root->value;
    if(root->isTerminal){
        //Try to push in minHeap
        if(!minHeap.empty()){
            auto temp = minHeap.top();
            if(minHeap.size() < k){
                minHeap.push({str, root->freq});
            }
            else if(minHeap.size() == k && (root->freq) == (temp.second)){
                if(str < temp.first){
                    minHeap.pop();
                    minHeap.push({str, root->freq});
                }
                else{
                    //Do Nothing
                }
            }
            else if(minHeap.size() == k && (root->freq) > (temp.second)){
                minHeap.pop();
                minHeap.push({str, root->freq});
            }
            else{
                //Dont push in minHeap
            }
        }
        else{
            minHeap.push({str, root->freq});
        }
    }
    for(auto itr = root->map.begin(); itr != root->map.end(); itr++){
        helperRE(str, minHeap, itr->second, k);
    }
    
    if(!str.empty()) str.pop_back(); //backtrack
    return;
}

void getWordsFromTrie(priority_queue< pair<string, int>, vector< pair<string, int> >, cc>& minHeap, Tn* root, int& k){
    string str = "";
    helperRE(str, minHeap, root, k);
    return;
}

vector<string> topKFrequent(vector<string>& words, int k) {
    //n = total number of words in "words"
    //Doing simple approx TC Calculations ignoring letters in each word & considering 1 word as a whole
    //Make trie of words (TC : O(n) {Visiting each word once while making the trie})
    Tn* root = new Tn('#');
    makeTrie(root, words);

    //Retrieve words from Trie
    //TC : O(n) + O(n log k) 
    //{say n words in Trie, each word's every letter visited in trie so approx this to TC O(n)}
    //{n words & minHeap of size k so TC : O(n log k)}
    priority_queue< pair<string, int>, vector< pair<string, int> >, cc> minHeap;  //pair <string, frequency>
    getWordsFromTrie(minHeap, root, k);

    vector<string> ans;

    //TC : O(k log k)
    //{Deleting k words from minHeap of size k so approx TC : O(k log k) i.e ignoring the reduced size of minHeap each time}
    while(!minHeap.empty()){
        auto temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp.first);
    }

    //TC : O(n)
    reverse(ans.begin(), ans.end());
    return ans;

    //Total TC : O(n) + O(n) + O(n log k) + O(k log K) + O(n)
    //i.e FINALLY TC : O(n log k) ____Line(1)
}


int main(){
   
return 0;
}