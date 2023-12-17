#include<iostream>
#include<deque>
#include<vector>
using namespace std;

/****Sum of minimum and maximum elements of all subarrays of size k [GFG : https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/] ******/

vector<int> SumOfMinMaxK(vector<int>& v, int k){
    deque<int> Qmax;
    deque<int> Qmin;
    vector<int> ans;

    //Process 1st window
    for(int i = 0; i < k; i++){
        //Inserting in Qmax
        if(Qmax.empty()){
            Qmax.push_back(i);
        }
        else{
            while(!Qmax.empty()){
                int element = v[Qmax.back()];
                if(element <= v[i]){
                    Qmax.pop_back();
                }
                else{
                    break;
                }
            }
            Qmax.push_back(i);
        }

        //Inserting in Qmin
        if(Qmin.empty()){
            Qmin.push_back(i);
        }
        else{
            while(!Qmin.empty()){
                int element = v[Qmin.back()];
                if(element >= v[i]){
                    Qmin.pop_back();
                }
                else{
                    break;
                }
            }
            Qmin.push_back(i);
        }
    }

    //Store ans of first window
    ans.push_back(v[Qmax.front()] + v[Qmin.front()]);

    //Process the remaining windows
    for(int i = k; i < v.size(); i++){
        //Remove elements that are out of the window
        if(!Qmax.empty() && Qmax.front() + k <= i){
            Qmax.pop_front();
        }

        if(!Qmin.empty() && Qmin.front() + k <= i){
            Qmin.pop_front();
        }

        //Inserting new element in Qmax
        if(Qmax.empty()){
            Qmax.push_back(i);
        }
        else{
            while(!Qmax.empty()){
                int element = v[Qmax.back()];
                if(element <= v[i]){
                    Qmax.pop_back();
                }
                else{
                    break;
                }
            }
            Qmax.push_back(i);
        }

        //Inserting new element in Qmin
        if(Qmin.empty()){
            Qmin.push_back(i);
        }
        else{
            while(!Qmin.empty()){
                int element = v[Qmin.back()];
                if(element >= v[i]){
                    Qmin.pop_back();
                }
                else{
                    break;
                }
            }
            Qmin.push_back(i);
        }

        //Store ans
        ans.push_back(v[Qmax.front()] + v[Qmin.front()]);
    }

    return ans;
}

int main(){
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    vector<int> ans = SumOfMinMaxK(arr, k);
    int Sum = 0;
    
    cout<<"ans vector : ";
    for(auto x : ans){
        cout<<x<<" ";
        Sum += x;
    }

    cout<<"\nSum : "<<Sum;

return 0;
}