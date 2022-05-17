#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void back(vector<vector<int>> &result, vector<int>&temp, int k,int n,int idx){
        if(idx==k){
            result.push_back(temp);
            return;
        }
        else{
            for(int i=temp[idx-1]+1;i<=n-k+1+idx;i++){
                temp.push_back(i);
                back(result,temp,k,n,idx+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> temp;
        int idx=0;
        for(int i=1;i<=n-k+1;i++){
            temp.push_back(i);
            back(result,temp,k,n,idx+1);
            temp.pop_back();
        }
        return result;
    }
};


int main(){
    int n,k;
    cin>>n>>k;
    Solution s;
    vector<vector<int> > result=s.combine(n,k);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}