#include<iostream>
using namespace std;

int last_occurrence(char* arr, int n, char& target){
    //Base Case
    if(n == 1){
        if(*arr == target){
            return 0;
        }
        else{
            return -1;
        }
    }

    //1 case i will solve
    int a = last_occurrence(arr + 1, n - 1, target);
    if(a == -1){
        if(*arr == target){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        return a+1;
    }
}

int main(){
//    char str[] = "abcddedg";
char str[] = "abc";
   int size = sizeof(str)/sizeof(str[0]);
   char target = 'c';
   cout<<last_occurrence(str, size, target)<<endl;
return 0;
}