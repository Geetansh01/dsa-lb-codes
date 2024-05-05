#include<bits/stdc++.h>
using namespace std;


//M1 : Using Variable Size Sliding Window + HashMap (std::unordered_map)
//TC : O(n + m) {Also see M2 below}
//m = s.length
//n = t.length

string minWindow(string s, string t) {
    int slen = s.length();
    int tlen = t.length();
    if(tlen > slen) return "";

    unordered_map<char, int> tMap; // char -> int; Frequency map for characters of "t"
    int count = 0; //Stores count of DISTINCT characters in "t"
    for(auto& ch : t){
        if(tMap[ch] == 0) count++;
        tMap[ch]++;
    }

    //Now traverse "s"; answer will be stored using "ansIndex" and "ansLen".
    int ansIndex = -1;
    int ansLen = INT_MAX; 

    //Initially start with 1 size window
    int start = 0; //start pointer
    int end = 0; //end pointer
    unordered_map<char, int> sMap; //Also Freq map for chars of "t" but when traversing "s"
    while(end < slen){
        char currCh = s[end];

        if(tMap.find(currCh) != tMap.end()){
            //If "currCh" present in "t" 
            sMap[currCh]++;

            if(sMap[currCh] == tMap[currCh]) count--; //Means "t" se 1 character completely mil gya 
            //i.e say this character is A. Say A ki Freq. "t" me 3 hai, to "s" me bhi "A" 3 times mil gya
        }

        while(count == 0){
            //If count is 0 means current window me pura "t" hai. Now window ko minimise kro

            //Pehle current window se answer store krlo
            int currLen = end - start + 1;
            if(currLen < ansLen){
                ansIndex = start;
                ansLen = currLen;
            } 

            //Now (start++) hoga. To "start" pe jo character hai uski Freq "sMap[]" me km kro
            char chAtStart = s[start];
            if(sMap.find(chAtStart) != sMap.end()){
                sMap[chAtStart]--;

                if(sMap[chAtStart] < tMap[chAtStart]) count++; //Means ab window me "t" nhi hai bcz count is NOT 0 anymore.
            }
            start++;
        }

        //Upr wale loop se ae ho means count is NOT 0 anymore, So window ka size increase kro
        end++; 
    }

    if(ansIndex == -1){
        return "";
    }
    else{
        //Make the answer string using "ansIndex" and "ansLen"
        return s.substr(ansIndex, ansLen);
    }
}

//M1 : Using Variable Size Sliding Window + HashMap (array) {TC same as M1}

//Even though M1 & M2 have same TC, still M2 is faster because using an array instead of an unordered_map as a hash map is faster. 
//M1 was giving title on GFG while M2 got accepted.
//GFG : [https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1]

// string minWindow(string s, string t) {
//     int slen = s.length();
//     int tlen = t.length();
//     if(tlen > slen) return "";

//     vector<int> tMap (128, 0); // char -> int; Frequency map for characters of "t"
//     int count = 0; //Stores count of DISTINCT characters in "t"
//     for(auto& ch : t){
//         if(tMap[ch] == 0) count++;
//         tMap[ch]++;
//     }

//     //Now traverse "s"; answer will be stored using "ansIndex" and "ansLen".
//     int ansIndex = -1;
//     int ansLen = INT_MAX; 

//     //Initially start with 1 size window
//     int start = 0; //start pointer
//     int end = 0; //end pointer
//     vector<int> sMap (128, 0); //Also Freq map for chars of "t" but when traversing "s"
//     while(end < slen){
//         char currCh = s[end];

//         if(tMap[currCh] != 0){
//             //If "currCh" present in "t" 
//             sMap[currCh]++;

//             if(sMap[currCh] == tMap[currCh]) count--; //Means "t" se 1 character completely mil gya 
//             //i.e say this character is A. Say A ki Freq. "t" me 3 hai, to "s" me bhi "A" 3 times mil gya
//         }

//         while(count == 0){
//             //If count is 0 means current window me pura "t" hai. Now window ko minimise kro

//             //Pehle current window se answer store krlo
//             int currLen = end - start + 1;
//             if(currLen < ansLen){
//                 ansIndex = start;
//                 ansLen = currLen;
//             } 

//             //Now (start++) hoga. To "start" pe jo character hai uski Freq "sMap[]" me km kro
//             char chAtStart = s[start];
//             if(sMap[chAtStart] != 0){
//                 sMap[chAtStart]--;

//                 if(sMap[chAtStart] < tMap[chAtStart]) count++; //Means ab window me "t" nhi hai bcz count is NOT 0 anymore.
//             }
//             start++;
//         }

//         //Upr wale loop se ae ho means count is NOT 0 anymore, So window ka size increase kro
//         end++; 
//     }

//     if(ansIndex == -1){
//         return "";
//     }
//     else{
//         //Make the answer string using "ansIndex" and "ansLen"
//         return s.substr(ansIndex, ansLen);
//     }
// }


int main(){
   
return 0;
}