#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/****Maximum Height by Stacking Cuboids [LeetCode : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/]******/

//If trying on LeetCode : either define this cc outside of "Solution" class or make it "static" inside!
bool cc(vector<int>& a, vector<int>& b){
    //Jis cuboid ki volume zyada vo pehle
    return ((a[0]*a[1]*a[2]) > (b[0]*b[1]*b[2]));
}

bool check(vector<int>& curr, vector<int>& prev){
    //returns True or False for whether "curr" cuboid can be placed on top of "prev" cuboid
    if((curr[0] <= prev[0]) && (curr[1] <= prev[1]) && (curr[2] <= prev[2])){
        return true;
    }
    else{
        return false;
    }
}

//Below Code copied from "Longest Increasing Subsequence [LeetCode : https://leetcode.com/problems/longest-increasing-subsequence/description/]"
//Ques : Jaise "LISq" me BS se kiya tha yahan bhi hoga kya?
//Ans : No, Vaha Lisq bna re the jo sorted thi to current no se just bda no BS se nikal liya tha but box se just bda box to BS se nhi aega so Nope! 
int solveUsingTabSO(vector<vector<int>>& cuboids){
    int n = cuboids.size();
    // vector<vector<int> > dp(n+1, vector<int>(n+1, 0)); //row x col :: curr x prev
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    //Fill initial data : done by initializing entire dp with 0 (Vaise to khali last row (i.e row = nums.size()) me 0 bharna tha)

    for(int curr_index = n-1; curr_index >= 0; curr_index--){
        //RE+Mem me "prev" worst case me "curr" se just piche ho skta hai but can never be equal to or ahead of it!
        for(int prev_index = curr_index - 1; prev_index >= -1; prev_index--){
            int include = 0;
            if(prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index])){
                int height2Add = cuboids[curr_index][2];  //"curr" cuboid included to uski height include kro i.e "cuboids[curr_index[2]]"
                include = height2Add + nextRow[curr_index+1]; 
            }
            int exclude = 0 + nextRow[prev_index+1];
            currRow[prev_index+1] = max(include, exclude);
        }

        //Update nextRow
        nextRow = currRow;
    }

    return nextRow[0];
}


int maxHeight(vector<vector<int>>& cuboids) {
    /*
        1)Pehle sare cuboids ko same way me orient krlo with max dimension as the height (as hme stacking me max height achieve krni hai)
        2)For this, std::sort each cuboid jisse max dimension will go on cuboid[2] i.e last index i.e height
    */
    //____________(Line 1)
    //"auto&" bcz copy nhi actual cuboid ko sort krna hai
    for(auto& cuboid : cuboids){
        sort(cuboid.begin(), cuboid.end());
    }

    //____________(Line 2)
    //Also sare cuboids ko bhi sort kr do to pick the BETTER BET boxes first
    //You can also use your custom comparator "cc" (Defined Above) if you want to compare via volumes
    sort(cuboids.begin(), cuboids.end(), greater<vector<int>>() );

    int ans = solveUsingTabSO(cuboids);
    return ans;
}

int main(){
   
return 0;
}