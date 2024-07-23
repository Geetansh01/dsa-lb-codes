#include<bits/stdc++.h>
using namespace std;


//M1: Using Line Sweep
//TC : O(n log n) ; n = no of intervals

//M2: Using Min Heap
//TC : O(n log n) ; n = no of intervals


// Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

static bool cc(Interval& a, Interval& b){
    return (a.start < b.start);
}

int minMeetingRooms(vector<Interval> &intervals) {
    // Write your code here
    int n = intervals.size();

    if(n == 0) return 0;

    sort(intervals.begin(), intervals.end(), cc);
    priority_queue<int, vector<int>, greater<int>> minH;
    minH.push(intervals[0].end);

    int reqRooms = 1;
    for(int i = 1; i < n; i++){
        int currStart = intervals[i].start;
        if(currStart >= minH.top()){
            minH.pop();
        }
        else{
            reqRooms++;
        }
        minH.push(intervals[i].end);
    }
    return reqRooms;
}

int main(){
    
return 0;
}