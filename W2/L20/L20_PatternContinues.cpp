#include<iostream>
using namespace std;


int main(){
/*******************Full Star Diamond (Upright Pyramid + Inverted Pyramid)************************/
/*
   *    
  * *   
 * * *  
* * * * 
* * * * 
 * * *  
  * *
   *
*/
// int n; //n is row count
// cin>>n;
// //Full Pyramid
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

// //Full Pyramid Inverted
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

/******************Hollow Diamond*************************/
/*
   *
  * *
 *   *
*     *
*     *
 *   *
  * *
   *
*/
// int r; //r is the total rows
// cin>>r;
// int n = r/2; //n is the rows in upper half (we are splitting the pattern into upper and lower half)

// //Upper Half Of Pattern
// for(int row = 0; row < n; row += 1 ){
//     //Initial Empty Spaces
//     for(int space = 0; space < n-row-1; space += 1){
//         cout<<" ";
//     }

//     //Characters after Initial Spaces (* & " ")
//     for(int ch = 0; ch < 2*(row) + 1; ch += 1){  //" 2*(row) + 1 " from The formula of Odd numbers ( 2x + 1)
//         //Printing Start * and End *
//         if(ch == 0 || ch == 2*(row)){
//             cout<<"*";
//         }
        
//         //Middle Spaces
//         else{
//             cout<<" ";
//         }
//     }

//     cout<<endl;
// }

// //Lower Half Of Pattern
// //Love Babbar's Logic
// for(int row = 0; row < n; row += 1 ){
//     //Initial Empty Spaces
//     for(int space = 0; space < row; space += 1){
//         cout<<" ";
//     }

//     //Characters after Initial Spaces (* & " ")
//     for(int ch = 0; ch < (2*n - (2*(row) + 1)); ch += 1){ 
//         /*

//         1)Say for n = 3 the pattern will be :
//         *   *
//          * *
//           *
//         2)Here the frequency for characters (i.e * + " " after Initial Empty Spaces) is:
//             row 0 : 5 ch
//             row 1 : 3 ch
//             row 2 : 1 ch
//         3)Common Observation : whenever u see a reverse odd no pattern like (5, 3, 1) then formula " n "
//          se subtract krne ki form me hoga.
//         4)So try (2*n - (2*(row) + 1)), and it will work . Remember (2*(row) + 1) from "Upper Half Of Pattern" Code.

//         */
       
//         //Printing Start * and End *
//         if(ch == 0 || ch == (2*n - (2*(row) + 1))-1){
//             cout<<"*";
//         }
        
//         //Middle Spaces
//         else{
//             cout<<" ";
//         }
//     }

//     cout<<endl;
// }


//My Logic
// for(int row = 0; row < n; row += 1 ){
//     if(row != (n-1)){
//             //Initial Empty Spaces
//             for(int space = 0; space < row; space += 1){
//                 cout<<" ";
//             }

//             //Starting *
//             cout<<"*";

//             //Middle Empty Spaces
//             for(int mspace = 0; mspace < 2*(n - (row + 1 )) - 1; mspace += 1){  //From The formula of Odd numbers ( 2x - 1)
//                 cout<<" ";
//             }

//             //Ending *
//             cout<<"*";
//         }

//     //Last row : (n-1)th row
//     else{
//         //Initial Empty Spaces
//         for(int space = 0; space < row; space += 1){
//             cout<<" ";
//         }

//         //The only *
//         cout<<"*";

//     }

//     cout<<endl;
// }


/******************Flipped Solid Diamond*************************/
/*
**** ****
***   ***
**     **
*       *
*       *
**     **
***   ***
**** ****
*/
// int r ; //r is the total rows
// cin>>r;
// int n = r/2; //n is the rows in esch half (splitting the pattern in lower and uppeer half)

// //Upper Half
// for(int row = 0; row < n; row += 1){
//    //Starting *s
//    for(int sstar = 0; sstar < n-row; sstar += 1){
//       cout<<"*";
//    }

//    //Empty Space wala Pyramid
//    for(int space = 0; space < 2*row + 1; space += 1){
//       cout<<" ";
//    }

//    //Ending *s
//    for(int estar = 0; estar < n-row; estar += 1){
//       cout<<"*";
//    }

//    cout<<endl;
// }

// //Lower Half
// for(int row = 0; row < n; row += 1){
//    //Starting *s
//    for(int sstar = 0; sstar < row + 1; sstar += 1){
//       cout<<"*";
//    }

//    // Empty Space wala invertedd Pyramid
//    for(int espace = 0; espace < 2*n - (2*row + 1); espace += 1){  //for logic of (2*n - (2*row + 1)) see above ques "Hollow Diamond"
//       cout<<" ";
       
//    }

//    //Endding *s
//    for(int estar = 0; estar < row + 1; estar += 1){
//       cout<<"*";
//    }

//    cout<<endl;
// }

/***************Fancy Pattern #2**************/
/*
1
2*2
3*3*3
4*4*4*4
4*4*4*4
3*3*3
2*2
1
*/
// int r; //r is the total no of rows
// cin>>r;
// int n = r/2;

// //Upper Half
// for(int row = 0; row < n; row += 1){
//    //printing digits
//    for(int digit = 0; digit < row + 1; digit += 1){
//       cout<<row + 1;
//       //If on last digit, do not print * after it
//       if(digit != row){
//          cout<<"*";
//       }

//       //print * after a digit
//       else{  }
//    }
//    cout<<endl;
// }

// //Lower Half
// for(int row = 0; row < n; row += 1){
//    //printing digits
//    for(int digit = 0; digit < n - row; digit += 1){
//       cout<<n-row;

//       //If on last digit, do not print * after it
//       if(digit != n-row-1){
//          cout<<"*";
//       }

//       //print * after a digit
//       else{  }
//    }

//    cout<<endl;
// }

/*******************Alphabet Palindrome Pyramid***********************/
/*
A
ABA
ABCBA
ABCDCBA
*/
/*
First we will make code to print :
1
121
12321
1234321

Then we will map 1->A and 2->B and so on...
*/

// int n;
// cin>>n;
// for(int row = 0; row < n; row += 1){
//    //Seedhi Counting
//    for(int col = 0; col < row + 1; col += 1 ){
//       int answer = col + 1; //answer will be used to map counting to Alphabets
//       char ch = answer + 'A' - 1;
//       cout<<ch; 
//    }
   
//    //Reverse Counting
//    for(int col = row ; col > 0; col -= 1){
//       int answer = col; //answer will be used to map counting to Alphabets
//       char ch = answer + 'A' - 1 ;
//       cout<<ch;
//    }

//    cout<<endl;

// }

return 0;
}