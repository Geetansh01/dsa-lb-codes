#include<bits/stdc++.h>
#define MOD 100000
using namespace std;

    
#define MOD 100000

int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start == end) return 0;
    if(start == 1) return -1;
    
    vector<int> visited(100000 + 1, 0);
    
    //Main Logic : BFS
    queue<pair<int, int> > q; //{number, BFS level}
    q.push({start, 0});
    visited[start] = 1;
    
    while(!q.empty()){
        auto frnt = q.front();
        q.pop();
        int currNum = frnt.first;
        int currLevel = frnt.second;
        
        for(auto& num : arr){
            if(num == 1) continue;
            
            int newNum = (currNum * num) % MOD;
            
            if(newNum == end) return currLevel + 1;

            //Note : Below line is WRONG Bcz MOD can reduce a bigger number to smaller one, so do not discard bigger numbers
            // if(newNum > end) continue;
            
            if(visited[newNum] == 0){
                q.push({newNum, currLevel + 1});
                visited[newNum] = 1;
            }
            
        }   
    }
    return -1;
}

int main(){

return 0;
}
