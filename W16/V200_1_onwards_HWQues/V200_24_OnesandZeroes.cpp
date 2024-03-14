#include<bits/stdc++.h>
using namespace std;

int solveUsingRE(vector<string>& strs, int index, int m, int n){
    if(index >= strs.size()) return 0;

    int largestSubsetSize = 0;

    //Option1 : pick current string only if it can be picked!
    string& currStr = strs[index];
    int onesCnt = 0;
    int zerosCnt = 0;
    for(int i = 0; i < currStr.length(); i++){
        if(currStr[i] == '1'){
            onesCnt++;
        }
        else{
            zerosCnt++;
        }
    }

    int option1 = INT_MIN;
    if(onesCnt <= n && zerosCnt <= m){
        option1 = 1 + solveUsingRE(strs, index + 1, m - zerosCnt, n - onesCnt);
    }

    //Option2 : Don't pick current string
    int option2 = 0 + solveUsingRE(strs, index + 1, m, n);

    largestSubsetSize = max(option1, option2);
    return largestSubsetSize == INT_MIN ? 0 : largestSubsetSize;
}

int solveUsingMem(vector<string>& strs, int index, int m, int n, vector<vector<vector<int> > >& dp){
    if(index >= strs.size()) return 0;

    if(dp[index][m][n] != -1){
        return dp[index][m][n];
    }
    
    int largestSubsetSize = 0;

    //Option1 : pick current string only if it can be picked!
    string& currStr = strs[index];
    int onesCnt = 0;
    int zerosCnt = 0;
    for(int i = 0; i < currStr.length(); i++){
        if(currStr[i] == '1'){
            onesCnt++;
        }
        else{
            zerosCnt++;
        }
    }

    int option1 = INT_MIN;
    if(onesCnt <= n && zerosCnt <= m){
        option1 = 1 + solveUsingMem(strs, index + 1, m - zerosCnt, n - onesCnt, dp);
    }

    //Option2 : Don't pick current string
    int option2 = 0 + solveUsingMem(strs, index + 1, m, n, dp);

    largestSubsetSize = max(option1, option2);
    dp[index][m][n] = largestSubsetSize == INT_MIN ? 0 : largestSubsetSize;
    
    return dp[index][m][n]; 
}

int solveUsingTab(vector<string>& strs, int m, int n){
    vector<vector<vector<int> > > dp(strs.size() + 1, vector<vector<int> >(m + 1, vector<int>(n + 1, 0))); //A x B x C :: index x m x n

    for(int index_i = strs.size() - 1; index_i >= 0; index_i--){
        for(int m_i = 0; m_i <= m; m_i++){
            for(int n_i = 0; n_i <= n; n_i++){
                int largestSubsetSize = 0;

                //Option1 : pick current string only if it can be picked!
                string& currStr = strs[index_i];
                int onesCnt = 0;
                int zerosCnt = 0;
                for(int i = 0; i < currStr.length(); i++){
                    if(currStr[i] == '1'){
                        onesCnt++;
                    }
                    else{
                        zerosCnt++;
                    }
                }

                int option1 = INT_MIN;
                if(onesCnt <= n_i && zerosCnt <= m_i){
                    option1 = 1 + dp[index_i + 1][m_i - zerosCnt][n_i - onesCnt];
                }

                //Option2 : Don't pick current string
                int option2 = 0 + dp[index_i + 1][m_i][n_i];

                largestSubsetSize = max(option1, option2);
                dp[index_i][m_i][n_i] = largestSubsetSize == INT_MIN ? 0 : largestSubsetSize;
            }
        }
    }

    return dp[0][m][n];

}

int findMaxForm(vector<string>& strs, int m, int n) {
    int largestSubsetSize = 0;

    //Plain RE
    // int index = 0;
    // largestSubsetSize = solveUsingRE(strs, index, m, n);

    //Mem
    // int index = 0;
    // vector<vector<vector<int> > > dp(strs.size() + 1, vector<vector<int> >(m + 1, vector<int>(n + 1, -1))); //A x B x C :: index x m x n
    // largestSubsetSize = solveUsingMem(strs, index, m, n, dp);

    //Tabulation
    largestSubsetSize = solveUsingTab(strs, m, n);

    return largestSubsetSize;
}

int main(){
   
return 0;
}