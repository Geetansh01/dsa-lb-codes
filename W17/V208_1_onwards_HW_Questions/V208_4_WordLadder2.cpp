#include<bits/stdc++.h>
using namespace std;

/*
    1)This solution got accepted on GFG but gave TLE on Leetcode. 
    2)For Leetcode, I guess you need to work with indices of strings rather than with strings themselves, because that is more efficient. Try that yourself.
    3)This prblm is extension of "L206 : WordLadder.cpp"
*/

//Main Logic : Find shortest route length (called "depth" in below solution) to "endWord" using BFS. 
//Then use DFS (only upto "depth") to get all transformation sequences

class Triplet{
    public:
        string str;
        int level;

        Triplet(string& s, int l){
            this->str = s;
            this->level = l;
        }
};
typedef Triplet T;

//No need for this function (See Warning below)
// bool oneLetterDiff(string& A, string& B){
//     int diffCount = 0;
//     for(int i = 0; i < A.length(); i++){
//         if(diffCount >= 2) return false;
//         if(A[i] != B[i]) diffCount++;
//     }
//     if(diffCount >= 2){
//         return false;
//     }
//     else{
//         return true;
//     }
// }

int bfs(string& beginWord, string& endWord, unordered_set<string> wl){
    queue<T> q;
    q.push(T(beginWord, 0));
    wl.erase(beginWord);

    while(!q.empty()){
        T frnt = q.front();
        q.pop();

        //Try to make all words with 1 word difference from current word
        string temp = frnt.str;
        int length = temp.length();
        for(int index = 0; index < length; index++){
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(ch == temp[index]) continue;
                temp[index] = ch;

                //check if this word in wordList
                if(wl.find(temp) != wl.end()){
                    string nbr = temp;
                    if(nbr == endWord){
                        //reached target word in shortest path
                        return frnt.level + 1;
                    }

                    if(wl.find(nbr) != wl.end()){
                        q.push(T(nbr, frnt.level + 1));
                        wl.erase(nbr);
                    }
                }
            }
            //restore "temp" to original string
            temp = frnt.str;
        }
    }

    return -1;
}

void dfs(string& currWord, string& endWord, vector<string>& temp, vector<vector<string>>& ans, unordered_set<string> wl, int depth){
    temp.push_back(currWord);
    wl.erase(currWord);

    //BC
    if(depth == 0){
        if(currWord == endWord) ans.push_back(temp);
        //backtrack
        temp.pop_back();
        wl.insert(currWord);
        return;
    }

    //Try to make all words with 1 word difference from current word
    string temp2 = currWord;
    int length = temp2.length();
    for(int index = 0; index < length; index++){
        for(int i = 0; i < 27; i++){
            char c = 'a' + i;
            if(c == temp2[index]) continue;
            temp2[index] = c;

            //check if this word in wordList
            if(wl.find(temp2) != wl.end()){
                string nbr = temp2;
                if(wl.find(nbr) != wl.end()){
                    dfs(nbr, endWord, temp, ans, wl, depth - 1);
                }
            }
        }
        //restore "temp" to original string
        temp2 = currWord;
    }
    
    //backtrack
    temp.pop_back();
    wl.insert(currWord);
    return;
}

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> wordList) {
    //WARNING : Don't go on making Adj List (it will be N^2 and you will get TLE). Below step is NOT EFFICIENT

    // //Making the adjacency list
    // unordered_map<string, list<string> > adjList; 

    // //WARNING : store the size in a separate "int" variable & use that inside for() loop. 
    // //Otherwise bht time waste hoga & you won't be able to debug!
    // int wlsize = wordList.size(); 
    // for(int i = -1; i < wlsize; i++){
    //     string& word = ((i == -1) ? beginWord : wordList[i]);
    //     if((word == beginWord) && (i != -1)) continue;
        
    //     for(int j = i + 1; j < wlsize; j++){
    //         string& word2 = wordList[j];

    //         if(word2 == beginWord) continue;
    //         if(word == word2) continue;

    //         if(oneLetterDiff(word, word2)){
    //             adjList[word].push_back(word2);
    //             adjList[word2].push_back(word);
    //         }
    //     }
    // }

    unordered_set<string> wl(wordList.begin(), wordList.end()); //copy of wordList (For more reasoning of why its made, see "L206 : WordLadder.cpp")
    
    vector<vector<string>> ans;

    //Get the depth of "endWord" usinig BFS
    int depth = bfs(beginWord, endWord, wl);
    if(depth == -1) return ans; //No way from "beginWord" to "endWord" found
    // cout<<depth<<endl;

    //Get all transformations using DFS
    vector<string> temp;
    dfs(beginWord, endWord, temp, ans, wl, depth);
    // cout<<wl.size()<<endl;
    
    return ans;
}

int main(){
   
return 0;
}