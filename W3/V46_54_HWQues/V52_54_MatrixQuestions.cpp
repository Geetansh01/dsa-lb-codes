#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// /*************************Q 52 : Wave Print A Matrix****************************************/
// void WavePrint(vector<vector<int>>& arr) {  
//     for (int col = 0; col < arr[0].size(); col++) {
//         //If col is EVEN, print Top to Bottom ("col & 1" equals 0 if col is EVEN)
//         if ((col & 1) == 0) {
//             for (int row = 0; row < arr.size(); row++) {
//                 cout << arr[row][col]<<" ";
//             }
//         } 

//         //If col is ODD, print Bottom to Top
//         else {
//             for (int row = arr.size() - 1; row >= 0; row--) {
//                 cout << arr[row][col]<<" ";
//             }
//         }
//     }
// }

// int main(){
//     vector<vector<int> > arr{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     WavePrint(arr);

// return 0;
// }

/*************************Q 53 : Spiral Print A Matrix [LeetCode : https://leetcode.com/problems/spiral-matrix/description/]****************************************/
// vector<int> SpiralPrint(vector<vector<int> >& vec){
//     int count = 0;
//     int row = vec.size();
//     int col = vec[0].size();

//     int StartingRow = 0;
//     int EndingCol = col - 1;
//     int EndingRow = row - 1;
//     int StartingCol = 0;

//     vector<int> ans;  

//     while(count < row * col){
        
//         //REMEMBER : " && (count < row*col) " ye condition bhule ga tu!

//         //Printing StartingRow
//         for(int i = StartingCol; (i <= EndingCol) && (count < row*col); i++){
//             ans.push_back(vec[StartingRow][i]);
//             count++;
//         }
//         StartingRow++;

//         //Printing EndingCol
//         for(int i = StartingRow; (i <= EndingRow) && (count < row*col); i++){
//             ans.push_back(vec[i][EndingCol]);
//             count++;
//         }
//         EndingCol--;

//         //Printing EndingRow
//         for(int i = EndingCol; (i >= StartingCol) && (count < row*col); i--){
//             ans.push_back(vec[EndingRow][i]);
//             count++;
//         }
//         EndingRow--;

//         //Printing StartingCol
//         for(int i = EndingRow; (i >= StartingRow) && (count < row*col); i--){
//             ans.push_back(vec[i][StartingCol]);
//             count++;
//         }
//         StartingCol++;
//     }
//     return ans;
// }

// int main(){
//     vector<vector<int> > arr{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     // vector<vector<int> > arr{{1,2,3,4}};
//     // vector<vector<int> > arr{{1}};
//     vector<int> ans;
//     ans = SpiralPrint(arr);
    
//     for(auto iter : ans){
//         cout<<iter<<" ";
//     }

// return 0;
// }



/*************************Q 54A : Add two numbers represented by two arrays [GFG : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-two-arrays2408/1] ****************************************/
// string calc_Sum(int *a,int n,int *b,int m){
//     string ans;
//     int i = n-1;
//     int j = m-1;
//     int carry = 0;
//     int digit = 0;
//     int sum = 0;
    
//     //Upuntil i and j are same
//     while(i>=0 && j>=0){
//         sum = a[i] + b[j] + carry;
//         digit = sum%10;
//         ans.push_back(digit + '0');
//         carry = sum/10;
//         i--;
//         j--;
//     }
    
//     //When a is longer than b (i exists but j is exhausted)
//     while(i>=0){
//         sum = a[i] + 0 + carry;
//         digit = sum%10;
//         ans.push_back(digit + '0');
//         carry = sum/10;
//         i--;
//     }
    
//     //When b is longer than a (j exists but i is exhausted)
//     while(j>=0){
//         sum = 0 + b[j] + carry;
//         digit = sum%10;
//         ans.push_back(digit + '0');
//         carry = sum/10;
//         j--;
//     }
    
//     //If carry holds non zero value 
//     if(carry){
//         ans.push_back(carry + '0');
//     }
    
//     //To remove leading zeros 
//     while( ans[ans.size()-1] == '0'){
//         ans.pop_back();
//     }
    
//     //To reverse ans (as the number is currently stored in opposite order)
//     reverse(ans.begin(), ans.end());
    
//     return ans;
// }

// int main(){
//     int a[] = {0,1,2,3,4};
//     int b[] = {1,2,3};
//     string ans = calc_Sum(a,5,b,3);

//     for(auto iter : ans){
//         cout<<iter;
//     }
// }


/*************************Q 54B : Factorials of large numbers [GFG : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1] ****************************************/
vector<int> LargeFactorial(int N){
    int mul = 0; //multiplication result
    int carry = 0;
    vector<int> ans;
    ans.push_back(1);
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < ans.size(); j++){
            mul = ans[j] * i + carry;
            ans[j] = mul%10;
            carry = mul / 10;
        }
        
        //Now add carry (one digit at a time) if it is greater than 0 
        while(carry){
            ans.push_back( carry%10 );
            carry = carry/10;
        }
        
    }
    
    //Now reverse "ans"
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}

int main(){
    vector<int> ans = LargeFactorial(50);
    for(auto iter : ans){
        cout<<iter;
    }
    cout<<endl<<"50! from Google : 30414093201713378043612608166064768844377641568960512000000000000"<<endl;
}
