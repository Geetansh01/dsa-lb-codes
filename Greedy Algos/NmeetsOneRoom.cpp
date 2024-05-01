#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
    Main logic : Greedy algorithm

    1)Greedily we will pick those meetings 1st that ends at the earliest. 

    2)So, Sort the meetings from smallest to largest according to their end time and start picking from the beginning. In this way we will be picking those meetings 1st which end earlier that is, with a less end time.

    3)Note that you might want to think greedily in terms of duration. That is, You might think to pick those meetings 1st that have a less duration. But that won't work. See example in Notebook. 
*/

bool cc(pair<int, int>& A, pair<int, int>& B){
    return A.second < B.second; //So sorting on basis on END TIME of meeting
}

//Function to find the maximum number of meetings that can
//be performed in a meeting room.
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int> > time;
    for(int i = 0; i < n; i++){
        time.push_back({start[i], end[i]});
    }

    sort(time.begin(), time.end(), cc);

    int count = 1; //Initially room khali to 1st meeting pakka hogi
    int prevEnd = time[0].second; //END time of previous meeting

    for(int i = 1; i < n; i++){
        int currStart = time[i].first;
        int currEnd = time[i].second;

        if(currStart > prevEnd){
            //Current meeting krwa lo
            count++;
            prevEnd = currEnd;
        }
    }

    return count;
}

int main(){
   
return 0;
}