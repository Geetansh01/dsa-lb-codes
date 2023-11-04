#include<iostream>
#include<limits.h>
using namespace std;


/***********************Print Array**********************************/
void printArray(int arr[][3], int row, int col);

/***********************Print Row Sum**********************************/
int printRowSum(int arr[][3], int row, int col);

/**********************Linear Search on 2d Array**********************************/
bool LinearSearch(int arr[][3], int row, int col, int key);

/**********************Max No in Array**********************************/
int MaxNo(int arr[][3], int row, int col);

/**********************Transpose Matrix (2D Array)(Different from Printing Transpose Of 2D Matrix)**********************************/
void transpose(int arr[][3], int row, int col, int transposeArr[][3]);

int main(){
/************************Printing Transpose Of 2D Matrix****************************/
//    int arr[2][3] = {
//     {1,2,3},
//     {4,5,6},
//    };

//     for(int j = 0; j < 3; j++){
//         for(int i = 0; i < 2; i++){
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
//    }

/***********************Print Row Sum**********************************/
// int arr[3][3] = {1,2,3,4,5,6,7,8,9};
// int row = 3;
// int col = 3;
// printRowSum(arr, row, col);

/***********************Linear Search on 2d Array**********************************/
// int arr[3][3] = {1,2,3,4,5,6,7,8,9};
// int row = 3;
// int col = 3;
// bool ans = LinearSearch(arr, row, col, 9);
// cout<<ans<<endl;

/********************Maximum No in 2D array*****************************/
// int arr[3][3] = {1,2,3,4,5,6,7,8,9};
// int row = 3;
// int col = 3;
// cout<<MaxNo(arr, row, col)<<endl;

/**********************Transpose Matrix (2D Array)(Different from Printing Transpose Of 2D Matrix)**********************************/
int arr[3][3] = {1,2,3,4,5,6,7,8,9};
int row = 3;
int col = 3;
int tranpose[3][3];

transpose(arr, row, col, tranpose);
cout<<"Original Matrix :"<<endl;
printArray(arr, row, col);
cout<<"Transpose Matrix :"<<endl;
printArray(tranpose, row, col);

return 0;
}


int printRowSum(int arr[][3], int row, int col){
    for(int r = 0; r < row; r++){
        //sum initialised 0 at the start of every row
        int sum = 0;
        for(int c = 0; c < col; c++){
            sum = sum + arr[r][c];
        }
        cout<<sum<<" ";
    }
    return 0;
}


bool LinearSearch(int arr[][3], int row, int col, int key){
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(arr[r][c] == key){
                return true;
            }
        }
    }
    return false;
}

int MaxNo(int arr[][3], int row, int col){
    int max = INT_MIN;
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(arr[r][c] > max){
                max = arr[r][c];
            }
        }
    }
return max;
}

void printArray(int arr[][3], int row, int col){
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            cout<<arr[r][c];
        }
    cout<<endl;
    }
}

void transpose(int arr[][3], int row, int col, int transposeArr[][3]){
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            transposeArr[c][r] = arr[r][c];
        }
    }
}
