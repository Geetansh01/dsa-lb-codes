#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*************************Q 66 : PRATA SPOJ[SPOJ : https://www.spoj.com/problems/PRATA/]*************************************/
bool check(vector<int>& ranks, int testValue, int Preq){
    int n = ranks.size();
    int Pmade = 0;

    for(int i = 0; i < n; i++){
        int result = testValue;
        int time = ranks[i];
        while(result > 0){
            result = result - time;
            if(result >= 0){
                Pmade++;
            }
            time = time + ranks[i];
        }
    }

    if(Pmade >= Preq){
        return true;
    }
    else{
        return false;
    }
}

int minTime(vector<int>& ranks, int cooks, int Preq){
    //Finding the best available cook
    int max = *max_element(ranks.begin(), ranks.end());
    int ans = -1;
    int s = 0;
    int e = (double(Preq) / 2) * ((2 * max) + ((Preq - 1) * max)); //Formula for sum of n(Preq) terms of AP
    /*
        1)why did i explicitly typecast "Preq" from "int" to "double?" :
            Because it involved integer division when calculating (Preq/2), which rounded down "Preq" to the nearest even integer when "Preq" was odd,
            leading to inaccurate results for the sum of the first "Preq" terms of an arithmetic progression (AP).
            The solution implemented here involves casting "Preq" to a double (double(Preq)) before performing division,
            ensuring that the division is done with floating-point precision and avoiding truncation issues.

        2)Another method u can use without needing to typecast explicitly : 
            U can utilizes a well-known formula for the sum of integers from 1 to Preq,
            (Preq * (Preq + 1) / 2), which doesn't suffer from integer division issues and accurately calculates
            the sum of the first Preq terms of the AP.

            --------> int e = max * (Preq * (Preq + 1) / 2);
    */
    int mid = s + (e-s)/2;

    while(s <= e){
        if(check(ranks, mid, Preq)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> answers;
    int testCases = 0;
    cin>>testCases;
    while(testCases--){
        int Preq;
        int cooks;
        vector<int> ranks;
        cin>>Preq>>cooks;
        for(int i = 0; i < cooks; i++){
            int temp = 0;
            cin>>temp;
            ranks.push_back(temp);
        }
        answers.push_back(minTime(ranks, cooks, Preq));
    }

    //Printing the answers
    for(auto iter : answers){
        cout<<iter<<endl;
    }

/*
Input this :
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1 

Expected output:
12
36
1

*/

return 0;
}