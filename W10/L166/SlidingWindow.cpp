#include<iostream>
#include<queue>
using namespace std;

/********Sliding Window [Interview] [Coding Ninjas : https://www.codingninjas.com/studio/problems/first-negative-integer-in-every-window-of-size-k_1164406?leftPanelTabValue=PROBLEM]*********/

//TC : O(n + k)
//SC : O(k)

vector<int> firstNegativeInteger(vector<int> &arr, int k, int n){
    queue<int> q;
    vector<int> ans;

    //Step 1 : Process first window of size k
    for(int i = 0; i < k; i++){
        if(arr[i] < 0){
            q.push(i);
        }
    }

    //Now Slide the window
    for(int i = k; i < n; i++){
        //Answer dedo purani window ka
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }
        
        //Out of window element ko remove krdo
        if((!q.empty()) &&  (i - q.front() >= k)){
            q.pop();
        }

        //check current elemetn for insertion
        if(arr[i] < 0){
            q.push(i);
        }
    }

    //Answer dedo last window ka
    if(q.empty()){
        ans.push_back(0);
    }
    else{
        ans.push_back(arr[q.front()]);
    }

    return ans;
}

int main(){
   vector<int> arr = {12,-1,-7,8,-15,30,16,28};
   int size = 8;

   int k = 3;
   vector<int> ans = firstNegativeInteger(arr, k, size);

   for(auto x : ans){
    cout<<x<<" ";
   }
return 0;
}