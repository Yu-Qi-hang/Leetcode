#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0,p1=nums.size()-1;
        for(int i=0;i<=p1;i++){
            while(p1>i&&nums[i]==2){
                swap(nums[i],nums[p1]);
                p1--;
            }
            if(nums[i]==0){
                swap(nums[p0],nums[i]);
                p0++;
            }
        }
    }
};

int main(){
    int m;
    cin>>m;
    vector<int> nums;
    int temp;
    while(m>0){
        cin>>temp;
        nums.push_back(temp);
        m--;
    }
    Solution s;
    s.sortColors(nums);
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    return 0;
}