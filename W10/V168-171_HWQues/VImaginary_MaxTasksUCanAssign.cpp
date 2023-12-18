#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

/****Maximum Number of Tasks You Can Assign [LeetCode : https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/]********/

// Solution Reference : https://algo.monster/liteproblems/2071
//TC : O(n log n + m log m + min(n, m) log min(n, m))
//SC : O(n + m)
// where :
//     n = number of tasks
//     m = number of workers

//Function to chk if 'x' tasks can be done
bool canAssignTasks(int& x, int& pills, int& taskCount, int& workerCount, vector<int>& tasks, vector<int>& workers, int& strength) {
    int remainingPills = pills;
    deque<int> availableTasks;
    int taskIndex = 0;

    for (int workerIndex = workerCount - x; workerIndex < workerCount; ++workerIndex) {

        while (taskIndex < x && tasks[taskIndex] <= workers[workerIndex] + strength) {
            availableTasks.push_back(tasks[taskIndex++]);
        }

        /*
            1)If no tasks can be assigned to the current worker, return false.

            2)This is because we selected 'x' strongest workers (i.e 'x' workers from the end of "workers" array which is sorted in ascending order) to chk if they can do 'x' tasks, and even if 1 worker performs 0 tasks while the rest does 1 task each, we will still not meet our goal! 

            3)Note : Ques states that each worker can do only 1 task
        */
        if (availableTasks.empty()) {
            return false;
        }

        // When Task can be done without a pill, pop the task from front
        if (availableTasks.front() <= workers[workerIndex]) {
            availableTasks.pop_front();
        }

        // When Task requires a pill and we have pills left, pop the task from back
        else if (remainingPills > 0) {
            --remainingPills;
            availableTasks.pop_back();

            /*
                Why pop_back()? 
                Ab agr pill de hi rhe ho to make the worker do the biggest task from the queue (the queue will contain smaller task in front and bigger ones in back!)
            */
        } 

        // Worker needs pills to do the task but NO pills left!
        else {
            return false;
        }
    }
    return true;
}

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    // Sort tasks and workers so we can use binary search effectively
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    
    int taskCount = tasks.size();
    int workerCount = workers.size();

    //Binary Search on Search Space 0 to min(taskCount, workerCount)
    int answer = -1; //This will finally store the max tasks that can be done
    int s = 0;
    int e = min(workerCount, taskCount);
    int mid = s + (e - s)/2;
    
    // Binary search to find the maximum number of tasks that can be assigned
    while (s <= e) {
        // Check if 'mid' number of tasks can be successfully assigned
        if (canAssignTasks(mid, pills, taskCount, workerCount, tasks, workers, strength)) {
            answer = mid;
            s = mid + 1;
        } 
        else {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }

    // 'answer' will contain the maximum number of tasks that can be assigned
    return answer;
}

int main(){
    //Below is a nice Test Case, answer is 3
   vector<int> tasks = {5, 9, 8, 5, 9};
   vector<int> workers = {1, 6, 4, 2, 6};
   int pills = 1;
   int strength = 5;
   
   cout<<maxTaskAssign(tasks, workers, pills, strength);
return 0;
}