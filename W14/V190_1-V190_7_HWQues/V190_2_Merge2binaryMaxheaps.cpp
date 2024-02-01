#include<iostream>
#include<vector>
using namespace std;

/***V190_2 : Merge two binary Max heaps [GFG : https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1]****/

//Note : this ques solved using 0-based indexing of heap 
//Notice the 3 changes for the same (compared to "L187 : HeapifyREArrToHeap" where 1 based indexing was used)

void heapify(vector<int> &c, int n, int index){
    while(true){
        int left = 2*index + 1;
        int right = 2*index + 2;
        int maxi = index;
        
        //Left Child
        
        //change 1 : "left < n"
        if(left < n && c[left] > c[maxi]){
            maxi = left;
        }
        //Right Child
        
        //change 2 : "right < n"
        if(right < n && c[right] > c[maxi]){
            maxi = right;
        }
        
        if(maxi == index){
            //correct position reached
            break;
        }
        else{
            swap(c[index], c[maxi]);
            index = maxi;
        }
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    //Step 1 : Merge "a" & "b" into new vector "c"
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    
    //Step 2 : use heapify() to make "c" into a max heap
    
    //change 3 : "i = (c.size()/2)-1" {Although "i = c.size()/2" would also work just fine}
    for(int i = (c.size()/2)-1; i >= 0; i--){
        heapify(c, c.size(), i);
    }
    
    return c;
}

int main(){
   
return 0;
}