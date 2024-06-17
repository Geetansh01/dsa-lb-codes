#include<iostream>
using namespace std;

//Done after completing the DSA course :)
//Ref for soln (NeetCodeIO YT) : " https://youtu.be/k2qrymM_DOo?si=Yepa73VmZ3qdGvUR "

//Main Pattern : 2 pointers
//General Learning/Hint: If going from left to right does not work, this does not mean the opposite will not work too. Try going from right to left.

//Interviewer will expect below Complexities, otherwise this Ques is Easy Marked on LeetCode!
//TC: O(n + m)
//SC: O(1)

//nextValidIndex() is the main Logic to think
void nextValidIndex(string& s, int& i){
    int backspace = 0;
    while(i >= 0){
        if(backspace == 0 && s[i] != '#'){
            //On a character and 0 backspace
            break;
        }
        else if(s[i] == '#'){
            backspace++;
        }
        else{
            //On a character with some bacakspaces left. So this character will be deleted
            backspace--;
        }
        i--;
    }
}

//This is simple, just comparing the strings
bool backspaceCompare(string s, string t) {
    int i = s.size() - 1;
    int j = t.size() - 1;
    nextValidIndex(s, i);
    nextValidIndex(t, j);
    while(i >= 0 && j >= 0){
        if(s[i] == t[j]){
            i--; j--;
            nextValidIndex(s, i);
            nextValidIndex(t, j);
        }
        else{
            return false;
        }
    }

    if(i<0 && j<0){
        return true;
    }
    else if(i < 0){
        nextValidIndex(t, j);
        if(j < 0){
            return true;
        }
        else{
            return false;
        }
    }
    //else
    nextValidIndex(s, i);
    if(i < 0){
        return true;
    }
    return false;
}

int main(){
   
return 0;
}