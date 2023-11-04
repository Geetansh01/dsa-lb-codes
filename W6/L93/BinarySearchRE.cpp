#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int s, int e, int& key){
    //base case
    //Case1 : Key not found
    if(s > e){
        return -1;
    }
    //Case2 : Key Found
    //1 case hmne sambhal liya
    int mid = s + (e-s)/2;
    if(arr[mid] == key){
        return mid;
    }

    //Baki RE sambhalega
    if(arr[mid] < key){
        //Right part me search : s = mid + 1
        return binarySearch(arr, mid+1, e, key);
    }
    else{
        //Left part me search : e = mid - 1
        return binarySearch(arr, s, mid-1, key);
    }
}

int main(){
    vector<int> v{10,20,40,60,70,90,99};
    int target = 99;

    int n = v.size();
    int s = 0;
    int e = n-1;
    int ans = binarySearch(v,s,e,target);

    cout<<"Founfd at Index : "<<ans<<endl;

   
return 0;
}