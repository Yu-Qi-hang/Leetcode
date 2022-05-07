#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]=digits[i]+carry;
            carry=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        if(digits[0]==0)digits.insert(digits.begin(),1);
        return digits;
    }
};

int main(){
    int n,temp;
    cin>>n;
    vector<int> digits;
    for(int i=0;i<n;i++){
        cin>>temp;
        digits.push_back(temp);
    }
    Solution s;
    vector<int> result=s.plusOne(digits);
    for(int i=0;i<result.size();i++)cout<<result[i]<<" ";
    return 0;
}