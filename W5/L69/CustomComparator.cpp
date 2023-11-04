#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// //custom comparator for "char"
// bool cmp(char first, char second){
//     // return (first < second); //ascending order
//     return (first > second); //descending order
// }

//custom comparator for "int"
bool compare(int first, int second){
    // return (first < second); //ascending order
    return (first > second); //descending order
}

int main(){
    // //Using custom comparator for "char"
    // string str = "abbcaad";
    // sort(str.begin(), str.end(), cmp);

    // for(auto iter : str){
    //     cout<<iter<<" ";
    // }
    // cout<<endl;


    //Using custom comparator in "int"
    // vector<int> vec{1,3,2,4,5,2,3,4,5,6,7};
    vector<int> vec{4,5,2,3,1};
    sort(vec.begin(), vec.end(), compare);

    for(auto iter : vec){
        cout<<iter<<" ";
    }

    return 0;
}