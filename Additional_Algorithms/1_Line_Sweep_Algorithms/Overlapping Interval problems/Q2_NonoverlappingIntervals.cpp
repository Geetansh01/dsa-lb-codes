#include<bits/stdc++.h>
using namespace std;

//TC: O(n)
static bool cc(vector<int>& A, vector<int>& B){
    return (A[0] < B[0]);
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cc);
    int count = 0;
    int end = -1;
    bool NoEnd = true;

    for(int interval = 0; interval < intervals.size(); interval++){
        int intervalS = intervals[interval][0];
        int intervalE = intervals[interval][1];

        if(NoEnd){
            end = intervalE;
            NoEnd = false;
        }
        else if(intervalS < end){
            count++;
            end = min(end, intervalE);
        }
        else{
            end = intervalE;
            // NoEnd = false;
        }
    }
    return count;
}

int main(){

return 0;
}