#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN 201
char * longestCommonPrefix(char ** strs, int strsSize);
int main(){
    int size=0;
    scanf("%d",&size);
    char **inter=(char**)malloc(sizeof(char*)*size);
    for(int i=0;i<size;i++){
        char *temp=(char*)malloc(sizeof(char)*MAXLEN);
        memset(temp,0,MAXLEN);
        inter[i]=temp;
        scanf("%s",inter[i]);
    }
    printf("%s",longestCommonPrefix(inter,size));
    return 0;
}
char * longestCommonPrefix(char ** strs, int strsSize){
    char *ret=(char*)malloc(sizeof(char)*MAXLEN);
    memset(ret,0,MAXLEN);
    for(int j=0;j<strlen(strs[0]);j++){
        int flag=1;
        for(int k=1;k<strsSize;k++){
            if(strs[k][j]!=strs[0][j]){
                flag=0;
                break;
            }
        }
        if(flag){
            ret[j]=strs[0][j];
        }
        else break;
    }
    return ret;
}
//流氓做法
char * longestCommonPrefix(char ** strs, int strsSize){
    for(int j=0;j<strlen(strs[0]);j++){
        int flag=1;
        for(int k=1;k<strsSize;k++){
            if(strs[k][j]!=strs[0][j]){
                flag=0;
                break;
            }
        }
        if(!flag){
            strs[0][j]='\0';
            return strs[0];
        }
    }
    return strs[0];
}
//子串匹配
int find(char *s,char *item){
    if(!strstr(s,item))return 0;
    else return 1;
}
char * longestCommonPrefix(char ** strs, int strsSize){
    char *ret=(char*)malloc(sizeof(char)*MAXLEN);
    memset(ret,0,MAXLEN);
    int length=0,templen=0;
    for(int i=0;i<strlen(strs[0]);i++){
        for(int j=i;j<strlen(strs[0]);j++){
            templen=j-i+1;
            char *item=(char*)malloc(sizeof(char)*(templen+1));
            memset(item,0,templen+1);
            int idx=0;
            strncpy(item,strs[0],templen);
            int isfind=1;
            for(int k=1;k<strsSize;k++){
                isfind=isfind&&find(strs[k],item);
                if(!isfind)break;
            }
            if(isfind){
                if(templen>length){
                    strcpy(ret,item);
                    length=templen;
                }
            }
            else break;
        }
    }
    return ret;
}