#include<iostream>
#include<vector>
using namespace std;

/***Edit Distance [LeetCode : https://leetcode.com/problems/edit-distance/description/]***/

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

int solveUsingMem(string& word1, string& word2, int i, int j, vector<vector<int> >& dp){
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

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(word1[i] == word2[j]){
        //Current characters matched
        ans = 0 + solveUsingMem(word1, word2, i+1, j+1, dp);
    }
    else{
        //Current characters not matched
        //OPerations perfom krlo

        //Insertion
        //Warning : "1 +" krna bhulega tu
        int option1 = 1 + solveUsingMem(word1, word2, i, j+1, dp);

        //Remove
        int option2 = 1 + solveUsingMem(word1, word2, i+1, j, dp);

        //Replace
        int option3 = 1 + solveUsingMem(word1, word2, i+1, j+1, dp);

        ans = min(option1, min(option2, option3));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTab(string word1, string word2){
    vector<vector<int> > dp(word1.length() + 1, vector<int>(word2.length() + 1, -1)); //row x col :: i x j (i trvrses word1 & j word2)

    //Fill initial data
    int tempRow = word1.length();
    for(int col = 0; col <= word2.length(); col++){
        dp[tempRow][col] = word2.length() - col;
    }

    int tempCol = word2.length();
    for(int row = 0; row <= word1.length(); row++){
        dp[row][tempCol] = word1.length() - row;
    }

    //Fill rest of DP
    for(int i_index = word1.length() - 1; i_index >= 0; i_index--){
        for(int j_index = word2.length() - 1; j_index >= 0; j_index--){
            int ans = 0;
            if(word1[i_index] == word2[j_index]){
                //Current characters matched
                ans = 0 + dp[i_index+1][j_index+1];
            }
            else{
                //Insertion
                int option1 = 1 + dp[i_index][j_index+1];

                //Remove
                int option2 = 1 + dp[i_index+1][j_index];

                //Replace
                int option3 = 1 + dp[i_index+1][j_index+1];

                ans = min(option1, min(option2, option3));
            }
            dp[i_index][j_index] = ans;
        }
    }

    return dp[0][0];
}

int solveUsingTabSO(string word1, string word2){
    // vector<vector<int> > dp(word1.length() + 1, vector<int>(word2.length() + 1, -1)); //row x col :: i x j (i trvrses word1 & j word2)
    vector<int> curr(word1.length() + 1, -1);
    vector<int> next(word1.length() + 1, -1);

    //Fill initial data (curr[] me initial data is being filled in for() loops)
    // int tempRow = word1.length();
    // for(int col = 0; col <= word2.length(); col++){
    //     dp[tempRow][col] = word2.length() - col;
    // }

    // Fill initial data in next[]
    // int tempCol = word2.length();
    for(int row = 0; row <= word1.length(); row++){
        next[row] = word1.length() - row;
    }

    //Fill rest of DP
    for(int j_index = word2.length() - 1; j_index >= 0; j_index--){

        //WARNING : Important line below; curr[] me initial data fill krna hai!
        // Fill initial data in curr[]
        int tempRow = word1.length();
        curr[tempRow] = word2.length() - j_index;

        for(int i_index = word1.length() - 1; i_index >= 0; i_index--){
            int ans = 0;
            if(word1[i_index] == word2[j_index]){
                //Current characters matched
                ans = 0 + next[i_index+1];
            }
            else{
                //Insertion
                int option1 = 1 + next[i_index];

                //Remove
                int option2 = 1 + curr[i_index+1];

                //Replace
                int option3 = 1 + next[i_index+1];

                ans = min(option1, min(option2, option3));
            }
            curr[i_index] = ans;
        }
        //Update next
        next = curr;
    }

    return next[0];
}

int minDistance(string word1, string word2) {
    //Plain RE
    // int i = 0;
    // int j = 0;
    // int ans = solveUsingRE(word1, word2, i, j);
    // return ans;

    //RE + Mem
    // vector<vector<int> > dp(word1.length() + 1, vector<int>(word2.length() + 1, -1)); //row x col :: i x j (i trvrses word1 & j word2)
    // int i = 0;
    // int j = 0;
    // int ans = solveUsingMem(word1, word2, i, j, dp);
    // return ans;

    //Tabulation
    // int ans = solveUsingTab(word1, word2);
    // return ans;

    //TabulationSO
    int ans = solveUsingTabSO(word1, word2);
    return ans;
}

int main(){
   
return 0;
}