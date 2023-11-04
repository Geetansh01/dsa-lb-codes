#include<iostream>
#include<vector>
#include<limits.h>
#include<numeric>
using namespace std;

/*****************Q 65 : EKO SPOJ [SPOJ : https://www.spoj.com/problems/EKO/cstart=80]******************************************************/

//Predicate Function
bool check(vector<long long> arr, long long rw, long long testValue, long long trees){
    long long ow = 0;
    for(long long i = 0; i < trees; i++){
        if(arr[i] >= testValue){
            ow = ow + (arr[i] - testValue);
        }
    }
    if(ow >= rw){
        return true;
    }
    else{
        return false;
    }
}

long long requiredHeight(vector<long long> arr, long long rw, long long trees){
    long long max = INT_MIN;
    for(long long i = 0; i < trees; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    long long ans = -1;
    long long s = 0;
    long long e = max;
    long long mid = s + (e - s)/2;
    while(s <= e){
        if(check(arr, rw, mid, trees)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int main(){
    long long trees;
    long long rw;
    vector<long long> treeheights;
    cin>>trees>>rw;
    for(long long i = 0; i < trees; i++){
        long long temp;
        cin>>temp;
        treeheights.push_back(temp);
    }
    cout<<requiredHeight(treeheights, rw, trees);
/*
You will have to give the input, give this : 
4 7
20 15 10 17
Output expected : 15
*/

return 0;
}