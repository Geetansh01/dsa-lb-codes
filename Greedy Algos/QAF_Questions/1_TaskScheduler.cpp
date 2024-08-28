#include<bits/stdc++.h>
using namespace std;

//TC: O( l*(n log m +  m log m) )
//l : length of tasks[] array
//n : gap (cooldown period)
//m : Different types of tasks (Here, A - Z)

//Ref for soln: " https://leetcode.com/problems/task-scheduler/solutions/3280549/full-explanation-using-priority-queue-and-formula-based-approach "

class Compare{
    public:
        bool operator () (pair<int, char>& A, pair<int, char>& B){
            return (A.first < B.first);
        }
};
int leastInterval(vector<char>& tasks, int n) {
    vector<int> fmap(26, 0); //char -> freq;

    for(auto& t : tasks){
        fmap[t - 'A']++;
    }

    priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> maxH; // {freq, task}
    for(int i = 0; i < 26; i++){
        if(fmap[i] != 0){
            pair<int, char> temp = {fmap[i], i+'A'};
            maxH.push(temp);
        }
    }

    int count = 0;
    int cl = n+1; //cycle length
    while(!maxH.empty()){
        vector<int> RemainingFmap(26, 0); //char -> freq;
        int tcc = 0; //this cycle count
        for(int i = 0; i < cl && !maxH.empty(); i++){
            auto f_t = maxH.top();
            char topTask = f_t.second;
            int freqTop = f_t.first;
            maxH.pop();
            freqTop--;
            RemainingFmap[topTask - 'A'] = freqTop;
            tcc++;
        }

        for(int i = 0; i < 26; i++){
            if(RemainingFmap[i] != 0){
                pair<int, char> temp = {RemainingFmap[i], i+'A'};
                maxH.push(temp);
            }
        }

        if(!maxH.empty()){
            tcc += cl - tcc;
        }

        count += tcc;
    }

    return count;
}


int main(){

return 0;
}