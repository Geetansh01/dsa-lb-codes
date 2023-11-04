#include<iostream>
#include<numeric>
using namespace std;

/*****************************Q 62 : Book Allocation Problem[GFG  https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1]******************************************************/
/*
Ques (the gfg website might have changed the lingo, below is the best way to state this question):
You are given an array ‘A[]’ of integer numbers. In this array, the ‘A[i]’ represents the number of pages in the ‘i-th’ book. There are ‘M’ number of students, and the task is to allocate all the books to the students. 

Allocate books in a way such that:
    Each student gets at least one book.
    Each book should be allocated to a student.
    Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘M’ students such that the maximum number of pages assigned to a student is minimum.
*/

//Predicate Function
bool check(int A[], int N, int M, int testValue){
    //M is the no of students
    //N is the no of books i.e size of array A
    int sum;
    int i = 0;
    while(M > 0){
        sum = 0;
        while(i<N && sum <= testValue){
            sum = sum + A[i];
            i++;
        }
        i--;
        M--;
    }

    if(sum > testValue){
        return false;
    }
    else{
        return true;
    }
}

int binarySearch(int A[], int s, int e, int N, int M){
    //M is the no of students
    //N is the no of books i.e size of array A
    int mid = s +(e-s)/2;
    int ans = 0;
    while(s <= e){
        if(check(A, N, M, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s +(e-s)/2;
    }
    return mid;
}

int findPages(int A[], int N, int M){
    //M is the no of students
    //N is the no of books i.e size of array A
    if(M > N){
        return -1;
    }
    else{
        int sum = accumulate(A, A+N, 0);
        //Alter : find sum yourself
        // int sum = 0;
        // for(int i = 0; i < N; i++){
        //     sum = sum + A[i];
        // }
        return binarySearch(A, 0, sum, N, M);
    }
}

int main(){
   int arr[] = {12,34,67,90};
   cout<<findPages(arr, 4, 2);
return 0;
}