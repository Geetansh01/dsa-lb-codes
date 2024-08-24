#include<bits/stdc++.h>
using namespace std;

//TC: O(n)
static bool cc(vector<int>& A, vector<int>& B){
    return (A[0] < B[0]);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cc);
    vector<vector<int>> ans;
    vector<int> temp = {-1, -1};

    int end = -1;
    bool NoEnd = true;
    for(int interval = 0; interval < intervals.size(); interval++){
        int intervalS = intervals[interval][0];
        int intervalE = intervals[interval][1];

        if(NoEnd){
            temp[0] = intervalS;
            end = intervalE;
            NoEnd = false;
        }
        else if(intervalS > end){
            temp[1] = end;
            ans.push_back(temp);
            temp[0] = intervalS;
            end = intervalE;
        }
        else{
            end = max(end, intervalE);
        }
    }

    if(!NoEnd){
        temp[1] = end;
        ans.push_back(temp);
    }

    return ans;
}

int main(){

return 0;
}