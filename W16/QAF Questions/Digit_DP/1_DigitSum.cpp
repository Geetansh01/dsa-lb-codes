#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " "; _print(x); cout << endl;

typedef long long int ll;

void _print(bool x) { cout << x; }
void _print(int x) { cout << x; }
void _print(long long int x) { cout << x; }
void _print(float x) { cout << x; }
void _print(double x) { cout << x; }
void _print(char x) { cout << x; }
void _print(string x) { cout << x; }

template<class T>
void _print(vector<T> v) {
    cout << "[";
    for (T ele : v) {
        cout << ele << ", ";
    }
    cout << "]";
}

const int MOD = 1e9 + 7;

/*****************************************************************************************************/
/* Iterative Function to calculate x^y in O(log y) */ //Taken from "L86_ModularExponentiation.cpp"
ll power(ll a, ll b){
    ll ans = 1;
    
    while(b>0){
        //if power is odd
        if(b&1){
            ans = (ans * a) ;
        }
        a = (a * a);
        b = b>>1;
    }
    
    return ans;
}  

// Recursive function to compute the digit sum for the range ending at R
ll computeDigitSumRecursive(int index, bool isTight, string& maxString, ll& maxNumber) {
    int length = maxString.length();

    // Base case: If all digits have been processed
    if (index >= length) return 0ll;

    ll digitSum = 0;
    // Determine the maximum digit we can use for this position
    int maxDigit = (isTight ? (maxString[index] - '0') : 9);

    // Calculate the power of 10 corresponding to the current position
    // ll powerOfTen = power(10, length - (index + 1)) + 0.1; //Using my own power() function
    ll powerOfTen = pow(10, length - (index + 1)) + 0.1; // Using C++ pow() function with +0.1 as correction for working with integers
    for (int digit = 0; digit <= maxDigit; digit++) {
        bool newTight = (digit == maxDigit && isTight);
        ll partialSum = computeDigitSumRecursive(index + 1, newTight, maxString, maxNumber);
        ll contribution = 0ll;
        if (newTight) {
            contribution = (maxNumber % powerOfTen) + 1;
        } else {
            contribution = powerOfTen;
        }
        digitSum += partialSum + (contribution * digit);
    }

    return digitSum;
}

// Memoized version of the above function
ll computeDigitSumMemoized(int index, bool isTight, string& maxString, ll& maxNumber, vector<vector<ll>>& dp) {
    int length = maxString.length();

    // Base case: If all digits have been processed
    if (index >= length) return 0ll;

    // If the result is already computed, return it from the dp table
    if (dp[index][isTight] != -1) {
        return dp[index][isTight];
    }

    ll digitSum = 0;
    // Determine the maximum digit we can use for this position
    int maxDigit = (isTight ? (maxString[index] - '0') : 9);

    // Calculate the power of 10 corresponding to the current position
    // ll powerOfTen = power(10, length - (index + 1)) + 0.1; //Using my own power() function
    ll powerOfTen = pow(10, length - (index + 1)) + 0.1; // Using C++ pow() function with +0.1 as correction for working with integers
    for (int digit = 0; digit <= maxDigit; digit++) {
        bool newTight = (digit == maxDigit && isTight);
        ll partialSum = computeDigitSumMemoized(index + 1, newTight, maxString, maxNumber, dp);
        ll contribution = 0ll;
        if (newTight) {
            contribution = (maxNumber % powerOfTen) + 1;
        } else {
            contribution = powerOfTen;
        }
        digitSum += partialSum + (contribution * digit);
    }

    // Store the computed result in the dp table
    dp[index][isTight] = digitSum;
    return dp[index][isTight];
}

// Function to calculate the digit sum for a given range [low, high]
ll solve() {
    ll low, high; 
    cin >> low >> high;
    low = low - 1; // Adjusting the lower bound

    string highString = to_string(high);
    
    // Initialize dp table with -1 for memoization
    vector<vector<ll>> dp(highString.length(), vector<ll>(2, -1));
    ll sumUpToHigh = computeDigitSumMemoized(0, true, highString, high, dp);

    ll result = sumUpToHigh;
    if (low >= 0) {
        string lowString = to_string(low);

        vector<vector<ll>> dp2(highString.length(), vector<ll>(2, -1));
        ll sumUpToLow = computeDigitSumMemoized(0, true, lowString, low, dp2);
        result = result - sumUpToLow;
    }

    return result;
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int tc; 
    cin >> tc;
    while (tc--) {
        cout << solve() << endl;
    }
}
