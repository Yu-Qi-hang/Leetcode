#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ret;
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0],finish=intervals[i][1];
            if(ret.size()==0||(ret.back())[1]<start)ret.push_back({start,finish});
            else if(ret.back()[1]<finish)ret.back()[1]=finish;
        }
        return ret;
    }
};

int main(){
    vector<vector<int>> intervals;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        intervals.push_back({a,b});
    }
    Solution s;
    vector<vector<int>> ret=s.merge(intervals);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i][0]<<" "<<ret[i][1]<<endl;
    }
    return 0;
}