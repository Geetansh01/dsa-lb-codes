#include<iostream>
using namespace std;

//Ques : to print all possible permutations of given string

void printPermutation(string& str, int i){
    //Base Case
    if(i >= str.length()){
        cout<<str<<" ";
        return;
    }

    //Recursion
    for(int j = i; j < str.length(); j++){
        //swapping
        swap(str[i], str[j]);

        //Recursive call
        printPermutation(str, i+1);

        //Backtracking Step
        swap(str[i], str[j]);
    }

}


int main(){
   string str = "abc";
   int i = 0;
   printPermutation(str, i);

return 0;
}