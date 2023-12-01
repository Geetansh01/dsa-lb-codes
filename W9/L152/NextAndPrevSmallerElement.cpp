#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmaller(vector<int> &v){
    stack<int> st;
    st.push(-1);

    vector<int> ans(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

vector<int> prevSmaller(vector<int> &v){
    stack<int> st;
    st.push(-1);

    vector<int> ans(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    vector<int> ans = nextSmaller(v);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    vector<int> ans2 = prevSmaller(v);
    for(int i = 0; i < ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }

    return 0;
}