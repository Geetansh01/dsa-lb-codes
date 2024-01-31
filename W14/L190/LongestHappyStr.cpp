#include<iostream>
#include<queue>
using namespace std;

/****Longest Happy String [LeetCode : https://leetcode.com/problems/longest-happy-string/description/]*****/
//Based on PPP pattern of heaps (+Greedy Approach)

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
    bool operator () (Node a, Node b){
        return (a.count) < (b.count);
    }
};

string longestDiverseString(int a, int b, int c) {
    priority_queue<Node, vector<Node>, compare> maxHeap;

    if(a > 0){
        Node temp('a', a);
        maxHeap.push(temp);
    }
    if(b > 0){
        Node temp('b', b);
        maxHeap.push(temp);
    }
    if(c > 0){
        Node temp('c', c);
        maxHeap.push(temp);
    }

    string ans = "";

    while(maxHeap.size() > 1){
        //Step 1 : pull from heap
        Node first = maxHeap.top();
        maxHeap.pop();

        Node second = maxHeap.top();
        maxHeap.pop();

        if(first.count >= 2){
            ans += first.data;
            ans += first.data;
            first.count -= 2; 
        }
        else{
            ans += first.data;
            first.count--;
        }

        /*
            WARNING : Special condition " ... && second.count >= first.count"

            1)In this ques, following same PPP ( + Greedy approach) as in "L190 : RemoveStones". 
            2)For "first" element (say x)
                1)Bcz it's the one with max freq, we place as many together as we can (i.e 2) so that ye jldi khtm ho jaye

            3)Main Thing is how many of the "second" to put after "first" (say y is the second)
                1)U may think ki "y" ko bhi jldi khtm kr lete hai kya dikkt hai to 2 "y" rkh do if u can BUT THAT'S WRONG!
                2)Remember, "y" is not the max element, "x" is . "y" is just a separator b/w "x"s . 

                [A] Case 1 : After putting "x" & decreasing it's freq (line (1) or (2)), now the freq of "y" < "x"
                    1)Here, we have a kami of separators
                    2)To "y" ko 1-1 hi rkho after 2 "x"s bcz longest possible Happy string bnegi if we are able to separate more "x"s

                    eg: x = 6; y = 2
                        (i) xx yy xx {without thoughtful utilisation of "y"}
                        (ii)xx y xx y xx { CORRECT ANSWER }

                [B] Case 2 : After putting "x" & decreasing it's freq (line (1) or (2)), now the freq of "y" >= "x"
                    1)Here, "y" ki kami nhi hai, so u can put 2 "y"s 
                    2)This is like "y" is the new max-freq-element for now, so ise bhi jldi khtm krna hai to max possible rkh lo                

                
        */
        if(second.count >= 2 && second.count >= first.count){
            ans += second.data;
            ans += second.data;
            second.count -= 2;
        }
        else{
            ans += second.data;
            second.count--;
        }

        if(first.count > 0){
            maxHeap.push(first);
        }

        if(second.count > 0){
            maxHeap.push(second);
        }
    }

    if(maxHeap.size() == 1){
        Node temp = maxHeap.top();
        maxHeap.pop();

        if(temp.count >= 2){
            ans += temp.data;
            ans += temp.data;
            temp.count -= 2;
        }
        else{
            ans += temp.data;
            temp.count--;
        }
    }
    
    return ans;
}

int main(){
   
return 0;
}