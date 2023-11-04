#include<iostream>
#include<limits.h>
using namespace std;

//Finding max element in array with RE
void findMax(int arr[], int n, int i, int& maxi){
    //Base Case
    if(i >= n){
        //Array khtm hogya vaps aa jao
        return;
    }

    //1 case solve krna hai
    //Just currnet element check kro vo max hai kya?
    if(arr[i] > maxi){
        maxi = arr[i];
    }

    //Baki recursion sambhal lega
    findMax(arr, n, i+1, maxi);
}

//Finding min element in array with RE
void findMin(int arr[], int n, int i, int& mini){
    //Base Case
    if(i >= n){
        //Array khtm hogya vaps aa jao
        return;
    }

    //1 case solve krna hai
    //Just currnet element check kro vo min hai kya?
    if(arr[i] < mini){
        mini = arr[i];
    }

    //Baki recursion sambhal lega
    findMin(arr, n, i+1, mini);
}

int main(){
   int arr[] = {1,2,0,3,60,4,5};
   int n = 7;
   int i = 0;

   int maxi = INT_MIN;
   findMax(arr, n, i, maxi);

   int mini = INT_MAX;
   findMin(arr, n, i, mini);

   cout<<"Max Number:"<<maxi<<endl;
   cout<<"Mini Number:"<<mini<<endl;
return 0;
}