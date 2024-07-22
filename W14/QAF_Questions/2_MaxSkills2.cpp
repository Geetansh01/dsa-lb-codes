#include<bits/stdc++.h>
using namespace std;


// Hint: From those problems that you can currently do, do the one with the max gains.

// Solution uses: Sorting + Max Heap
// TC: O(N LogN ) ; N = number of problems given

class compare{
    public:
        bool operator () (vector<int>& a, vector<int>& b){
            return (a[1] < b[1]);
        }  
};

static bool cc(vector<int>& a, vector<int>& b){
    return (a[0] < b[0]);
}

int maximumSkill2(int skill, int n, int d, vector<vector<int>> &problems) {
    // code here
    //sort : least difficult -> most difficult
    sort(problems.begin(), problems.end(), cc);
    
    //Main thing: from those that you can do, do the one with most gains
    priority_queue<vector<int>, vector<vector<int>>, compare> maxH; //maxH has max gains wali prblm on top among those that are in the heap
    int i = 0;
    while(i < n){
        if(problems[i][0] <= skill){
            maxH.push(problems[i]);
            i++;
        }
        else{
            break;
        }
    }
    
    while(!maxH.empty() && d>0){
        vector<int> topPrblm = maxH.top();
        maxH.pop();
        d--;
        skill += topPrblm[1]; //upgrade skill
        
        //Push additional problems that you can do now with upgraded skill
        while(i<n){
            if(problems[i][0] <= skill){
                maxH.push(problems[i]);
                i++;
            }
            else{
                break;
            }
        }
    }
    
    return skill;
}


int main(){
   
return 0;
}