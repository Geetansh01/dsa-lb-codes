#include<iostream>
using namespace std;

/***********************************Square Root using Binary Search***********************************************************/
int findSqrt(int n){
    //This function gives only int part of sqrt(n) when n is not a perfect square.
    int target = n;
    int s = 0;
    int e = n;
    int m = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(m*m == target){
            return m;
        }

        else if(m*m > target){
            //left part me search kro
            e = m-1;
        }

        else{
            //store ans
            ans = m;
            //right part me search kro
            s = m + 1;
        }

        m = s + (e-s)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    int ans = findSqrt(n);
    cout<<"Integer part of Sqrt of n is :"<<ans<<endl;

    int precision;
    cout<<"How many floating digits needed : ";
    cin>>precision;
    
    double step = 0.1;
    double finalAns = ans;
    for(int i = 0; i < precision; i++){
        double j = finalAns;

        while(j*j <= n){
            finalAns = j;
            j = j + step;
        }

        step = step/10;
    }

    cout<<"Fianl Answer : "<<finalAns<<endl;

return 0;
}