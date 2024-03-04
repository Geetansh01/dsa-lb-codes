#include<bits/stdc++.h>
using namespace std;


//Plain RE 1 : with BC which is easy to understand but relatively difficult to implement in Tabulation
//MORAL OF STORY : Try to write simple Base Cases
bool solveUsingRE(string& s1, string& s2, string& s3, int ptr1, int ptr2, int ptr3){
    //BC : if ptr3 goes out of bound (i.e whole s3 matched)
    if(ptr3 >= s3.length()){
        if(ptr1 >= s1.length() && ptr2 >= s2.length()){
            return true;
        }
        else{
            return false;
        }
    }

    if(ptr1 < s1.length() && s1[ptr1] == s3[ptr3]){
        //try ptr1
        bool tryPtr1 = solveUsingRE(s1, s2, s3, ptr1 + 1, ptr2, ptr3 + 1);
        if(tryPtr1 == true){
            return true;
        }
    }
    if(ptr2 < s2.length() && s2[ptr2] == s3[ptr3]){
        //try ptr2 if ptr1 failed
        bool tryPtr2 = solveUsingRE(s1, s2, s3, ptr1, ptr2 + 1, ptr3 + 1);
        if(tryPtr2 == true){
            return true;
        }
    }

    //If both failed then return false
    return false;
}

//Plain RE 2 : with BC which is relatively easy to implement in Tabulation
bool solveUsingRE2(string& s1, string& s2, string& s3, int ptr1, int ptr2, int ptr3){
    //BC : if ptr3 goes out of bound (i.e whole s3 matched)
    if(ptr3 >= s3.length() && ptr1 >= s1.length() && ptr2 >= s2.length()) return true;

    bool ans = false;
    if(ptr1 < s1.length() && s1[ptr1] == s3[ptr3]){
        //try ptr1
        bool tryPtr1 = solveUsingRE(s1, s2, s3, ptr1 + 1, ptr2, ptr3 + 1);
        ans = ans || tryPtr1;
    }
    if(ptr2 < s2.length() && s2[ptr2] == s3[ptr3]){
        //try ptr2 if ptr1 failed
        bool tryPtr2 = solveUsingRE(s1, s2, s3, ptr1, ptr2 + 1, ptr3 + 1);
        ans = ans || tryPtr2;
    }

    //If both failed then return false
    return ans;
}

bool solveUsingMem(string& s1, string& s2, string& s3, int ptr1, int ptr2, int ptr3, vector<vector<vector<int> > >& dp){
    //BC : if ptr3 goes out of bound (i.e whole s3 matched)
    if(ptr3 >= s3.length()){
        if(ptr1 >= s1.length() && ptr2 >= s2.length()){
            return true;
        }
        else{
            return false;
        }
    }

    if(dp[ptr1][ptr2][ptr3] != -1){
        return dp[ptr1][ptr2][ptr3];
    }

    if(ptr1 < s1.length() && s1[ptr1] == s3[ptr3]){
        //try ptr1
        bool tryPtr1 = solveUsingMem(s1, s2, s3, ptr1 + 1, ptr2, ptr3 + 1, dp);
        if(tryPtr1 == true){
            dp[ptr1][ptr2][ptr3] = true;
            return dp[ptr1][ptr2][ptr3];
        }
    }
    if(ptr2 < s2.length() && s2[ptr2] == s3[ptr3]){
        //try ptr2 if ptr1 failed
        bool tryPtr2 = solveUsingMem(s1, s2, s3, ptr1, ptr2 + 1, ptr3 + 1, dp);
        if(tryPtr2 == true){
            dp[ptr1][ptr2][ptr3] = true;
            return dp[ptr1][ptr2][ptr3];
        }
    }

    //If both failed then return false
    dp[ptr1][ptr2][ptr3] = false;
    return dp[ptr1][ptr2][ptr3] ;
}

//Tabulation for Plain RE 1
bool solveUsingTab(string s1, string s2, string s3){
    vector<vector<vector<int> > > dp(s1.length() + 1, vector<vector<int> >(s2.length() + 1, vector<int>(s3.length() + 1, -1))); //a x b x c :: ptr1 x ptr2 x ptr3

    //Fill Initial Data
    for(int ptr1_i = 0; ptr1_i <= s1.length(); ptr1_i++){
        auto& temp = dp[ptr1_i];

        for(int ptr2_i = 0; ptr2_i <= s2.length(); ptr2_i++){
            for(int ptr3_i = 0; ptr3_i <= s3.length(); ptr3_i++){

                if(ptr3_i >= s3.length()){
                    if(ptr1_i >= s1.length() && ptr2_i >= s2.length()){
                        temp[ptr2_i][ptr3_i] = 1;
                    }
                    else{
                        temp[ptr2_i][ptr3_i] = 0;
                    }
                }

            }
        }
    }

    //Fill rest of dp
    for(int ptr1_i = s1.length(); ptr1_i >= 0; ptr1_i--){
        auto& temp = dp[ptr1_i];

        for(int ptr2_i = s2.length(); ptr2_i >= 0; ptr2_i--){
            for(int ptr3_i = s3.length(); ptr3_i >= 0; ptr3_i--){

                if(temp[ptr2_i][ptr3_i] != -1) continue; //Answer already stored in "Fill initial data" step

                bool ansFound = false;
                if(ptr1_i < s1.length() && s1[ptr1_i] == s3[ptr3_i]){
                    //try ptr1
                    bool tryPtr1 = dp[ptr1_i + 1][ptr2_i][ptr3_i + 1];
                    if(tryPtr1 == true){
                        dp[ptr1_i][ptr2_i][ptr3_i] = true;
                        ansFound = true;
                    }
                }
                if(!ansFound && ptr2_i < s2.length() && s2[ptr2_i] == s3[ptr3_i]){
                    //try ptr2 if ptr1 failed
                    bool tryPtr2 = dp[ptr1_i][ptr2_i + 1][ptr3_i + 1];
                    if(tryPtr2 == true){
                        dp[ptr1_i][ptr2_i][ptr3_i] = true;
                        ansFound = true;
                    }
                }

                //If both failed then return false
                if(!ansFound){
                    dp[ptr1_i][ptr2_i][ptr3_i] = false;
                }
            }
        }
    }

    return dp[0][0][0];
}

//Tabulation for Plain RE 2
bool solveUsingTab2(string s1, string s2, string s3){
    vector<vector<vector<int> > > dp(s1.length() + 1, vector<vector<int> >(s2.length() + 1, vector<int>(s3.length() + 1, -1))); //a x b x c :: ptr1 x ptr2 x ptr3

    //Fill Initial Data
    dp[s1.length()][s2.length()][s3.length()] = true;

    //Fill rest of dp
    for(int ptr1_i = s1.length(); ptr1_i >= 0; ptr1_i--){
        auto& temp = dp[ptr1_i];

        for(int ptr2_i = s2.length(); ptr2_i >= 0; ptr2_i--){
            for(int ptr3_i = s3.length(); ptr3_i >= 0; ptr3_i--){

                if(temp[ptr2_i][ptr3_i] != -1) continue; //Answer already stored in "Fill initial data" step

                bool ans = false;
                if(ptr1_i < s1.length() && s1[ptr1_i] == s3[ptr3_i]){
                    //try ptr1
                    bool tryPtr1 = dp[ptr1_i + 1][ptr2_i][ptr3_i + 1];
                    ans = ans || tryPtr1;
                }
                if(ptr2_i < s2.length() && s2[ptr2_i] == s3[ptr3_i]){
                    //try ptr2 if ptr1 failed
                    bool tryPtr2 = dp[ptr1_i][ptr2_i + 1][ptr3_i + 1];
                    ans = ans || tryPtr2;
                }

                //If both failed then return false
                dp[ptr1_i][ptr2_i][ptr3_i] = ans;
            }
        }
    }

    return dp[0][0][0];
}

bool isInterleave(string s1, string s2, string s3) {
    bool isInterleave = false;

    //Plain RE 1
    // int ptr1 = 0;
    // int ptr2 = 0;
    // int ptr3 = 0;
    // isInterleave = solveUsingRE(s1, s2, s3, ptr1, ptr2, ptr3);

    //Plain RE 2
    // int ptr1 = 0;
    // int ptr2 = 0;
    // int ptr3 = 0;
    // isInterleave = solveUsingRE2(s1, s2, s3, ptr1, ptr2, ptr3);

    //Mem [Although same TC as Tabulation, it runs faster-15ms while Tabulation goes 130+ms bcz many unnecessary comparisons are made in 3d dp bottom-up approach i guess!]
    int ptr1 = 0;
    int ptr2 = 0;
    int ptr3 = 0;
    vector<vector<vector<int> > > dp(s1.length() + 1, vector<vector<int> >(s2.length() + 1, vector<int>(s3.length() + 1, -1))); //a x b x c :: ptr1 x ptr2 x ptr3
    isInterleave = solveUsingMem(s1, s2, s3, ptr1, ptr2, ptr3, dp);

    //Tabulation
    // int ptr1 = 0;
    // int ptr2 = 0;
    // int ptr3 = 0;
    // isInterleave = solveUsingTab(s1, s2, s3);

    //Tabulation 2
    // int ptr1 = 0;
    // int ptr2 = 0;
    // int ptr3 = 0;
    // isInterleave = solveUsingTab2(s1, s2, s3);

    return isInterleave;
}

int main(){
   
return 0;
}