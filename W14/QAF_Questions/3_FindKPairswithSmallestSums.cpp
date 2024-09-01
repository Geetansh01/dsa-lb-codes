#include<bits/stdc++.h>
using namespace std;

//M1 : using pattern of "L189 : 1)Merge K Sorted Arrays" 
//TC: O(k logk) {1 <= k <= m*n}; m = nums1.length, n = nums2.length
/*
    Ref for soln/ explanation:
    See this reply ("https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/84551/simple-java-o-klogk-solution-with-explanation/comments/232946") in this post ("https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/84551/simple-java-o-klogk-solution-with-explanation")
*/

//M2 (Same TC as M1)
//Ref for soln: https://youtu.be/PiGYS7BbV_Q?si=acX2KYcAa8FLQV1R
class Info{
    public:
        int Aidx;
        int Bidx;

        Info(int a, int b){
            Aidx = a;
            Bidx = b;
        }
};

class Compare{
    public:
        vector<int>& A;
        vector<int>& B;

        Compare(vector<int>& a, vector<int>& b) : A(a), B(b) {}

        bool operator () (Info& lhs, Info& rhs){
            int suma = A[lhs.Aidx] + B[lhs.Bidx];
            int sumb =  A[rhs.Aidx] + B[rhs.Bidx];
            return suma > sumb;
        }        
};

typedef pair<int, int> p;

vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
    vector<vector<int>> ans;
    int lenA = A.size();
    int lenB = B.size();

    //Yes, below syntax to initialise the minH is a bit tricky  :p. Ask chatGpt to explain it. 
    //Basically I needed A[] and B[] in the "Compare" class to be able to find the sum as i am storing indexes in "minH" ("Info" object carries the indexes from A[] and B[])
    //Want to avoid it? Store the sum itself in the minH along with the indexes like : {sum, {index from A[], index from B[]}}. Then inside the Compare class, use the "sum" for comparison
    priority_queue<Info, vector<Info>, Compare> minH ((Compare(A, B))); //Note the extra brackets around "Compare(A, B)", these are IMPORTANT (Otherwise U might be dealing with strange error msgs :p). 
    // These help clarify to the compiler that you are making an object of class "Compare" rather than calling a function! (Src: ChatGPT, Topic: Most vexing parse in C++)
    map<p, bool> visited; 
    
    Info temp(0, 0);
    minH.push(temp);
    visited[{0, 0}] = true;

    while(k > 0 && !minH.empty()){
        Info minSumPair = minH.top();
        minH.pop();
        int a_index = minSumPair.Aidx;
        int b_index = minSumPair.Bidx;

        ans.push_back({A[a_index], B[b_index]});
        k--;

        if(a_index + 1 < lenA){
            if(visited.find({a_index + 1, b_index}) == visited.end()){
                Info temp(a_index + 1, b_index);
                minH.push(temp);
                visited[{a_index + 1, b_index}] = true;
            }
        }

        if(b_index + 1 < lenB){
            if(visited.find({a_index, b_index + 1}) == visited.end()){
                Info temp(a_index, b_index + 1);
                minH.push(temp);
                visited[{a_index, b_index + 1}] = true;
            }
        }
    }
    return ans;
}

int main(){

return 0;
}