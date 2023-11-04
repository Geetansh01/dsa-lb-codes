#include<iostream>
#include<cmath>
using namespace std;

/******************************L103 : Integer to English Words[LeetCode : https://leetcode.com/problems/integer-to-english-words/description/]*****************************************/
//M1 : My approach (TC: O(N), SC: O(N)) (Same TC, SC as that of solution discussed in L103 so both codes are identical algo-wise just different implementations)

string helperRE(int x){
    //Base Case
    if(x <= 9){
        switch (x){
        case 9:
            return "Nine";
            break;
        case 8:
            return "Eight";
            break;
        case 7:
            return "Seven";
            break;
        case 6:
            return "Six";
            break;
        case 5:
            return "Five";
            break;
        case 4:
            return "Four";
            break;
        case 3:
            return "Three";
            break;
        case 2:
            return "Two";
            break;
        case 1:
            return "One";
            break;
        
        case 0:
        return "";
            break;
        }
    }


    //1 case
    string ans= "";
    if(x <= 19){
        switch (x){
        case 19:
            ans = "Nine";
            return ans.append("teen");
            break;
        case 18:
            ans = "Eigh";
            return ans.append("teen");
            break;
        case 17:
            ans = "Seven";
            return ans.append("teen");
            break;
        case 16:
            ans = "Six";
            return ans.append("teen");
            break;
        case 15:
            ans = "Fif";
            return ans.append("teen");
            break;
        case 14:
            ans = "Four";
            return ans.append("teen");
            break;
        case 13:
            ans = "Thir";
            return ans.append("teen");
            break;
        case 12:
            ans = "Twelve";
            return ans;
            break;
        case 11:
            ans = "Eleven";
            return ans;
            break;
        case 10:
            ans = "Ten";
            return ans;
            break;
        case 9:
            ans = helperRE(x);
            return ans;
            break;
        case 8:
            ans = helperRE(x);
            return ans;
            break;
        case 7:
            ans = helperRE(x);
            return ans;
            break;
        case 6:
            ans = helperRE(x);
            return ans;
            break;
        case 5:
            ans = helperRE(x);
            return ans;
            break;
        case 4:
            ans = helperRE(x);
            return ans;
            break;
        case 3:
            ans = helperRE(x);
            return ans;
            break;
        case 2:
            ans = helperRE(x);
            return ans;
            break;
        case 1:
            ans = helperRE(x);
            return ans;
            break;
        case 0:
            ans = helperRE(x);
            return ans;
            break;
        }
    }

    else if(x <= 99){
    int temp = x/10;
    int digit = x%10;
        switch (temp){
        case 9:
            ans = "Nine";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        case 8:
            ans = "Eigh";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        case 7:
            ans = "Seven";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        case 6:
            ans = "Six";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        case 5:
            ans = "Fif";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        case 4:
            ans = "For";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        case 3:
            ans = "Thir";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        case 2:
            ans = "Twen";
            return (digit != 0 ? ans.append("ty") + " " + helperRE(digit) : ans.append("ty") + helperRE(digit) );
            break;
        }
    }

    else if(x <= 999){
        int temp = x;
        int hundredth_place_digit = (x/10)/10;
        int remaining = 0;
        int POW_TEN = 1;
        for(int i = 0; i < 2; i++){
            int last_digit = (temp%10)*POW_TEN;
            POW_TEN = POW_TEN*10;
            temp = temp/10;
            remaining = remaining + last_digit;
        }

        switch(hundredth_place_digit){
            case 9:
                ans = ( remaining != 0 ? string("Nine") + " " +"Hundred" + " " + helperRE(remaining) : string("Nine") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 8:
                ans = ( remaining != 0 ? string("Eight") + " " +"Hundred" + " " + helperRE(remaining) : string("Eight") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 7:
                ans = ( remaining != 0 ? string("Seven") + " " +"Hundred" + " " + helperRE(remaining) : string("Seven") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 6:
                ans = ( remaining != 0 ? string("Six") + " " +"Hundred" + " " + helperRE(remaining) : string("Six") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 5:
                ans = ( remaining != 0 ? string("Five") + " " +"Hundred" + " " + helperRE(remaining) : string("Five") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 4:
                ans = ( remaining != 0 ? string("Four") + " " +"Hundred" + " " + helperRE(remaining) : string("Four") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 3:
                ans = ( remaining != 0 ? string("Three") + " " +"Hundred" + " " + helperRE(remaining) : string("Three") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 2:
                ans = ( remaining != 0 ? string("Two") + " " +"Hundred" + " " + helperRE(remaining) : string("Two") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
            case 1:
                ans = ( remaining != 0 ? string("One") + " " +"Hundred" + " " + helperRE(remaining) : string("One") + " " +"Hundred" + helperRE(remaining) ); 
                return ans;
                break;
        }
    }
    return ""; //Only added this bcz LeetCode kh ra tha non void function kuch return nhi kr rha (but actually beech me kr ra hai and LeetCode ko pta nhi :) )
}

string numberToWords(int num){
    if(num == 0) return "Zero";

    string ans = "";
    int i = 1;
    
    while(i<=4 && num>0){
        int extract = 0; //extract will be the last 3 digits of "num"

        //Run the loop maximum 3 times to extract the last 3 digits
        int POW_TEN = 1;
        for(int j = 0; j<3 && num>0; j++){
            int digit = (num%10) * POW_TEN;
            POW_TEN = POW_TEN*10;
            num = num/10;
            extract += digit;
        }

        if(extract == 0); // Do nothing
        else if(i == 1){
            ans = helperRE(extract);
        } 
        else if(i == 2){
            ans = helperRE(extract) + " " +"Thousand" + " " + ans;
        }
        else if(i == 3){
            ans = helperRE(extract) + " " +"Million" + " " + ans;
        }
        else if(i == 4){
            ans = helperRE(extract) + " " +"Billion" + " " + ans;
        }
        i++;
    }

    if(ans[ans.length()-1] == ' '){
        ans.pop_back();
    }

    return ans;

}

int main(){
    string ans = numberToWords(300);
    cout<<ans<<":::::::::::::::::"<<endl;
return 0;
}

