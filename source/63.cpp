#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        obstacleGrid[0][0]=1-obstacleGrid[0][0];
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i])obstacleGrid[0][i]=0;
            else{
                obstacleGrid[0][i]=obstacleGrid[0][i-1];
            }
        }
        for(int j=1;j<m;j++){
            if(obstacleGrid[j][0])obstacleGrid[j][0]=0;
            else{
                obstacleGrid[j][0]=obstacleGrid[j-1][0];
            }
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j])obstacleGrid[i][j]=0;
                else{
                    obstacleGrid[i][j]=obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
                }
            }
        return obstacleGrid[m-1][n-1];
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
    cout<<s.uniquePathsWithObstacles(obstacleGrid);
    return 0;
}