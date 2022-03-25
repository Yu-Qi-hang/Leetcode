#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ** generateParenthesis(int n, int* returnSize);
char ** generate(char **ret,char *temp,int left,int right,int n,int *returnSize,int *batch);
int main(){
    int n=0;
    int returnSize[]={0};
    scanf("%d",&n);
    char **tuple=generateParenthesis(n,returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%s\n",tuple[i]);
    }
    return 0;
}

char ** generate(char **ret,char *temp,int left,int right,int n,int *returnSize,int *batch){
    if(left==n&&right==n){
        if(*batch==*returnSize){
            (*batch)*=2;
            ret=(char**)realloc(ret,sizeof(char*)*(*batch));
        }
        ret[*returnSize]=temp;
        (*returnSize)++;
    }
    else{
        if(left>right){
            char *new=(char*)malloc(sizeof(char)*(2*n+1));
            memset(new,0,2*n+1);
            strcpy(new,temp);
            new[strlen(temp)]=')';
            ret=generate(ret,new,left,right+1,n,returnSize,batch);
        }
        if(left<n){
            char *newnew=(char*)malloc(sizeof(char)*(2*n+1));
            memset(newnew,0,2*n+1);
            strcpy(newnew,temp);
            newnew[strlen(temp)]='(';
            ret=generate(ret,newnew,left+1,right,n,returnSize,batch);
        }
    }
    return ret;
}
char ** generateParenthesis(int n, int* returnSize){    
    int returnsize=0;
    int batch=5;
    char **ret=(char**)malloc(sizeof(char*)*batch);
    ret=generate(ret,"",0,0,n,&returnsize,&batch);
    *returnSize=returnsize;
    return ret;
}
