#include<iostream>
using namespace std;

/***Edit Distance [LeetCode : https://leetcode.com/problems/edit-distance/description/]***/

//Below soln will Give TLE [DP Needed]

//Don't write names like "a" or "b" in interview, use intuitive names 
//If encountered "Memory Limit Exceed" when sbmitting on LC, try passing by reference
int solveUsingRE(string& word1, string& word2, int i, int j){
    //Base Case
    if(i >= word1.length()){
        //word1 wali string end hogyi
        //So word1 ki length maybe word2 se chota hai
        return word2.length() - j;
    }
    if(j >= word2.length()){
        //word1 wali string end hogyi
        //So word1 ki length maybe word2 se bdi hai
        return word1.length() - i;
    }

    int ans = 0;
    if(word1[i] == word2[j]){
        //Current characters matched
        ans = 0 + solveUsingRE(word1, word2, i+1, j+1);
    }
    else{
        //Current characters not matched
        //OPerations perfom krlo

        //Insertion
        //Warning : "1 +" krna bhulega tu
        int option1 = 1 + solveUsingRE(word1, word2, i, j+1);

        //Remove
        int option2 = 1 + solveUsingRE(word1, word2, i+1, j);

        //Replace
        int option3 = 1 + solveUsingRE(word1, word2, i+1, j+1);

        ans = min(option1, min(option2, option3));
    }

    return ans;
}

int minDistance(string word1, string word2) {
    int i = 0;
    int j = 0;
    int ans = solveUsingRE(word1, word2, i, j);
    return ans;
}

int main(){
   
return 0;
}