#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int head=0,tail=m-1;
        while(head<tail){
            int mid=(head+tail)/2;
            if(matrix[mid][0]<target){
                head=mid;
                if(matrix[mid+1][0]>target)break;
                else head++;
            }
            else if(matrix[mid][0]>target)tail=mid-1;
            else return true;
        }
        int left=0,right=n-1;
        while(left<right){
            int mid=(left+right)/2;
            if(matrix[head][mid]==target)return true;
            else if(matrix[head][mid]<target)left=mid+1;
            else right=mid-1;
        }
        if(matrix[head][left]==target)return true;
        else return false;
    }
};

int main(){
    int m,n,target;
    vector<vector<int> > matrix;
    cin>>m>>n>>target;
    for(int i=0;i<m;i++){
        int temp;
        for(int j=0;j<n;j++){
            cin>>temp;
            matrix[i].push_back(temp);
        }
    }
    Solution s;
    cout<<s.searchMatrix(matrix,target);
}