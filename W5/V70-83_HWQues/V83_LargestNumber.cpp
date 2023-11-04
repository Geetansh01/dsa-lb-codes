#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*****************Q 83 : Largest Number[LeetCode : https://leetcode.com/problems/largest-number/description/]****************************************/

bool cc(string s1, string s2){
    string t1 = s1+s2;
    string t2 = s2+s1;
    return (t1 > t2) ? true : false;

    //Or use the more elaborate version below 
    // if(t1 > t2){
    //     return true;
    // }
    // else{
    //     return false;
    // }
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

    //If 0 is the largest Number then return just "0" (LeetCode marks WRONG if "00" is returned)
    if(vec[0] == "0"){
        return "0";
    }

    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size(); j++){
            ans.push_back(vec[i][j]);
        }
    }

    return ans;
}


int main(){
    vector<int> nums = {3,30,34,5,9};
    string answer = largestNumber(nums);

    cout<<answer<<endl;
       
return 0;
}