#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& freq){
    int ans = 0;

    //Hr dabbe me A to Z insert krne ka try kro
    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            //Pehle dabbe me 1 char mai insert krunga
            //Pehle dabbe me 1 char insert kr diya to 1 answer yaha mil gya 
            ans++;
            //Frequency update kro
            freq[i]--;

            //Baki dabbo me chars RE insert krke ans laega
            int REKaAns = solve(freq);
            ans += REKaAns;

            //Backtracking
            freq[i]++;
        }
    }

    return ans;
}

int numTilePossibilities(string tiles) {
    vector<int> freq(26, 0);
    //Count frequencies of chars
    for(auto ch : tiles){
        freq[ch - 'A']++;
    }

    int ans = solve(freq);
    return ans;
}

int main(){
   
return 0;
}