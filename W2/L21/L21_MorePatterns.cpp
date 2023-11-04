#include<iostream>
using namespace std;


int main(){

/*****************Numeric Full Pyramid***********************/
/*
   1
  232
 34543
4567654
*/
//    int n; //n is the total rows
//    cin>>n;
//    for(int row = 0; row < n; row +=1){
//     //To pprint spaces
//     for(int space = 0; space < n - row - 1; space += 1){
//         cout<<" ";
//     }

//     //To print row + 1 elements (numbers)
//     for(int col = 0; col < row + 1; col += 1){
//         cout<< row + col + 1;
//     }

//     //To print reverse counting
//     int start = 2*row;
//     for(int rcount = 0; rcount < row; rcount += 1){
//         cout<<start;
//         start = start - 1;
//     }

//     cout<<endl;
//    }


/*****************Numeric Hollow Pyramid***********************/
/*
    1
   1 2
  1   3
 1     4
1 2 3 4 5
*/
// int n; //n is the total rows
// cin>>n;

// for(int row = 0; row < n; row += 1){
//     //Spaces
//     for(int space = 0; space < n - row - 1; space += 1){
//         cout<<" ";
//     }

//     //Numbers with spaces in between
//     int start = 1;
//     for(int ch = 0; ch < 2*row + 1; ch += 1){
//         //If first or last row
//         if(row == 0 || row == (n-1)){
//             //Even characters
//             if(ch%2 == 0){
//                 cout<<start;
//                 start += 1;
//             }

//             //Odd Characters
//             else{
//                 cout<<" ";
//             }
//         }

//         //Middle Rows
//         else{
//             //1st character
//             if(ch == 0){
//                 cout<<1;
//             }
//             else if(ch == 2*row +1 -1){
//                 cout<<row+1;
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//     }

//     cout<<endl;
// }

return 0;
}