#include<bits/stdc++.h>
using namespace std;

//Using Pure Line Sweep
int numberOfPoints(vector<vector<int>>& nums) {
    //100 is the last possible point (Constraint in ques)
    vector<int> numberLine(101); // point --> No of cars parked on this point (Not exactly, we will do a line sweep for this)
    for(auto& s_e : nums){
        int start = s_e[0]; //Point where the car starts 
        numberLine[start]++;
        int end = s_e[1] + 1; //Point after the point where the car ends
        if(end <= 100){
            numberLine[end]--;
        }
    }

    //Do a Line Sweep on the number line (with a Prefix Sum / Cumulative Sum)
    int points = 0;
    int prefixSum = 0; //cumulative sum 
    for(int pt = 1; pt <= 100; pt++){
        prefixSum += numberLine[pt];
        if(prefixSum > 0) points++;
    }

    return points;
} 

int main(){
    
return 0;
}