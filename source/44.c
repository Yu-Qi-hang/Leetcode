#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum{false,true}bool;
// bool isMatch(char * s, char * p){
//     printf("%s\n%s\n",s,p);
//     if(s[0]=='\0'&&p[0]=='\0')return true;
//     else if(s[0]!='\0'&&p[0]!='\0'){
//         if(p[0]=='?'){
//             return isMatch(&s[1],&p[1]);
//         }
//         else if(p[0]=='*'){
//             if(p[1]=='\0')return true;
//             int idx=0;
//             while(p[idx+1]=='*')idx++;
//             if(isMatch(&s[0],&p[idx+1]))return isMatch(&s[0],&p[idx+1]);
//             else return isMatch(&s[1],&p[idx]);
//         }
//         else if(p[0]==s[0])return isMatch(&s[1],&p[1]);
//         else return false;
//     }
//     else if(s[0]=='\0'&&p[0]=='*'){
//         int idx=0;
//         while(p[idx]=='*')idx++;
//         if(p[idx]=='\0')return true;
//         else return false;
//     }
//     else return false;
// }

bool isMatch(char* s, char* p) {
    int m=strlen(s);
    int n=strlen(p);
    int **dp=(int**)malloc(sizeof(int*)*(m+1));
    for(int i=0;i<m+1;i++){
        dp[i]=(int*)malloc(sizeof(int)*(n+1));
        for(int j=0;j<n+1;j++)dp[i][j]=0;
    }
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        if(p[i-1]=='*')dp[0][i]=true;
        else break;
    }
    for(int i=1;i<=m;i++){
        for (int j=1;j<=n;j++) {
            if(p[j-1]=='*') {
                dp[i][j]=dp[i][j-1] | dp[i-1][j];
            } else if(p[j-1]=='?'){ 
                dp[i][j]=dp[i-1][j-1];
            }else if(s[i-1]==p[j-1]) {
                dp[i][j]=dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}

int main(){
    char s[2001],p[2001];
    memset(s,0,2001);
    memset(p,0,2001);
    scanf("%s %s",s,p);
    if(isMatch(s,p))printf("true");
    else printf("false");
    return 0;
}