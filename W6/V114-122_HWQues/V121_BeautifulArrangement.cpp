#include<iostream>
#include<vector>
using namespace std;

/************121 : Beautiful Arrangement [LeetCode : https://leetcode.com/problems/beautiful-arrangement/description/]****************/

//Both M1 and M2 have similar TC
//M1 : My Logic
void solveHelper(vector<int> &iarray, vector<int> &perms, int i, int &count){
    //Base Case
    if(i >= perms.size()){
        count++;
        return;
    }

    for(int j = i; j < perms.size(); j++){
        //Checking for beautiful arrangement
        if(iarray[i] % perms[j] != 0){
            if(perms[j] % iarray[i] != 0){
                continue;
            }
        }

        //Recursive call
        swap(perms[i], perms[j]);
        solveHelper(iarray, perms, i+1, count);

        //BackTrack
        swap(perms[i], perms[j]);
    }
}

int countArrangement(int n) {
    int count = 0;
    int i = 0;
    vector<int> perms;
    vector<int> iarray;
    for(int i = 1; i <= n; i++){
        perms.push_back(i);
        iarray.push_back(i);
    }
    solveHelper(iarray, perms, i, count);
    return count;
}

//M2 : Lakshay Bhaiya's Logic
// void solveHelper(vector<int> &perm, int num, int &count, int &n){
//     //Base Case
//     if(num == n+1){
//         count++;
//         return;
//     }

//     for(int i = 1; i < perm.size(); i++){
//         if(perm[i] == 0 && (i % num == 0 || num % i == 0)){
//             perm[i] = num;
            
//             //Recursive call
//             solveHelper(perm, num+1, count, n);

//             //backTrack
//             perm[i] = 0;
//         }
//     }
// }

// int countArrangement(int n) {
//     int count = 0;
//     vector<int> perm(n+1, 0);
//     int num = 1;
//     solveHelper(perm, num, count, n);
//     return count;
// }


int main(){
   cout<<countArrangement(4)<<endl;
return 0;
}