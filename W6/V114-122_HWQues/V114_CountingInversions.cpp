#include <bits/stdc++.h>
using namespace std;

/***********Counting Inversions [Hackerrank : https://www.hackerrank.com/challenges/ctci-merge-sort/problem]*********************/

void mergeHelper(vector<int> &arr, int s, int e, long int &swaps){
    int mid = s+(e-s)/2;

    //Make Dynamic arrays
    int ls = mid-s+1;
    int rs = e-mid;
    int *left = new int[ls];
    int *right = new int[rs];
    
    //copy values
    int k = s;
    for(int i = 0; i < ls; i++){
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for(int j = 0; j < rs; j++){
        right[j] = arr[k];
        k++;
    }
    
    int i = 0; //left Dyn array pointer
    int j = 0; //right Dyn array pointer
    int c = s; //main array pointer
    
    while(i<ls && j<rs){
        if(left[i] <= right[j]){
            arr[c++]=left[i++];
        }
        
        else if(right[j] < left[i]){
            arr[c++]=right[j++];
            
            //THE ONLY LINE THAT MATTERS, BAKI TO MERGE SORT HAI
            swaps += ls-i;
        }
    }
    
    while(i < ls){
        arr[c++] = left[i++];
    }
    
    while(j < rs){
        arr[c++] = right[j++];
    }

    delete[] left;
    delete[] right;
    
}

void mergeSort(vector<int> &arr, int s, int e, long int &swaps){
    //Base Case
    if(s >= e){
        return;
    }
    
    int mid = s+(e-s)/2;
    //left array
    mergeSort(arr, s, mid, swaps);
    
    //right array
    mergeSort(arr, mid+1, e, swaps);
    
    //merge left and right
    mergeHelper(arr, s, e, swaps);
}

long countInversions(vector<int>& arr) {
    long int swaps = 0;
    int s = 0; int e = arr.size()-1;
    mergeSort(arr, s, e, swaps);
    return swaps;
}

int main(){
    vector<int> arr = {2,1,3,1,2};
    long int swaps = countInversions(arr);

    cout<<swaps<<endl;

    return 0;
}
