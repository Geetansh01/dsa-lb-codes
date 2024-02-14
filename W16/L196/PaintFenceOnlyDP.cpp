#include<iostream>
#include<vector>
using namespace std;

/****Painting the Fence [GFG : https://www.geeksforgeeks.org/problems/painting-the-fence3727/1]******/
//Note that GFG wants answer % (10^9 + 7), code to be submitted on GFG is at last of this file (written by me)

//Plain RE
int usingRE(int n,int k){
    //Base Case
    if(n == 1){
        return k;
    }
    if(n == 2){
        int same = k;
        int diff = k*(k-1);
        return same + diff;
    }

    int same = (k-1) * usingRE(n-2, k);
    int diff = (k-1) * usingRE(n-1, k);
    return same + diff;
}


//RE + Mem
int usingMem(int n,int k, vector<int>& dp){
    //Base Case
    if(n == 1){
        return k;
    }
    if(n == 2){
        int same = k;
        int diff = k*(k-1);
        return same + diff;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int same = (k-1) * usingMem(n-2, k, dp);
    int diff = (k-1) * usingMem(n-1, k, dp);
    dp[n] = same + diff;
    return dp[n];
}

//Tabulation
int usingTab(int n, int k){
    vector<int> dp(n+1, -1);

    dp[1] = k;
    int same = k;
    int diff = k*(k-1);
    dp[2] = (same + diff);

    for(int i = 3; i <= n; i++){
        int same = (k-1) * dp[i-2];
        int diff = (k-1) * dp[i-1];
        dp[i] = same + diff;
    }

    return dp[n];
}

//Tabulation Space Optimized
int usingTabSO(int n, int k){
    // vector<int> dp(n+1, -1);

    int prev = k;
    int same = k;
    int diff = k*(k-1);
    int next = (same + diff);

    int current = 0;
    for(int i = 3; i <= n; i++){
        int same = (k-1) * prev;
        int diff = (k-1) * next;
        current = same + diff;
        
        //WARNING : Updation Bhule Ga tu 
        //Update
        prev = next;
        next = current;
    }

    if(n == 1) return prev;
    if(n == 2) return next;
    return current;
}

int getPaintWays(int n ,int k){
    //PLain RE 
    // int ans = usingRE(n, k);
    // return ans;

    //RE + Mem
    // vector<int> dp(n+1, -1);
    // int ans = usingMem(n, k, dp);
    // return ans;
    
    //Tabulation
    // int ans = usingTab(n, k);
    // return ans;

    //Tabulation SO
    int ans = usingTabSO(n, k);
    return ans;
}

int main(){
   int n = 3;
   int k = 3;
   int ans = getPaintWays(n,k);
   cout<<ans<<endl;
return 0;
}


//Submit this on GFG
// #define M 1000000007
// long long usingMem(int n ,int alternatek, vector<long long>& dp){
//     //Base Case
//     if(n == 1){
//         long long k = alternatek; //bcz "alternatek" is "int" to calculation me kuch error ati hai so taking it's long long version
//         return k;
//     }
//     if(n == 2){
//         long long k = alternatek;
//         long long same = k%M;
//         long long diff = (k%M) * ((k-1)%M)%M;
//         return (same + diff)%M;
//     }

//     if(dp[n] != -1){
//         return dp[n];
//     }

//     long long k = alternatek;
//     long long same = ( ((k-1)%M) * usingMem(n-2, k, dp) )%M; //"usingMem(n-2, k, dp)" already modded value dega
//     long long diff = ( ((k-1)%M) * usingMem(n-1, k, dp) )%M;
//     dp[n] = (same + diff)%M;
//     return dp[n];
// }

// long long countWays(int n, int k){
//     //PLain RE
//     //...
    
//     //RE + Mem
//     vector<long long> dp(n+1, -1);
//     long long ans = usingMem(n, k, dp);
//     return ans;
// }