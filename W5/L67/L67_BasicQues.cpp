#include<iostream>
#include<string.h>
using namespace std;

int getLength(char name[]){
    int length = 0;
    int i = 0 ;
    while(name[i] != '\0'){
        length++;
        i++;
    }
    return length;
}

void reverse(char name[]){
    int start = 0;
    int end = strlen(name) - 1;
    while(start <= end){
        swap(name[start], name[end]);
        start++;
        end--;      
    }
}

void replaceSpace(char sentence[]){
    int i = 0;
    while(sentence[i] != '\0'){
        if(sentence[i] == ' '){
            sentence[i] = '@';
        }
        i++;
    }
}

bool checkPalindrome(char word[]){
    int s = 0;
    int e = strlen(word) - 1;

    while(s <= e){
        if(word[s] != word[e]){
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}

void convertIntoUpperCase(char arr[]){
    int n = strlen(arr);

    for(int i = 0; i < n; i++){
        arr[i] = arr[i] - 'a'  + 'A';
    }
}

void convertIntoLowerCase(char arr[]){
    int n = strlen(arr);

    for(int i = 0; i < n; i++){
        arr[i] = arr[i] - 'A' + 'a';
    }
}

int main(){
    // //Length of string
    // char name[100];
    // cin.getline(name, sizeof(name));
    // cout<<"Length : "<<getLength(name)<<endl;
    // cout<<"Length : "<<strlen(name)<<endl; //from "string.h" header file

    // //String Reversal
    // reverse(name);
    // cout<<"Name reversed : "<<name<<endl;

    //Replace Spaces with @
    // char sentence[100];
    // cin.getline(sentence, sizeof(sentence));
    // replaceSpace(sentence);
    // cout<<sentence<<endl;

    //Check If Palindrome
    // char word[100] = "LOL";
    // cout<<"Is Palindrome : "<<checkPalindrome(word)<<endl; 

    //Change Upper case to lower and vice a versa
    char arr[100] = "babbar";
    convertIntoUpperCase(arr);
    cout<<arr<<endl; 
    convertIntoLowerCase(arr);
    cout<<arr<<endl; 


return 0;
}