#include<bits/stdc++.h>
using namespace std;

//M1 : using Disjoint Set DS
//Ref(Striver's YT channel - Lakshay Bhaiya ne vahi se dekha hai) : "https://youtu.be/FMwpt_aQOGw?si=8ZvJUom1OWz1g28d"

//code for findParent() and unionSet() copied from V208_1_onwards_HW_Questions : KruskalsAlgoMST.cpp

//Find parent Recursively
int findParent(vector<int>& parent, int node){
    //BC
    
    int parentOfnode = findParent(parent, parent[node]);
    parent[node] = parentOfnode; //Path Compression
    
    return parentOfnode;
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
    int parentU = findParent(parent, u); 
    int parentV = findParent(parent, v);
    
    if(rank[parentU] < rank[parentV]){
        parent[parentU] = parentV;
    }
    else if(rank[parentU] > rank[parentV]){
        parent[parentV] = parentU;
    }
    else{
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    //Using Disjoint Set DS
    int n = accounts.size();
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    unordered_map<string, int> mp;
    //Iterate "accounts"
    for(int i = 0; i < n; i++){
        auto& account = accounts[i];

        for(int j = 1; j < account.size(); j++){
            string& email = account[j];

            //Check if "email" already in "mp"
            auto it = mp.find(email);
            if(it == mp.end()){
                //"email" not found in "mp", make it's entry 
                mp[email] = i;
            }
            else{
                //Do union 
                unionSet(i, it->second, parent, rank);
            }
        }
    }

    //Now make "preAns" using "parent[]" and "mp"
    unordered_map<int, set<string>> preAns;
    for(auto it : mp){
        int accountNo = it.second;
        string email = it.first;

        //Get true "accountNo" using" parent[]"
        accountNo = findParent(parent, accountNo);
        preAns[accountNo].insert(email);
    }

    //Now make final answer
    vector<vector<string>> ans; 
    for(auto it : preAns){
        int accountNo = it.first;

        vector<string> temp;
        temp.push_back(accounts[accountNo][0]); //push account name as the 0th index string from "accounts"


        for(auto email : it.second){
            temp.push_back(email);
        }

        ans.push_back(temp);
    }

    return ans;
}


//M2 : using DFS (without Disjoint Set DS)
// //More TC bcz i had to make the adjList (it took 2 nested loops :( )
// void dfs(string& curr, unordered_map<string, list<string>>& adjList, vector<string>& emails, unordered_map<string, bool>& visited){
//     visited[curr] = true;
//     emails.push_back(curr);

//     for(auto nbr : adjList[curr]){
//         if(!visited[nbr]){
//             dfs(nbr, adjList, emails, visited);
//         }
//     }

//     return;
// }

// vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//     //Make adjList
//     unordered_map<string, list<string>> adjList;
//     for(int i = 0; i < accounts.size(); i++){
//         for(int j = 1; j < accounts[i].size(); j++){
//             string& u = accounts[i][j];
//             for(int k = j + 1; k < accounts[i].size(); k++){
//                 string& v = accounts[i][k];
//                 adjList[u].push_back(v);
//                 adjList[v].push_back(u);
//             }
//         }
//     }

//     vector<vector<string>> ans;

//     unordered_map<string, bool> visited;
//     for(int i = 0; i < accounts.size(); i++){
//         //DFS
//         if(!visited[accounts[i][1]]){
//             vector<string> temp;
//             temp.push_back(accounts[i][0]);
//             vector<string> emails;

//             dfs(accounts[i][1], adjList, emails, visited);

//             //Sort the emails
//             sort(emails.begin(), emails.end());

//             for(auto& email : emails){
//                 temp.push_back(email);
//             }

//             ans.push_back(temp);
//         }
//     }


//     return ans;
// }

int main(){
   
return 0;
}