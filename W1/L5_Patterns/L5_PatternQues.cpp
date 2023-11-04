#include<iostream>
using namespace std;


int main(){
/*******Solid Square*************/
//     int n;
//     cin>>n;
//    for(int row = 0; row < n; row += 1){
//     for(int col = 0; col < n; col += 1){
//         cout<<"* ";
//     }
//     cout<<endl;
//    }


/**************Hollow Rectangle****************/
   //Method 1(My logic)
//    int rowCount; 
//    int colCount;
//    cin>>rowCount>>colCount;
//    for(int row = 0; row < rowCount; row += 1){
//     for(int col = 0; col < colCount; col += 1){
//         //First row  or last row(rowCount-1)
//         if((row == 0) || (row == (rowCount-1)) ){
//             cout<<"* ";
//         }
//         //Middle rows and End columns(colCount-1)
//         else if((col == 0) || (col == (colCount-1))){
//             cout<<"* ";
//         }
//         //Middle rows and Middle columns
//         else{
//             cout<<"  ";
//         }
//     }
//     cout<<endl;
//    }

    //Method 2(Love Babbar's Logic)
    // int rowCount;
    // int colCount;
    // cin>>rowCount>>colCount;
    // for(int row = 0; row < rowCount; row +=1){
    //     //first row or last row(rowCount-1)
    //     if((row == 0) || (row == (rowCount-1))){
    //         for(int col = 0; col < colCount; col += 1){ 
    //             cout<<"* ";
    //         }
    //     }
    //     //Middle rows
    //     else{
    //         //first star
    //         cout<<"* ";
    //         //Empty Spaces
    //         for(int col = 0; col < (colCount-2); col += 1){ //(colCount-2) bcz no. of Empty Spaces is colCount - (1st + Last star).
    //             cout<<"  ";
    //         }
    //         //Last star
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }


/*****************Half Pyramid*****************/
// int n;
// cin>>n;
// for(int row = 0; row < n; row += 1){
//     for(int col = 0; col < (row + 1); col += 1){
//         cout<<"*";
//     }
//     cout<<endl;
// }

/*****************Inverted Half Pyramid*****************/
// int n; //n is the Row count 
// cin>>n;
// for(int row = 0; row < n; row += 1){
//     for(int col = 0; col < (n - row); col += 1){
//         cout<<"* ";
//     }
//     cout<<endl;
// }

/*****************Number Pyramid*****************/
// int n; //n is row count
// cin>>n;
// for(int row = 0; row < n; row += 1){
//     for(int col = 0; col < (row + 1); col += 1){
//         cout<<col + 1<<" ";
//     }
//     cout<<endl;
// }

/*****************Inverted Number Pyramid*****************/
// int n; //n is row count
// cin>>n;
// for(int row = 0; row < n; row += 1){
//     for(int col = 0; col < (n - row); col += 1){
//         cout<<(col + 1)<<" ";
//     }
//     cout<<endl;
// }


/*******************Full Star Pyramid************************/
// int n; //n is row count
// cin>>n;
// for(int row = 0; row < n; row += 1){
//     //to print Empty Space in each row
//     for(int space = 0; space < ((n-1)-row); space += 1){
//         cout<<" ";
//     }

//     //To print Stars in each row
//     for(int star = 0; star < (row + 1); star += 1){
//         cout<<"* ";
//     }
//     cout<<endl;
// }

/*******************Inverted Full Star Pyramid************************/
// int n; //n is row count
// cin>>n;
// for(int row = 0; row < n; row += 1){
//     //To print Empty Space
//     for(int s = 0; s < row; s += 1){
//         cout<<" ";
//     }

//     //To Print stars
//     for(int star = 0; star < (n - row); star += 1){
//         cout<<"* ";
//     }
//     cout<<endl;
// }


return 0;
}