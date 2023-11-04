#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/***********************Q 76 : Group Anagrams[LeetCode : https://leetcode.com/problems/group-anagrams/description/]************************************/

//Method 1 : using STL map
//Don't worry about the syntax or difference between unordered_map, map etc... Map will be studied later.
// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     map<string, vector<string> > mp;

//     for(int i = 0; i < strs.size(); i++){
//         string temp = strs[i];
//         sort(temp.begin(), temp.end());
//         mp[temp].push_back(strs[i]);
//     }   

//     //Now iterate the map and make your answer
//     vector<vector<string>> ans;
//     for(auto iter = mp.begin(); iter != mp.end(); iter++){
//         ans.push_back(iter->second);
//     }

//     // Or u can use a range based for-each loop like this
//     // for(auto iter : mp){
//     //     ans.push_back(iter.second);
//     // }

//     return ans;
// }

//Method 2 : using std::array
std::array<int,256> hashTheString(string s){
    std::array<int, 256> arr = {0};
    for(int i = 0; i < s.size(); i++){
        arr[s[i] ]++;
    }
    return arr;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<std::array<int, 256>, vector<string> > mp;

    for(int i = 0; i < strs.size(); i++){
        std::array<int , 256> temp = hashTheString(strs[i]);
        mp[temp].push_back(strs[i]);
    }   

    //Now iterate the map and make your answer
    vector<vector<string>> ans;
    for(auto iter = mp.begin(); iter != mp.end(); iter++){
        ans.push_back(iter->second);
    }

    // Or u can use a range based for-each loop like this
    // for(auto iter : mp){
    //     ans.push_back(iter.second);
    // }

    return ans;
}

int main(){
    vector<string> strs = {"stop","pots","reed","","tops","deer","", "opts"};

    for(int i = 0; i < strs.size(); i++){
        cout<<strs[i]<<" ";
    }
    cout<<endl;

    vector<vector<string>> ans = groupAnagrams(strs);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
    }

    return  0;
}