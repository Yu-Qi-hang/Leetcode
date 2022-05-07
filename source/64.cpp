#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=1;i<n;i++)grid[0][i]+=grid[0][i-1];
        for(int i=1;i<m;i++)grid[i][0]+=grid[i-1][0];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+=(grid[i-1][j]<grid[i][j-1])?grid[i-1][j]:grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};

int main(){
    vector<vector<int> > obstacleGrid;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int> B;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            B.push_back(temp);
        }
        obstacleGrid.push_back(B);
    }
    Solution s;
    cout<<s.minPathSum(obstacleGrid);
    return 0;
}