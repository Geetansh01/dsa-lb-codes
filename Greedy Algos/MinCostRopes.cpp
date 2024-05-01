#include <iostream>
#include <queue>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> minH;
    
    for(int i = 0; i < n; i++){
        minH.push(arr[i]);
    }

    long long TotCost = 0;
    while(minH.size() >= 2){
        long a = minH.top();
        minH.pop();
        long b = minH.top();
        minH.pop();

        TotCost += a+b;

        long sum = a + b;
        minH.push(sum);
    }

    return TotCost;
}

int main()
{
    long long arr[] = {4, 3, 2, 6};
    long long n = 4;
    long long ans = minCost(arr, n);
    cout<<ans;
    return 0;
}