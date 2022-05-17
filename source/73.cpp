#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int col_zero=0,row_zero=0;
        for(int i=0;i<m;i++){
            if(!matrix[i][0]){
                col_zero=1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(!matrix[0][i]){
                row_zero=1;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!matrix[i][j]){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!matrix[i][0]||!matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
        }
        if(col_zero)for(int i=0;i<m;i++)matrix[i][0]=0;
        if(row_zero)for(int i=0;i<n;i++)matrix[0][i]=0;
        return;        
    }
};

int main(){
    vector<vector<int> > matrix;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            matrix[i].push_back(temp);
        }
    }
    Solution s;
    s.setZeroes(matrix);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}