#include<bits/stdc++.h>
using namespace std;

//Main Logic of Both M1 & M2 : BFS to get the shortest path
//M1 Does BFS in a general way (See code to understand)
//M2 makes an adjacent List and performs BFS on that (M2 takes (N^2) while making the adjacency list :( )

//M1 : using unordered_set [TC : O(N)]  ; N = wordList.size()
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int> > q;
    q.push({beginWord, 1});

    unordered_set<string> st(wordList.begin(), wordList.end()); //This is a copy of wordList
    //We don't want to change the original wordList & also we will be deleting things from this copy so we used "unordered_set"

    //Jo bhi word queue me push kro use "St" se hta do
    st.erase(beginWord);

    while(!q.empty()){
        pair<string, int> fNode = q.front();
        q.pop();

        string currString = fNode.first;
        int currLevel = fNode.second;

        //Check if "endWord" pr to nhi aa gye
        if(currString == endWord){
            return currLevel;
        }

        for(int index = 0; index < currString.length(); index++){
            //Hr index pr 'a' to 'z' sare alphabets rkhke "currString" se 1 char differ krne wale word bnao
            
            for(char ch = 'a'; ch <='z'; ch++){
                string newString = currString;
                newString[index] = ch;

                //Check if this newly formed word present in wordList
                if(st.find(newString) != st.end()){
                    q.push({newString, currLevel + 1});
                    st.erase(newString);
                }
            }

        }

    }

    return 0; //Yahan tk aa ge to "endWord" NOT present in "wordList"; 
}
 

//M2 : My solution [TC : O(N^2)] ; N = wordList.size()
// int BFS(int src, int target, unordered_map<int, list<int> >& adjList, unordered_map<int, bool>& visited){
//     if(src == target) return 0; //This will never happen ATQ

//     queue<int> q;
//     int separator = INT_MAX;

//     q.push(src);
//     visited[src] = true;
//     q.push(separator);

//     int level = 1; 

//     while(!q.empty()){
//         int frontNode = q.front();
//         q.pop();

//         if(frontNode == separator){
//             level += 1;
//             if(!q.empty()){
//                 q.push(separator);
//             }
//         }
//         else{
            
//             bool targetFound = false;
//             for(auto neighbour : adjList[frontNode]){
//                 if(!visited[neighbour]){

//                     if(neighbour == target){
//                         targetFound = true;
//                     }

//                     q.push(neighbour);
//                     visited[neighbour] = true;
//                 }
//             }

//             if(targetFound) return level;

//         }

//     }

//     return INT_MAX; //target not found!
// }


// bool chkOneLetterDiff(string& beginWord, string& word){
//     int NoDiffLetters = 0;
//     for(int i = 0; i < beginWord.length(); i++){
//         if(beginWord[i] != word[i]) NoDiffLetters++;
//     }

//     return (NoDiffLetters == 1) ? true : false;
// }


// int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//     // Main Logic : shortest path via BFS in Undirected graph

//     //Make adjList
//     unordered_map<int, list<int> > adjList;
//     int wls = wordList.size()-1;
//     for(int index = -1; index <= wls; index++){
//         string& currWord = (index == -1) ? beginWord : wordList[index]; 

//         for(int index2 = index + 1; index2 <= wordList.size()-1; index2++){
//             string& word = wordList[index2];
//             if(chkOneLetterDiff(currWord, word)){
//                 adjList[index].push_back(index2);
//                 adjList[index2].push_back(index);
//             }
//         }
//     }

//     //BFS
//     unordered_map<int, bool> visited;
//     int smallestLen = 0;
//     int src = -1;

//     int target;
//     for(int index = 0; index <= wls; index++){
//         if(wordList[index] == endWord){
//             target = index;
//             break;
//         }
//     }

//     smallestLen = BFS(src, target, adjList, visited);

//     return smallestLen == INT_MAX ? 0 : smallestLen + 1;

// }

int main(){

return 0;
}