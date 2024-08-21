#include<bits/stdc++.h>
using namespace std;

/*
    Hints for solution:
    a)Yt (codestorywithMIK) (He got the main idea correct, don't nit pick the details!) : "https://youtu.be/2d1ALG8wwDc?si=8PblptyJQOq6XKiY"
*/

//TC: O(n + q); n = Length of string, q = no. of queries
typedef long long ll;
vector<ll> countKConstraintSubstrings(string str, int k, vector<vector<int>>& queries) {
    int n = str.length();

    // Array to store the rightmost index up to which the substring ending at each index is valid
    vector<int> rightMostSafeIndex(n, -1);
    int start = n - 1;
    int end = start;
    vector<int> count = {0, 0}; // count[0] -> number of '0's, count[1] -> number of '1's

    // Traverse the string from right to left to fill rightMostSafeIndex
    while (start >= 0) {
        count[str[start] - '0']++; // Update count for the current character

        // Shrink the window from the right if the k-constraint is violated
        while (!(count[0] <= k || count[1] <= k)) {
            count[str[end] - '0']--; 
            end--;
        }

        // Store the rightmost index that satisfies the k-constraint for the substring starting at 'start'
        rightMostSafeIndex[start] = end;
        start--;
    }

    // Print the rightMostSafeIndex array for debugging
    for (auto& index : rightMostSafeIndex) 
        cout << index << " ";

    // Prefix sum array to store the number of valid substrings ending at each index
    vector<ll> prefixSum(n, 0);
    start = 0;
    end = start;
    count = {0, 0};

    // Traverse the string from left to right to fill prefixSum
    while (end < n) {
        count[str[end] - '0']++; // Update count for the current character

        // Shrink the window from the left if the k-constraint is violated
        while (!(count[0] <= k || count[1] <= k)) {
            count[str[start] - '0']--; 
            start++;
        }

        // Calculate the number of valid substrings ending at index 'end'
        int validSubstringsEndingAtEnd = end - start + 1;
        prefixSum[end] = 1ll * validSubstringsEndingAtEnd + (end > 0 ? prefixSum[end - 1] : 0);
        end++;
    }

    // Vector to store the results for each query
    vector<ll> result;
    int totalQueries = queries.size();

    // Process each query
    for (int q = 0; q < totalQueries; q++) {
        int left = queries[q][0];
        int right = queries[q][1];

        ll answer = 0;
        int rightMostIndexForLeft = min(right, rightMostSafeIndex[left]); // rightmost index up to which the substring is valid
        int validSubstringLength = rightMostIndexForLeft - left + 1; // length of valid substring

        // Calculate the number of valid substrings for this query
        answer += (1ll * validSubstringLength * (validSubstringLength + 1)) / 2;
        answer += prefixSum[right] - prefixSum[rightMostIndexForLeft];

        result.push_back(answer);
    }

    return result;
} 


int main(){

return 0;
}