#include<iostream>
using namespace std;


int main(){
/**************************Q1 & Q2: Solid Square & Hollow Square (Very Basic, Not Done)*****************/

/*********************************Patterns Q3: Hollow Inverted Half Pyramid***********************/
/*
********
*     *
*    *
*   *
*  *
* *
**
*
*/
//    int n; //n is the no of rows
//    cin>>n;
//    for(int row = 0; row < n; row += 1){
//     //Starting row
//     if(row == 0){
//         for(int star = 0; star < n; star += 1 ){
//             cout<<"*";
//         }
//     }

//     //End Row
//     else if(row == (n-1)){
//         cout<<"*";
//     }

//     //Middle Rows
//     else{
//         cout<<"*";    //Starting Star

//         //Middle Spaces
//         for(int space = 0; space < ((n-3)-(row-1)); space += 1){
//             cout<<" ";
//         }

//         cout<<"*"; //Ending Star
//     }
//     cout<<endl;
//    }


/****************************Patterns Q4 : Hollow Full Star Pyramid **********************************/
/*
     *
    * *
   *   *
  *     *
 *       *
***********
*/
// int n; //n is the row count
// cin>>n;
// int totcol = (2*n)-1; //totalcol is the total no of columns based on total no of rows

// for(int row = 0; row < n; row ++){
//     //For middle Rows
//     if(row != 0 && row != (n-1)){ //(n-1) is the last row
    
//         //Initial Empty Spaces
//         for(int ispace = 0; ispace < (n-1)-row; ispace++){
//             cout<<" ";
//         }

//         //Starting * of Middle Rows
//         cout<<"*";

//         //Middle Empty Spaces
//         for(int mspace = 0; mspace < (totcol - 2 -(2*((n-1)-row)) ); mspace++){ //((n-1)-row) is the no. of Initial Empty Spaces in a row
//             cout<<" ";
//         }

//         //Ending * of Middle Rows
//         cout<<"*";
//     }

//     //0th row
//     else if(row == 0){
//         //Initial Empty Spaces
//         for(int ispace = 0; ispace < (n-1)-row; ispace++){
//             cout<<" ";
//         }

//         //The only * of 0th row
//         cout<<"*";
//     }

//     //Last Row : (n-1)th row
//     else{
//         //All the *s of last row
//         for(int col = 0; col < totcol; col++ ){
//             cout<<"*";
//         }
//     }

//     cout<<endl; //To go to next line after each row
// }

return 0;
}