#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node* right;
};


//Q2 Solution
bool chkLoop(Node*& head){
    Node* temp = head;
    unordered_map<Node*, bool> visited;

    while(temp != NULL){
        if(visited.find(temp) == visited.end()){
            visited[temp] = true;
        } 
        else{
            return true; //i.e ll has loop
        }
        temp = temp->right;
    }

    return false;
}

int main(){
    // Q1 : Record frequency of alphabets in string
    string str = "Geetansh";
    unordered_map<char, int> freq;

    for(int i = 0; i < str.length(); i++){
        char tefreq = str[i];
        freq[tefreq]++;
    }

    for (auto y : freq){
        cout << y.first << " -> " << y.second << endl;
    }


    //Q2 : Chk for loop in linked list [LeetCode : https://leetcode.com/problems/linked-list-cycle/submissions/1166077183/]

    return 0;
}