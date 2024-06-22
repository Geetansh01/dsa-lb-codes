#include<iostream>
using namespace std;

//Merging two sorted arrays In-Place. 
//TC : O(log (n+m)) * O(n+m)
//SC : O(1)

void InPlaceMergeSortedArrays(int* A, int sA, int* B, int sB){
    int n = sA;
    int m = n + sB;
    int gap = (m)/2 + (m)%2;

    while(gap >= 1){
        int i = 0; 
        int j = i+gap;
        while(j < m){
            if(i < n){
                if(j < n){
                    if(A[i] > A[j]){
                        swap(A[i], A[j]);
                    }
                }
                else{
                    int tempj = j - n;
                    if(A[i] > B[tempj]){
                        swap(A[i], B[tempj]);
                    }
                }
            }
            else{
                int tempi = i-n;
                int tempj = j-n;
                if(B[tempi] > B[tempj]){
                    swap(B[tempi], B[tempj]);   
                }
            }

            i++; 
            j++;
        }
        
        if(gap == 1){
            return;
        }
        gap = (gap/2) + (gap%2);
    }

    return;
}

int main(){
    int ODD[] = {1,3,5,7};
    int sODD = 4;
    int EVEN[] = {2,4,6,7,8,8,8,10,12,14,16,18};
    int sEVEN = 12;

    InPlaceMergeSortedArrays(ODD, sODD, EVEN, sEVEN);

    cout<<"After in place Merging : "<<endl;
    for(int i = 0; i < sODD; i++){
        cout<<ODD[i]<<" ";
    }
    cout<<endl;
    for(int j = 0; j < sEVEN; j++){
        cout<<EVEN[j]<<" ";
    }


   
return 0;
}