#include<iostream>
using namespace std;

void printSubSequences(string str, string output, int i){
    //base case
    if(i >= str.length()){
        cout<<output<<endl;
        return;
    }

    //exclude
    printSubSequences(str, output, i+1);  //WRONG : " return printSubSequences(str, output, i+1)" (Run code with this to see why!)

    //include
    output.push_back(str[i]);
    printSubSequences(str, output, i+1); //WRONG : " return printSubSequences(str, output, i+1)"

}

int main(){
   string str = "abc";
   string output = "";

   int i = 0;
   printSubSequences(str, output, i);
return 0;
}