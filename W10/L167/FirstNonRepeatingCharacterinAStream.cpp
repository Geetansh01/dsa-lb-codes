#include<iostream>
#include<queue>
using namespace std;

/*******First Non Repeating Character in A Stream [Interview] [GFG : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1]*******/

//TC : O(n)
//SC : O(n)

string FirstNonRepeating(string& str){
    int freq[26] = {0};
    queue<char> q;
    string ans = "";

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        //Step 1 : Increment frequency
        freq[ch - 'a']++;

        //Step 2 : push in q
        q.push(ch);

        //Step 3 : Find answer in q from front
        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }

        //If no first non-repeating character is found
        if(q.empty()){
            ans.push_back('#');
        }
    }

    return ans;
}

int main(){
    string str = "zarcaazrd";

    string ans = FirstNonRepeating(str);

    for(auto x : ans){
        cout<<x<<" ";
    }

return 0;
}