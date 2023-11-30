#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/***********[LeetCode : https://leetcode.com/problems/largest-rectangle-in-histogram/description/]****************/

    vector<int> nextSmallerElement(vector<int> &v){
        stack<int> st;
        st.push(v.size());
        vector<int> ans(v.size());

        for (int i = v.size() - 1; i >= 0; i--){

            int curr = v[i];
            while (st.top() != v.size() && v[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &v){
        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size());
        for (int i = 0; i < v.size(); i++){

            int curr = v[i];
            while (st.top() != -1 && v[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        //Step1 : prev Smaller array 
        vector<int> prevSmaller = prevSmallerElement(heights);

        //Step2 : next smaller array
        vector<int> nextSmaller = nextSmallerElement(heights);

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int length = heights[i];
            int width = nextSmaller[i] - prevSmaller[i] -1;

            int area = length * width;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

int main(){
   vector<int> v;
   v.push_back(2);
   v.push_back(1);
   v.push_back(5);
   v.push_back(6);
   v.push_back(2);
   v.push_back(3);

   cout<<largestRectangleArea(v)<<endl;
return 0;
}