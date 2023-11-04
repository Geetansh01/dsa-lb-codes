#include<iostream>
#include<vector>
using namespace std;

/****************Q 80 : String Compression [LeetCode : https://leetcode.com/problems/string-compression/description/]*************************************************/

void rev(vector<char>& vec, int s, int e){
    while(s < e){
        swap(vec[s], vec[e]);
        s++;
        e--;
    }
}

int compress(vector<char>& chars) {
    int i = 0, count = 0, j = 0, p = chars.size()-1;
    char letter = chars[0];
    int s = 0, e = 0;

    while(i < chars.size()){
        if(chars[i] == letter){
            count++;
            i++;
        }

        else if(count > 1){
            chars[j++] = letter;
            s = j;
            while(count > 0){
                int digit = count%10;
                chars[j++] = digit + ('1' - 1);
                count = count/10;
            }
            e = j - 1;
            rev(chars, s, e);

            letter = chars[i];
            count = 0;
        }

        else{
            chars[j++] = letter;             
            letter = chars[i];
            count = 0;
        }
    }

    if(count > 1){
        chars[j++] = letter;
        s = j;
        while(count > 0){
            int digit = count%10;
            chars[j++] = digit + ('1' - 1);
            count = count/10;
        }
        e = j - 1;
        rev(chars, s, e);

        letter = chars[i];
        count = 0;
    }

    else{
        chars[j++] = letter;             
        letter = chars[i];
        count = 0;
    }

    while(p >= j){
        chars.pop_back();
        p--;
    }

    return j;
}

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout<<"Length of output : "<<compress(chars)<<endl;

    for(auto iter : chars){
        cout<<iter<<" ";
    }
}