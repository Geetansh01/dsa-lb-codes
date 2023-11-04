#include<iostream>
#include<vector>
using namespace std;


int main(){
/****************Method 1 To make 2D Arrays with vectors***********************/
//    vector<vector<int> > arr;

//    vector<int> a{1,2,3};
//    vector<int> b{2,4,6};
//    vector<int> c{1,3,7};

//    arr.push_back(a);
//    arr.push_back(c);
//    arr.push_back(a);

// // For Printing when No of columns is same in all rows (as is standard for a matrix)
// for(int i = 0; i < arr.size(); i++){
//     for(int j = 0; j < arr[0].size(); j++){
//         cout<<arr[i][j];
//     }
//     cout<<endl;
// }

// // For Printing when No of columns is NOT same in all rows
// for(int i = 0; i < arr.size(); i++){
//     for(int j = 0; j < arr[i].size(); j++){
//         cout<<arr[i][j];
//     }
//     cout<<endl;
// }

/****************Method 2 To make 2D Arrays with vectors***********************/
vector <vector<int> > arr(3, vector<int> (5, 1));

// For Printing when No of columns is same in all rows (as is standard for a matrix)
for(int i = 0; i < arr.size(); i++){
    for(int j = 0; j < arr[0].size(); j++){
        cout<<arr[i][j];
    }
    cout<<endl;
}




















return 0;
}