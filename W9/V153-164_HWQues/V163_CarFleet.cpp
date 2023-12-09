#include<iostream>
#include<limits.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

/******Q163 : Car Fleet [LeetCode : https://leetcode.com/problems/car-fleet/description/]********/

class Car{
    public:
        int pos;
        int speed;

        Car(int p, int s) : pos(p), speed(s){}; 
        static bool comp(Car& a, Car& b){
            return a.pos < b.pos;
        }
};

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;
    for(int i = 0; i < position.size(); i++){
        Car tempCar(position[i], speed[i]);
        cars.push_back(tempCar);
    }

    sort(cars.begin(), cars.end(), Car::comp);

    //Time vector to store time
    vector<double> time (position.size(), 0);
    for(int i = 0; i < cars.size(); i++){
        if(cars[i].speed != 0){
            time[i] =  (target - cars[i].pos)/double(cars[i].speed);
        }
        else{
            //The car has 0 speed and thus never reaches target
            time[i] = INT_MAX;
        }
    }

    int fleetCount = 0;

    // Using Stack to calculate fleetCount
    stack<double> timeStack;
    for(int i = time.size() - 1; i >= 0; i--){
        if(timeStack.empty()){
            timeStack.push(time[i]);
        }
        else if(time[i] > timeStack.top()){
            timeStack.push(time[i]);
        }
        else{
            //Do Nothing
        }
    }
    fleetCount = timeStack.size();

    // //OR no need to use the stack, just use a single variable to calculate fleetCount (But Info of which fleet reaches at which time is lost as that was being stored in stack)
    // double temp = INT_MIN;
    // for(int i = time.size()-1; i >= 0; i--){
    //     if(temp < time[i]){
    //         fleetCount++;
    //         temp = time[i];
    //     }
    // }

    return fleetCount;
}

int main(){
   int target = 12;
   vector<int> position = {10,8,0,5,3};
   vector<int> speed = {2,4,1,1,3};

   cout<<carFleet(target, position, speed);
return 0;
}