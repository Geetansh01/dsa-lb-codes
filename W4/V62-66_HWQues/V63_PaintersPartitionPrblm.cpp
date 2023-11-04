#include<iostream>
#include<numeric>
using namespace std;

/*****************Q 63 : Painters Partition Problem[GFG : https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1]********************************************************/
//Very Very Similar to "Q 62 : Book Allocation Problem"
/*Ques:
Dilpreet wants to paint his dog's home that has n boards with different lengths.
The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, 
say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.
*/

//Predicate Function
bool check(int arr[], int n, int k, long long testValue){
    long long sum = 0;
    long long i = 0;
    
    while(k > 0){
        sum = 0;
        while(i<n && sum <= testValue){
            sum = sum + arr[i];
            i++;   
        }
        k--;
        i--;
    }
    
    if(sum > testValue){
        return false;
    }
    else{
        return true;
    }
}

long long minTime(int arr[], int n, int k)
{
    long long sum = accumulate(arr, arr + n, 0LL);
    /*
    Caution :
    Use "0LL" to specify that accumulate works with "long long" values otherwise accumulate will work with "int" and overflow will happen.
    This overflowed wrong value will then be stored in "long long sum". 

    */
    long long ans = 0;
    long long s = 0;
    long long e = sum;
    long long mid = s + (e-s)/2;
    while(s <= e){
        if(check(arr, n, k, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return mid;
}

int main(){
    int n = 5;
    int arr[] = {5,10,30,20,15};
    int k = 3;
    cout<<minTime(arr, n, k)<<endl;

return 0;
}