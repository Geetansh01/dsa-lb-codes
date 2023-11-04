#include<iostream>
using namespace std;

int fact(int n);

int main(){
   /****************Numeric Hollow Half Pyramid***********************/
//    int n; 
//    cin>>n;
//    for(int row = 0; row < n; row++){
//     if(row == 0 || row == 1 || row == (n-1)){
//         //Print Simple counting
//         for(int i = 0; i < row + 1; i++){
//             cout<<i+1<<" ";
//         }
//     }

//     else{
//         //Starting 1
//         cout<<"1"<<" ";

//         //Spaces
//         for(int spaces = 0; spaces < row - 1; spaces++){
//             cout<<" "<<" ";
//         }

//         //Last number
//         cout<<row+1<<" ";
//     }
//    cout<<endl;
//    }


/****************Numeric Hollow Inverted Half Pyramid***********************/
/*
1 2 3 4 5 
2     5 
3   5 
4 5 
5 
*/
// int n = 5; //no of rows hard coded to be 5
// for(int row = 0; row < n; row ++){
//     if(row == 0 || row == n-2 || row == n-1 ){
//         //Counting
//         for(int c = row + 1; c <= 5; c++){
//             cout<<c<<" ";
//         }
//     }

//     else{
//         cout<<row + 1<<" ";

//         //Spaces
//         for(int space = 0; space < n-row-2; space++){
//             cout<<" "<<" ";
//         }

//         //Last 5
//         cout<<"5 ";
//     }

//     cout<<endl;
// }

/********************Numeric Palindrome Equilateral Pyramid********************/
/*
                1       
              1 2 1     
            1 2 3 2 1   
          1 2 3 4 3 2 1 
        1 2 3 4 5 4 3 2 1         
      1 2 3 4 5 6 5 4 3 2 1       
    1 2 3 4 5 6 7 6 5 4 3 2 1     
  1 2 3 4 5 6 7 8 7 6 5 4 3 2 1   
1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 
*/
// int n;
// cin>>n;
// for(int row = 0; row < n; row++){
//     //Spaces
//     for(int space = 0; space < n-row-1; space++){
//         cout<<" "<<" ";
//     }

//     //Counting
//     for(int c = 0; c < row + 1; c++){
//         cout<<c+1<<" ";
//     }

//     //Reverse Counting
//     for(int rc = row; rc >= 1; rc--){
//         cout<<rc<<" ";
//     }

//     cout<<endl;
// }

/********************Solid Half Diamond********************/
/*
* 
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
*/
// int r; //r is the total rows
// cin>>r;
// int n = r/2;
// int m = r - n;

// //Upper Half
// for(int row = 0; row < n; row++){
//     //stars
//     for(int star = 0; star < row + 1; star++){
//         cout<<"* ";
//     }
//     cout<<endl;
// }

// //Lower Half
// for(int row = 0; row < m; row++){
//     //stars
//     for(int star = 0; star < m-row; star++){
//         cout<<"* ";
//     }

//     cout<<endl;
// }


/********************Fancy Pattern #3********************/
/*
* 
* 1 *
* 1 2 1 *
* 1 2 3 2 1 *
* 1 2 1 *
* 1 *
*
*/
// int r; //Total Rows
// cin>>r;
// int n = r/2; //Upper half 
// int m = r - n; //Lower Half

// //Upper Half
// for(int row = 0; row < n; row++){
//   //First star
//   cout<<"* ";

//   //Counting
//   for(int c = 0; c < row; c++){
//     cout<<c+1<<" ";
//   }

//   //Reverse Counting
//   for(int rc = row - 1; rc >= 1; rc-- ){
//     cout<<rc<<" ";
//   }

//   //Last star
//   if(row != 0 ){
//     cout<<"* ";
//   }

//   cout<<endl;
// }

// //Upper Half
// for(int row = 0; row < m; row++){
//   //Fist Star
//   cout<<"* ";

//   //Counting
//   for(int c = 0; c < m - row - 1; c++){
//     cout<<c+1<<" ";
//   }

//   //Reverse Counting
//   for(int rc = m - row - 2; rc >= 1; rc-- ){
//     cout<<rc<<" ";
//   }

//   //Last star
//   if(row != m-1){
//     cout<<"* ";
//   }

//   cout<<endl;
// }


/*****************Floyd's Triangle Pattern*******************************/
// int n;
// cin>>n;
// int num = 1;
// for(int row = 0; row < n; row++){
//   //counting
//   for(int c = 0; c < row + 1; c++){
//     cout<<num++<<" ";
//   }
//   cout<<endl;
// }


/*****************Pascal's Triangle Pattern 1*******************************/
/*
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/
// int n;
// cin>>n;
// for(int row = 0; row < n; row++){
//   for(int col  = 0; col < row + 1; col++){
//     //Formula for a number in pascal's triangle : row (Combination) col
//     cout<<fact(row)/( fact(col) * fact(row - col) )<<" ";
//   }
//   cout<<endl;
// }


/*****************Pascal's Triangle Pattern 2*******************************/
/*
       1 
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1 
*/
// int n;
// cin>>n;
// for(int row = 0; row < n; row++){
//     //Spaces 
//     for(int space = 0; space < n - 1 - row; space++){
//       cout<<" ";
//     }

//   //Column
//   for(int col  = 0; col < row + 1; col++){

//     //Formula for a number in pascal's triangle : row (Combination) col
//     cout<<fact(row)/( fact(col) * fact(row - col) )<<" ";

//   }
//   cout<<endl;
// }

return 0;
}


int fact(int n){
  int fact = 1;
  while (n != 0){
    fact = fact*n;
    n--;  
  }
  return fact;
}