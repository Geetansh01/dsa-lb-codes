#include<bits/stdc++.h>
using namespace std;

/*
    Two Methods (Same TC of both : O(n); n = length of string) : 
    
    a) Observation (Ref: LeetCode Hints of the problem)
        HINTS (From LeetCode):
        Hint 1: Consider the set of substrings that end at a certain index i. Then, consider a specific alphabetic character. How do you count the number of substrings ending at index i that contain that character?
        Hint 2: The number of substrings that contain the alphabetic character is equivalent to 1 plus the index of the last occurrence of the character before index i + 1.
        Hint 3: The total appeal of all substrings ending at index i is the total sum of the number of substrings that contain each alphabetic character.
        Hint 4: To find the total appeal of all substrings, we simply sum up the total appeal for each index.

    b) DP (Ref: https://leetcode.com/problems/total-appeal-of-a-string/solutions/1996300/python3-o-n-o-1-detail-for-beginners)
        (i) DP in the sense that we would solve such that "solution of current problem would depend on the solution of a smaller subproblem"
        (ii) DP method pe ane se pehle do method "a) Observation". Then DP method sense bnaega!
        (iii) NOTE: Final answer is not in any single cell of "dp" like usual, it is the sum of values in all cells of the "dp"

    c) Combinatorics (Ref: https://leetcode.com/problems/total-appeal-of-a-string/solutions/1999226/Combinatorics)
*/

// //M1 : According to LeetCode Hints 
// long long appealSum(string str) {
//     int n = str.size();
//     long long sum = 0;
//     vector<int> lastOccurrence(26, -1); // character(a to z) -> Last occurrence of that character

//     for(int i = 0; i < n; i++){
//         lastOccurrence[str[i] - 'a'] = i;
        
//         //Loop 26 times for all the alphabets
//         for(int i = 0; i < 26; i++){
//             if(lastOccurrence[i] == -1) continue; //Means this character has not yet appeared
//             sum += lastOccurrence[i] + 1;
//         }
//     }
//     return sum;
// }

// M2 : DP 
long long appealSum(string str) {
    int n = str.size();

    vector<int> lastOccurrence(26, -1); // character(a to z) -> Last occurrence of that character
    vector<long long> dp(n, 0); // index "i" -> Appeal of substrings ending at "i"th index (and starting from 0th index)
    dp[0] = 1;
    lastOccurrence[str[0] - 'a'] = 0; //character at 0th index last occurred at 0th index

    //Fill the "dp" from 1st index onwards
    for(int i = 1; i < n; i++){
        if(lastOccurrence[str[i] - 'a'] == -1){
            //Means this character has not yet appeared
            dp[i] = dp[i-1] + (i+1);
        }
        else{
            int prevIndex = lastOccurrence[str[i] - 'a'];
            dp[i] = dp[i-1] + ((i+1) - (prevIndex+1));
        }

        lastOccurrence[str[i] - 'a'] = i; //Update the last occurrence 
    }

    //NOTE: Final answer is not in any single cell of "dp" like usual, it is the sum of values in all cells of the "dp"
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += dp[i];
    }
    return sum;
}

// //M3 : Combinatorics
// long long appealSum(string str) {
//     int n = str.size();
//     long long sum = 0;
//     vector<int> lastOccurrence(26, -1); // character(a to z) -> Last occurrence of that character

//     for(int i = 0; i < n; i++){
//         sum += (i - lastOccurrence[str[i] - 'a']) * (n - i);
//         lastOccurrence[str[i] - 'a'] = i;
//     }
//     return sum;
// }

int main(){

return 0;
}