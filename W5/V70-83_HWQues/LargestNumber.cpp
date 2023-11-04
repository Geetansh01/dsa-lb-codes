#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cc(string s1, string s2){
    //Handling Equal Numbers
    if(s1.compare(s2) == 0){
        return true;
    }

    int i=0, j=0;
    //Handlling Unequal Numbers 
    while(true){
        if(i >= s1.size()){
            i = 0;
        }
        if(j >= s2.size()){
            j = 0;
        }

        //Now the comparison starts
        if(s1[i] > s2[j]){
            return true;
        }
        else if(s1[i] == s2[j]){
            i++; 
            j++;
        }
        else{
            return false;
        }
    }
}

string largestNumber(vector<int>& nums) {
    string ans;
    vector<string> vec;

    for(int i = 0; i < nums.size(); i++){
        string temp;

        //Converting multiple digit numbers to string
        if(nums[i]>9){
            while(nums[i]>0){
                char digit = (nums[i]%10) + ('1'-1);
                temp.push_back(digit);
                nums[i] = nums[i]/10;
            }
            reverse(temp.begin(), temp.end());
        }
        else{
            temp.push_back(nums[i] + ('1'-1));
        }

        //Making vector identical to nums but storing "int" as "string"
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end(), cc);
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size(); j++){
            ans.push_back(vec[i][j]);
        }
    }

    return ans;
}


int main(){
 vector<string> arr = {"3", "3"};
 sort(arr.begin(), arr.end(), cc);
// string ans = largestNumber(arr);

 for(auto iter : arr){
    cout<<iter<<" ";
 }

// cout<<ans;
   
return 0;
}