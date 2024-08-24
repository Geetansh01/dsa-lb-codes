#include<bits/stdc++.h>
using namespace std;

//TC : O(n)

typedef long long ll;
static bool cc(vector<int>& A, vector<int>& B){
    return A[0] < B[0];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cc);

    ll end = INT_MAX*1ll;
    int count = 0;
    bool NoEnd = true;

    for(int pt = 0; pt < points.size(); pt++){
        int ps = points[pt][0];
        int pe = points[pt][1];

        if(NoEnd){
            end = pe*1ll;
            NoEnd = false;
        }
        else if(ps > end){
            count++;
            end = pe*1ll;
        }
        else if(ps < end){
            end = min(end, 1ll*pe);
        }
        else{
            count++;
            NoEnd = true;
            while(pt < points.size() && points[pt][0] == end){
                pt++;
            }
            end = INT_MAX*1ll;
            pt--;
        }
    }

    if(!NoEnd) count++;
    return count;
}

int main(){

return 0;
}