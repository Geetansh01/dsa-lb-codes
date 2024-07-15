#include<iostream>
#include<vector>
using namespace std;

//For video soln, ref (I recommend you watch uptil "11:53" mark): https://youtu.be/o-YDQzHoaKM?feature=shared
//For written soln intuituion, ref: https://leetcode.com/problems/find-k-closest-elements/solutions/106426/java-c-python-binary-search-o-log-n-k-k

//TC: O(Log(N-K) + K); N = Size of array

//TC is not that impressive from the easier method in "V59-60_HWQues: 2) Q 60"
//What's important then? : New pattern/ way to apply BS: We will directly search for a window in the array [Rather than a value like in the usual BS]

//Concise Code
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    int start = 0;
    int end = n-k;
    int mid = start + (end-start)/2;
    while(start < end){
        if((x - arr[mid]) > (arr[mid+k] - x)){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }

    //Your answer lies in window: arr[mid] ~ arr[mid + k - 1]
    vector<int> ans;
    int i = mid;
    for(int i = mid; i < mid + k; i++){
        ans.push_back(arr[i]);
    }

    return ans;
}

//Same code as above, but using absolute values instead in the BS condition (Comparatively easier to understand but long code)
// vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//     int n = arr.size();
//     int start = 0;
//     int end = n-k;
//     int mid = start + (end-start)/2;
//     while(start < end){
//         if(abs(arr[mid] - x) > abs(arr[mid+k] - x)){
//             start = mid + 1;
//         }
//         else{
//             if(arr[mid] != arr[mid+k]){
//                 /*
//                     Need to move window to left. Why? Because Question states
//                         An integer a is closer to x than an integer b if: 
//                         1) |a - x| < |b - x|, or
//                         2) |a - x| == |b - x| and a < b

//                     Here, the 2nd condition makes us go left
//                 */
//                 end = mid;
//             }
//             else if(arr[mid] == arr[mid+k]){
//                 if(x < arr[mid]){
//                     //Need to go move window to left. 
//                     //This is because x lies to the left. So if a better window exists, it will be in the left
//                     end = mid;
//                 }
//                 else if(x > arr[mid]){
//                     //Need to go right.
//                     //This is because x lies to the right. So if a better window exists, it will be in the right

//                     start = mid + 1;
//                 }
//                 else{
//                     // Here, arr[mid] = x = arr[mid + k]
//                     // This is the best possible window as all elements in the window are equal to x ! 
//                     break; 
//                 }
//             }
//         }
//         mid = start + (end-start)/2;
//     }

//     //Your answer lies in window: arr[mid] ~ arr[mid + k - 1]
//     vector<int> ans;
//     int i = mid;
//     for(int i = mid; i < mid + k; i++){
//         ans.push_back(arr[i]);
//     }

//     return ans;
// }

int main(){
   
return 0;
}