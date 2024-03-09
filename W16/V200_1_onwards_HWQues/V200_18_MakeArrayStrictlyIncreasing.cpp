#include<bits/stdc++.h>
using namespace std;

/*******/

int solveUsingRE(vector<int>& arr1, vector<int>& arr2, int prevEle, int curr){
    //BC
    if(curr >= arr1.size()) return 0;

    int minReplacements = INT_MAX;

    int option1 = INT_MAX;
    if(prevEle < arr1[curr]){
        //OPtion 1 : simply move ahead without any replacemennts!
        int REAns = solveUsingRE(arr1, arr2, arr1[curr], curr + 1);
        option1 = REAns != -1 ? 0 + REAns : INT_MAX; 
    }

    //Option 2 : Replace current
    int option2 = INT_MAX;
    int justBigger = upper_bound(arr2.begin(), arr2.end(), prevEle) - arr2.begin(); //index of element just bigger thn prevEle in arr2[]
    if(justBigger < arr2.size()){
        // arr1[curr] = arr2[justBigger]; //We will not modify the original array, just pass "arr2[justBigger]" as "prevEle" to RE Call

        int REAns = solveUsingRE(arr1, arr2, arr2[justBigger], curr + 1);
        option2 = REAns != -1 ? 1 + REAns : INT_MAX; 
    }

    minReplacements = min(option1, option2);

    return minReplacements == INT_MAX ? -1 : minReplacements;
}

int solveUsingMem(vector<int>& arr1, vector<int>& arr2, int prevEle, int curr, map<pair<int, int>, int>& dp){
    //BC
    if(curr >= arr1.size()) return 0;

    auto iterator = dp.find({prevEle, curr});
    if(iterator != dp.end()){
        return iterator->second; //iterator->first holds the key & iterator->second holds the value!
    }

    int minReplacements = INT_MAX;

    int option1 = INT_MAX;
    if(prevEle < arr1[curr]){
        //OPtion 1 : simply move ahead without any replacemennts!
        int REAns = solveUsingMem(arr1, arr2, arr1[curr], curr + 1, dp);
        option1 = REAns != -1 ? 0 + REAns : INT_MAX; 
    }

    //Option 2 : Replace current
    int option2 = INT_MAX;
    int justBigger = upper_bound(arr2.begin(), arr2.end(), prevEle) - arr2.begin(); //index of element just bigger thn prevEle in arr2[]
    if(justBigger < arr2.size()){
        // arr1[curr] = arr2[justBigger]; //We will not modify the original array, just pass "arr2[justBigger]" as "prevEle" to RE Call

        int REAns = solveUsingMem(arr1, arr2, arr2[justBigger], curr + 1, dp);
        option2 = REAns != -1 ? 1 + REAns : INT_MAX; 
    }

    minReplacements = min(option1, option2);
    dp[{prevEle, curr}] = minReplacements == INT_MAX ? -1 : minReplacements;

    return dp[{prevEle, curr}];
}

int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    int minReplacements = 0;

    sort(arr2.begin(), arr2.end());

    //Using Plain RE
    // int prevEle = -1; //prev is Not the index but the number itself
    // //We can initialise "prevEle" with -1 bcz ATQ : [ 0 <= arr1[i], arr2[i] <= 10^9 ]; so -1 is guaranteed to be less than any value of arr1
    // int curr = 0; //"curr" is the index
    // minReplacements = solveUsingRE(arr1, arr2, prevEle, curr);

    //Mem
    int prevEle = -1; //prev is Not the index but the number itself
    //We can initialise "prevEle" with -1 bcz ATQ : [ 0 <= arr1[i], arr2[i] <= 10^9 ]; so -1 is guaranteed to be less than any value of arr1
    int curr = 0; //"curr" is the index
    map<pair<int, int>, int> dp; //{prevEle, curr} ---> minReplacements for this pair
    minReplacements = solveUsingMem(arr1, arr2, prevEle, curr, dp);

    //Tab
    //Because my code is using "prevEle" which is actual element of the "arr1[]" array and not it's index. So, ATQ, "prevEle" can range from 0 to 10^9. I will not be willing to make such a big vector, so I used a std::map as my DP, but the disadvantage of this is that I cannot write the tabulation solution with the map DP. However, if I had used a vector, I could have written the tabulation solution but 10^9 is a huge number, so maybe that tabulation solution would not perform very well.


    return minReplacements;
}

int main(){
   
return 0;
}