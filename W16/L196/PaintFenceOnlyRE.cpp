#include<iostream>
using namespace std;

/****Painting the Fence [GFG : https://www.geeksforgeeks.org/problems/painting-the-fence3727/1]******/
//Note that GFG wants answer % (10^9 + 7)
//Below soln will give TLE

int getPaintWays(int n,int k){
    //Base Case
    if(n == 1){
        return k;
    }
    if(n == 2){
        int same = k;
        int diff = k*(k-1);
        return same + diff;
    }

    int same = (k-1) * getPaintWays(n-2, k);
    int diff = (k-1) * getPaintWays(n-1, k);
    return same + diff;
}

int main(){
   int n = 4;
   int k = 3;
   int ans = getPaintWays(n,k);
   cout<<ans<<endl;
return 0;
}