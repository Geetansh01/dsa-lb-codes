#include<bits/stdc++.h>
using namespace std;

//Ref for soln (I upsolved after watching till 3:55, so my approach below is a bit different but the main idea is the same) : https://youtu.be/pwLdf3gFby0?si=S9O4ybpeagQvyu_T

/* Iterative Function to calculate (x^y)%p in O(log y) */ //Taken from "L86_ModularExponentiation.cpp"
int power(int a, int b, int p){
    int ans = 1;
    
    while(b>0){
        //if power is odd
        if(b&1){
            ans = (ans%p * a%p) %p;
        }
        a = (a%p * a%p);
        b = b>>1;
    }
    
    return ans%p;
} 

int solveRE(int i, int Tmod, int k, string& str){
    int n = str.length(); 

    int posJ = n-i-1;
    int x = power(10, n-i-1, k);
    int y = power(10, n-posJ-1, k);
    for(int digit = 9; digit >= 1; digit--){
        int mod1 = (digit%k * x)%k;
        int mod2 = posJ != i ? (digit%k * y)%k : 0;
        int totMod = (mod1 + mod2)%k;
        int furtherTmod = Tmod - totMod;
        while(furtherTmod < 0) furtherTmod += k;
        if(i < ceil((1.0*n)/2) - 1){
            int nextDigit = solveRE(i+1, furtherTmod, k, str);
            if(nextDigit != -1){
                str[i+1] = (nextDigit + '0');
                str[posJ - 1] = (nextDigit + '0');
                // cout<<digit;
                return digit;
            }
        }
        else{
            if(totMod == Tmod){
                // cout<<digit;
                return digit;
            }
        }
    }

    return -1;
}

int solveMem(int i, int Tmod, int& k, string& str, vector<vector<int>>& dp){
    int n = str.length(); 
    
    if(dp[i][Tmod] != -2){
        return dp[i][Tmod];
    }

    int posJ = n-i-1;
    int x = power(10, n-i-1, k);
    int y = power(10, n-posJ-1, k);
    for(int digit = 9; digit >= 1; digit--){
        int mod1 = (digit%k * x)%k;
        int mod2 = posJ != i ? (digit%k *y)%k : 0;
        int totMod = (mod1 + mod2)%k;
        int furtherTmod = Tmod - totMod;
        while(furtherTmod < 0) furtherTmod += k;
        if(i < ceil((1.0*n)/2) - 1){
            int nextDigit = solveMem(i+1, furtherTmod, k, str, dp);
            if(nextDigit != -1){
                str[i+1] = (nextDigit + '0');
                str[posJ - 1] = (nextDigit + '0');
                // cout<<digit;
                dp[i][Tmod] = digit;
                return dp[i][Tmod];
            }
        }
        else{
            if(totMod == Tmod){
                // cout<<digit;
                dp[i][Tmod] = digit;
                return dp[i][Tmod];
            }
        }
    }

    dp[i][Tmod] = -1;
    return dp[i][Tmod];
}

int solveTab(int& k, string& str){     
    int n = str.length(); 
    vector<vector<int>> dp(n, vector<int>(10, -2)); //i x Target Modulus ; -2 means no ans in dp

    int i = ceil((1.0*n)/2) - 1;
    int posJ = n-i-1;
    int x = power(10, n-i-1, k);
    int y = power(10, n-posJ-1, k);
    for(int Tmodidx = k-1; Tmodidx >= 0; Tmodidx--){
        for(int digit = 9; digit >= 1; digit--){
            int mod1 = (digit%k * x)%k;
            int mod2 = posJ != i ? (digit%k * y)%k : 0;
            int totMod = (mod1 + mod2)%k;
            int furtherTmod = Tmodidx - totMod;
            while(furtherTmod < 0) furtherTmod += k;
            // if(i < ceil((1.0*n)/2) - 1){
            //     int nextDigit = dp[i+1][furtherTmod];
            //     if(nextDigit != -1){
            //         str[i+1] = (nextDigit + '0');
            //         str[posJ - 1] = (nextDigit + '0');
            //         // cout<<digit;
            //         dp[i][Tmodidx] = digit;
            //         break;
            //         // return dp[i][Tmod];
            //     }
            // }
            // else{
                if(totMod == Tmodidx){
                    // cout<<digit;
                    dp[i][Tmodidx] = digit;
                    break;
                    // return dp[i][Tmod];
                }
            // }
        }
        if(dp[i][Tmodidx] == -2) dp[i][Tmodidx] = -1;
        // return dp[i][Tmod];
    }

    for(int iidx = ceil((1.0*n)/2)-1-1; iidx >= 0; iidx--){
        int posJ = n-iidx-1;
        int x = power(10, n-iidx-1, k);
        int y = power(10, n-posJ-1, k);
        for(int Tmodidx = k-1; Tmodidx >= 0; Tmodidx--){
            for(int digit = 9; digit >= 1; digit--){
            // if(Tmodidx >= k) continue;
                int mod1 = (digit%k * x)%k;
                int mod2 = posJ != iidx ? (digit%k * y)%k : 0;
                int totMod = (mod1 + mod2)%k;
                int furtherTmod = Tmodidx - totMod;
                while(furtherTmod < 0) furtherTmod += k;
                // if(iidx < ceil((1.0*n)/2) - 1){
                    int nextDigit = dp[iidx+1][furtherTmod];
                    if(nextDigit != -1){
                        // str[iidx+1] = (nextDigit + '0');
                        // str[posJ - 1] = (nextDigit + '0');
                        // cout<<digit;
                        dp[iidx][Tmodidx] = digit;
                        break;
                        // return dp[i][Tmodidx];
                    }
                // }
                // else{
                //     if(totMod == Tmodidx){
                //         // cout<<digit;
                //         dp[iidx][Tmodidx] = digit;
                //         break;
                //         // return dp[i][Tmod];
                //     }
                // }
            }
            if(dp[iidx][Tmodidx] == -2) dp[iidx][Tmodidx] = -1;
            // return dp[i][Tmod];
        }
    }

    int Tmod = 0;
    for(int iidx = 0; iidx <=  ceil((1.0*n)/2)-1; iidx++){
        int posJ = n - iidx - 1;
        int digit =  dp[iidx][Tmod];
        str[iidx] = (digit + '0');
        if(posJ != i) str[posJ] = (digit + '0');

        int mod1 = (digit%k * power(10, n-iidx-1, k))%k;
        int mod2 = posJ != i ? (digit%k * power(10, n-posJ-1, k))%k : 0;
        int totMod = (mod1 + mod2)%k;
        int furtherTmod = Tmod - totMod;
        while(furtherTmod < 0) furtherTmod += k;
        Tmod = furtherTmod;
    }

    return -1;
}

string largestPalindrome(int n, int k) {
    string str(n, '#');

    //RE
    // int digit = solveRE(0, 0, k, str);
    // str[0] = (digit + '0');
    // str[n-1] = (digit + '0');

    //Mem
    // vector<vector<int>> dp(n, vector<int>(10, -2)); //i x Target Modulus ; -2 means no ans in dp
    // int digit = solveMem(0, 0, k, str, dp);
    // str[0] = (digit + '0');
    // str[n-1] = (digit + '0');

    //Tabulation
    solveTab(k, str);

    return str;
}

int main(){

return 0;
}