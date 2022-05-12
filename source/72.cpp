#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        int dp[m+1][n+1];
        for(int i=0;i<n;i++)dp[0][i]=i;
        for(int j=0;j<m;j++)dp[j][0]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int left=dp[j][i-1]+1;
                int up=dp[j-1][i]+1;
                int dig=dp[j-1][i-1];
                if(word2[i-1]!=word1[j-1])dig++;
                dp[j][i]=min(left,min(up,dig));
            }
        }
        return dp[m][n];
    }
};

int main(){
    string word1,word2;
    cin>>word1>>word2;
    Solution s;
    cout<<s.minDistance(word1,word2);
    return 0;
}