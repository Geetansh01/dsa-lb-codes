#include<bits/stdc++.h>
using namespace std;

//M1 : Using Pure Line Sweep
//TC : O(N logN) ; N = no. of logs
//SC : O(X) ; X = number of different years in the logs
//Ex : Say Logs = [[2000, 2005]], then map would have only 2 entries for "2000" & "2005"
int maximumPopulation(vector<vector<int>>& logs) {
    map<int, int> timeLine; // year --> people alive (Not exactly, how many people are alive in the any year will be derived from sweeping The Line)
    for(auto& log : logs){
        timeLine[log[0]]++;
        timeLine[log[1]]--;
    }

    //Do a Line Sweep on the time line
    int ansYr = -1;
    int max_ppl = -1; //max people alive 
    int count = 0;  //people alive currently (in current year)
    for(auto& itr : timeLine){
        int currYear = itr.first;
        count += itr.second; //Now "count" has the no. of people alive in the current year
        if(count > max_ppl){
            max_ppl = count;
            ansYr = currYear;
        }
    }

    return ansYr;
}  

//M2 : Using Range Addition (see INDEX.txt for "Additional Algorithms: 2)Line Sweep Algorithm: 2)Using Range Addition")
//TC : O(n) (But SC would take a hit)
//SC : O(Y) ; Y = All the possible years, even those not in the logs
//Ex : Say the only logs as input can be: Logs = [[2000, 2005]], then an array with size 6 (for all years in [2000, 2005]) is needed. 
//Now since question has constraint "1950 <= birthi < deathi <= 2050" so an array of size 101 needs to be taken!

/*
    Note:
    1) Some questions of line sweep can also be done using range addition equivalents. 
    2) Sometimes, line sweep is used along with range addition.

    3) However, some questions are purely line sweep and do not involve range addition. 
    For example: Search for a pair of intersecting segments [Ref: https://cp-algorithms.com/geometry/intersecting_segments.html#search-for-a-pair-of-intersecting-segments]

    4) These two techniques are actually different, so I am not merging or confusing them into one. For what Range Addition is, see "Additional Algorithms: 2)Line Sweep Algorithm: 2)Using Range Addition"
*/

int main(){
    
return 0;
}