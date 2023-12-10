#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//M1 : Using Stack (TC : O(N)) (See Monotonic Stack Problem in N.B)
vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    vector<double> answer(cars.size(), -1);
    stack<double> stk;

    for(int i = cars.size() - 1; i >= 0; i--){
            while(!stk.empty() && cars[stk.top()][1] >= cars[i][1]){
                //pop this car as it's faster than us so no collison possible with it
                stk.pop();
            }

            if(stk.empty()){
                //The stack has become empty. So all cars ahead of us were faster than us thus no collison
                stk.push(i);
            }

            else{
                //Found a car to collide with. So collision is Sure to happen
                double CollTime = (double(cars[stk.top()][0] - cars[i][0]))/(cars[i][1] - cars[stk.top()][1]);

                //The time we take to collide should be less than or equal to the time the next car is taking to collide with it's next, else we will collide when the next has already collided and update timeColl accordingly
                if(answer[stk.top()] == -1 || CollTime <= answer[stk.top()]){
                    answer[i] = CollTime;
                }
                else{
                    while(!stk.empty() &&  CollTime > answer[stk.top()] && answer[stk.top()] != -1){
                        stk.pop();
                        CollTime = (double(cars[stk.top()][0] - cars[i][0]))/(cars[i][1] - cars[stk.top()][1]);
                    }
                    answer[i] = CollTime;             
                }
                stk.push(i);
            }
    }

    return answer;
}

int main(){
   vector<vector<int> > cars = {{1,2},{2,1},{4,3},{7,2}};
   vector<double> CollisionTimes = getCollisionTimes(cars);

   for(auto x : CollisionTimes){
    cout<<x<<" ";
   }
return 0;
}