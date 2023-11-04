#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;

    //converting to string to minutes
    for(int i = 0; i < timePoints.size(); i++){
        int hrs = stoi(timePoints[i].substr(0, 2));
        int mins = stoi(timePoints[i].substr(3, 2));
        int totmins = 60*hrs + mins;
        minutes.push_back(totmins);
    }

    //sort minutes
    /*
    This sort has 2 roles to play:
    1) Obvious : to reduce complexity to O(N logN)
    2) Not Obvious : Note that time is circular, the difference between "03:00" and "16:00" can be 660 minutes or 780 minutes. 
       But we will always calculate it to be 780 minutes (which is wrong as we should calculate 660) unless "03:00" and "16:00" comprise of 1st and last 
       term respectively. If they are not 1st and last term respectively then sort takes care that some apt values are present as 1st and last term 
       (like "00:00" and "23:59") so that even the wrong calc of 780 minutes is overshadowed 
       (for eg, difference between "00:00" and "23:59" is 1min ---> calculation for 1st and last term is calculated correctly as it is separately 
       handled in the end).
    */

    sort(minutes.begin(), minutes.end());

    //finding minimum difference
    int minimum = INT_MAX;
    int n = minutes.size();
    for(int i = 0; i < n-1; i++){
        int diff = minutes[i+1] - minutes[i];
        minimum = min(diff, minimum); 
    }

    //Time is circular, compare end with first
    int newdiff = (minutes[0]+1440) - minutes[n-1];
    minimum = min(minimum, newdiff); 

    return minimum;

}

int main(){
   vector<string> timePoints = {"23:59","00:00"};
   cout<<findMinDifference(timePoints);

   return 0;
}
