#include<iostream>
using namespace std;

/**************Max Sum without Adjacents[GFG : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1]****************************************/

/*
In "MaximumSumOfNonAdjacentElementsBETTER.cpp" , I am writing BETTER code 
For EASY version of the same code see "MaximumSumOfNonAdjacentElementsEASY.cpp"
*/

//Our solution will give TLE in current state (DP required)

//This function does the work and takes just 2 parameters
int findMax2(int* arr, int n){
    //Base Case
    if(n <= 0){
        return 0;
    }

    //Include Current Element
    int a = *(arr) + findMax2(arr+2, n-2);

    //Exclude Current Element
    int b = findMax2(arr+1, n-1);

    return max(a, b);
}


//This function takes an extra parameter "sum". This soln can not be submitted on GFG as GFG allows only 2 parameters.
int findMax1(int* arr, int n, int sum){
    //Base Case
    if(n <= 0){
        return sum;
    }

    //1 case i will solve
    //Include
    int a = findMax1(arr+2, n-2, sum+*arr);

    //Exclude
    int b = findMax1(arr+1, n-1, sum);

    return max(a, b);
}

int main(){
//    int arr[] = {1,2,3,4,5,6,7};
   int arr[] = {2,1,4,9};
   int s = sizeof(arr)/sizeof(arr[0]);
   int sum = 0; //Needed only for function " findMax1() "

   cout<<"Answer : "<<findMax2(arr, s)<<endl;
   cout<<"Answer : "<<findMax1(arr, s, sum)<<endl;
return 0;
}