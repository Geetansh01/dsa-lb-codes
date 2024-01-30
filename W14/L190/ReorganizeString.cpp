#include<iostream>
#include<queue>
using namespace std;

/****Reorganize String [Interview][LeetCode : https://leetcode.com/problems/reorganize-string/description/]****/

class Node{
    public:
    char data;
    int count;

    Node(char data, int count){
        this->data = data;
        this->count = count;
    }
};

class compare{
    public: //GLTI KREGA TU : Remember to make it public !
    bool operator () (Node* a, Node* b){
        return (a->count) < (b->count);
    }
};

string reorganizeString(string s) {
    //Create Mapping
    int freq[26] = {0};
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        freq[ch - 'a']++;
    }

    priority_queue<Node*, vector<Node*>, compare> maxHeap;

    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            Node* temp = new Node(i+'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";

    //Bcz we will be pulling out 2 things from heap so it's size should be greater than 1
    while(maxHeap.size() > 1){
        //Step 1 : pull from heap
        Node* first = maxHeap.top();
        maxHeap.pop();

        Node* second = maxHeap.top();
        maxHeap.pop();

        //Step 2 : processing
        ans += (first->data);
        ans += (second->data);

        (first->count)--;
        (second->count)--;

        //Step 3 : push back to heap
        if((first->count) != 0){
            maxHeap.push(first);
        }
        else{
            delete first; //To prevent memory leak
        }

        if((second->count) != 0){
            maxHeap.push(second);
        }
        else{
            delete second; //To prevent memory leak
        }
        
    }

    if(maxHeap.size() == 1){
        Node* temp = maxHeap.top();
        maxHeap.pop();
        if((temp->count) == 1){
            ans += (temp->data);
        }
        else{
            return ""; //i.e answer is not possible
        }

        delete temp; //To prevent memory leak
    }

    return ans;
}

int main(){
   
return 0;
}