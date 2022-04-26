#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         intervals.push_back(newInterval);
//         sort(intervals.begin(),intervals.end());
//         vector<vector<int>> ret;
//         for(int i=0;i<intervals.size();i++){
//             int start=intervals[i][0],finish=intervals[i][1];
//             if(ret.size()==0||(ret.back())[1]<start)ret.push_back({start,finish});
//             else if(ret.back()[1]<finish)ret.back()[1]=finish;
//         }
//         return ret;
//     }
// };
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int start=newInterval[0],finish=newInterval[1];
        int in=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>finish){
                if(!in){
                    ret.push_back({start,finish});
                    in=1;
                }
                ret.push_back(intervals[i]);
            }
            else if(intervals[i][1]<start)ret.push_back(intervals[i]);
            else{
                start=start<intervals[i][0]?start:intervals[i][0];
                finish=finish<intervals[i][1]?intervals[i][1]:finish;
            }
        }
        if(!in)ret.push_back({start,finish});
        return ret;
    }
};

int main(){
    vector<vector<int>> intervals;
    vector<int> newInterval;
    int n;
    int a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        intervals.push_back({a,b});
    }
    cin>>a>>b;
    newInterval.push_back(a);
    newInterval.push_back(b);
    Solution s;
    vector<vector<int>> ret=s.insert(intervals,newInterval);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i][0]<<" "<<ret[i][1]<<endl;
    }
    return 0;
}