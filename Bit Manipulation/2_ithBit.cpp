#include<iostream>
using namespace std;

//get ith bit
void getIthBit(int n, int i){
    int mask = (1<<i);
    int ans = n & mask;
    if(ans == 0){
        cout<<"ith bit 0"<<endl;
    }
    else{
        cout<<"ith bit 1"<<endl;
    }
}

//Setting ith bit means making ith bit 1
void setIthBit(int n, int i){
    int mask = (1<<i);
    n = n | mask;
    
    cout<<"n after setting ith bit: "<<n<<endl;
}

//Clearing ith bit means making ith bit 0
int clearIthBit(int n, int i){
    int mask = ~(1<<i);
    n = n & mask;
    cout<<"n after clearing ith bit: "<<n<<endl;

    return n;
}

//Update ith bit
void updateIthBit(int n, int i, int target){
    //Step1 : clear ith bit
    n = clearIthBit(n, i);

    //Step2 : create mask
    int mask = (target << i);

    //Step3 : update n
    n = n | mask;
    cout<<"Updated Number : "<<n<<endl;
}

//Clear last I bits
void clearLastIBits(int n, int i){
    // int mask = ((~0)<<i); //Method 2 to make mask
    int mask = (-1 << i);
    n = n & mask;
    cout<<"after clearing last i bits: "<<n<<endl;
}

int main(){
    int n = 10; //1010 in binary ; so 3rd bit is 1

    //Get ith bit
    int i = 3; //So get value of 3rd bit (0 indexed bits)
    getIthBit(n, i); //1 expected

    //Set ith bit
    int j = 2;
    setIthBit(n, j); //14 expected

    //Clear ith bit
    int k = 1;
    clearIthBit(n, k); //8 Expected

    //Update ith bit
    int l = 2;
    int target = 1;
    //Make lth bit 1
    updateIthBit(n, l, target); //14 expected
    
    //Make 3rd bit 0
    l = 3;
    target = 0;
    updateIthBit(n, l, target); //2 Expected

    //Clear last I bits
    int a = 15; //1111
    int m = 2;
    clearLastIBits(a, m); //12 Expected (1100 in binary)
return 0;
}