#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;


int getASCIIsum(string& str, int index){
    int sum = 0;
    while(index < str.length()){
        sum += str[index++];
    }
    return sum;
}

int solveUsingRE(string& s1, string& s2, int i, int j){
    //BC
    if(i >= s1.length() && j >= s2.length()) return 0;
    if(i >= s1.length()){
        return getASCIIsum(s2, j);
    }
    if(j >= s2.length()){
        return getASCIIsum(s1, i);
    }

    //Try all options
    int ans = INT_MAX;
    if(s1[i] == s2[j]){
        //Option 1 : delete none (Only when the chars match)
        int option1 = 0 + solveUsingRE(s1, s2, i+1, j+1);
        ans = min(ans, option1);
    }
    else{
        //Option 2 : delete ith character from s1
        int option2 = s1[i] + solveUsingRE(s1, s2, i+1, j);
        
        //Option 3 : delete jth character from s2
        int option3 = s2[j] + solveUsingRE(s1, s2, i, j+1);
        
        //Option 4 : delete both characters 
        /*
            -Option 4 not needed separately, bcz age ke RE tree me Option 1 & 2 se ye wala case bhi chk ho jaega
            -Although option 4 se bhi code chl gya but only 13/93 Test Cases ke baad TLE lg gya but just option 1 & 2 se 63/93 Test Cases ke baad TLE lga
            -This is bcz with option 4 TC : O(3^N) {3 RE calls at each step of RE Tree} 
            -But without option 4 TC : O(2^N) {2 RE calls at each step of RE Tree} 
        */
        // int option4 = s1[i] + s2[j] + solveUsingRE(s1, s2, i+1, j+1);

        ans = min(option2, option3);
    }
    
    return ans;
} 

int solveUsingMem(string& s1, string& s2, int i, int j, vector<vector<int> >& dp){
    //BC
    if(i >= s1.length() && j >= s2.length()) return 0;
    if(i >= s1.length()){
        return getASCIIsum(s2, j);
    }
    if(j >= s2.length()){
        return getASCIIsum(s1, i);
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //Try all options
    int ans = INT_MAX;
    if(s1[i] == s2[j]){
        //Option 1 : delete none (Only when the chars match)
        int option1 = 0 + solveUsingMem(s1, s2, i+1, j+1, dp);
        ans = min(ans, option1);
    }
    else{
        //Option 2 : delete ith character from s1
        int option2 = s1[i] + solveUsingMem(s1, s2, i+1, j, dp);
        
        //Option 3 : delete jth character from s2
        int option3 = s2[j] + solveUsingMem(s1, s2, i, j+1, dp);
        
        ans = min(option2, option3);
    }
    dp[i][j] = ans;
    
    return dp[i][j];
} 

int solveUsingTab(string& s1, string& s2, int i, int j){
    vector<vector<int> > dp(s1.length() + 1, vector<int> (s2.length() + 1, -1)); //row x col :: i x j

    //Fill initial data
    //when i = s1.length()
    int s2Sum = getASCIIsum(s2, 0);
    for(int j = 0; j <= s2.length(); j++){
        dp[s1.length()][j] = s2Sum;
        s2Sum -= s2[j];
    }

    //when j = s2.length()
    int s1Sum = getASCIIsum(s1, 0);
    for(int i = 0; i <= s1.length(); i++){
        dp[i][s2.length()] = s1Sum;
        s1Sum -= s1[i];
    }

    dp[s1.length()][s2.length()] = 0;

    for(int i_indx = s1.length() - 1; i_indx >= 0; i_indx--){
        for(int j_indx = s2.length() - 1; j_indx >= 0; j_indx--){
                //Try all options
                int ans = INT_MAX;
                if(s1[i_indx] == s2[j_indx]){
                    //Option 1 : delete none (Only when the chars match)
                    int option1 = 0 + dp[i_indx+1][j_indx+1];
                    ans = min(ans, option1);
                }
                else{
                    //Option 2 : delete ith character from s1
                    int option2 = s1[i_indx] + dp[i_indx+1][j_indx];
                    
                    //Option 3 : delete jth character from s2
                    int option3 = s2[j_indx] + dp[i_indx][j_indx+1];
                    
                    ans = min(option2, option3);
                }
                dp[i_indx][j_indx] = ans;               
        }
    }

    return dp[0][0];

} 

int solveUsingTabSO(string& s1, string& s2, int i, int j){
    // vector<vector<int> > dp(s1.length() + 1, vector<int> (s2.length() + 1, -1)); //row x col :: i x j
    // vector<int> currRow (s2.length() + 1, -1); //Made Below
    vector<int> nextRow (s2.length() + 1, -1);

    //Fill initial data
    //"nextRow"
    int s2Sum = getASCIIsum(s2, 0);
    for(int j = 0; j <= s2.length(); j++){
        nextRow[j] = s2Sum;
        s2Sum -= s2[j];
    }
    nextRow[s2.length()] = 0;

    //"currRow"
    int initialSum = 0;

    for(int i_indx = s1.length() - 1; i_indx >= 0; i_indx--){
        initialSum += s1[i_indx]; 
        vector<int> currRow (s2.length() + 1, -1);
        currRow[s2.length()] = initialSum;

        for(int j_indx = s2.length() - 1; j_indx >= 0; j_indx--){
            //Try all options
            int ans = INT_MAX;
            if(s1[i_indx] == s2[j_indx]){
                //Option 1 : delete none (Only when the chars match)
                int option1 = 0 + nextRow[j_indx+1];
                ans = min(ans, option1);
            }
            else{
                //Option 2 : delete ith character from s1
                int option2 = s1[i_indx] + nextRow[j_indx];
                
                //Option 3 : delete jth character from s2
                int option3 = s2[j_indx] + currRow[j_indx+1];
                
                ans = min(option2, option3);
            }
            currRow[j_indx] = ans;                
        }

        nextRow = currRow;
    }

    return nextRow[0];

} 

int minimumDeleteSum(string s1, string s2) {
    int ans = 0;

    //Plain RE
    // int i = 0; //s1 pointer
    // int j = 0; //s2 pointer
    // ans = solveUsingRE(s1, s2, i, j);

    //Mem
    // int i = 0;
    // int j = 0;
    // vector<vector<int> > dp(s1.length() + 1, vector<int> (s2.length() + 1, -1)); //row x col :: i x j
    // ans = solveUsingMem(s1, s2, i, j, dp);

    //Tabulation
    // int i = 0;
    // int j = 0;
    // ans = solveUsingTab(s1, s2, i, j);

    //TabulationSO
    int i = 0;
    int j = 0;
    ans = solveUsingTabSO(s1, s2, i, j);
    
    return ans;
}

int main(){
   
return 0;
}