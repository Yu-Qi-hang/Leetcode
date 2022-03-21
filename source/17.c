#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char ** letterCombinations(char * digits, int* returnSize);
int main(){
    char s[5];
    int returnSize=0;
    printf("Input a digit string within 4 letters:");
    scanf("%s",&s);
    char **ret=letterCombinations(s,&returnSize);
    for(int i=0;i<returnSize;i++)
        printf("%s\n",ret[i]);
    return 0;
}
char ** letterCombinations(char * digits, int* returnSize){
    if(digits[0]=='\0'){
        *returnSize=0;
        return NULL;
    }
    *returnSize=1;
    char imp[9]="adgjmptw";
    int length=strlen(digits);
    for(int i=0;i<length;i++){
        if(digits[i]=='7'||digits[i]=='9')(*returnSize)*=4;
        else (*returnSize)*=3;
    }
    char **ret=(char**)malloc(sizeof(char*)*(*returnSize));
    for(int i=0;i<*returnSize;i++){
        ret[i]=(char*)malloc(sizeof(char)*(length+1));
        ret[i][length]='\0';
    }
    int batch=1;
    for(int i=0;i<length;i++){
        int mode=3;
        int k=0;
        int offset=0;
        if(digits[i]=='7'||digits[i]=='9')mode=4;
        for(int j=0;j<*returnSize;j++){
            k=j;
            while(k-j<batch){
                ret[k][i]=imp[digits[i]-'2']+offset;
                k++;
            }
            j=k-1;
            offset=(offset+1)%mode;
        }
        batch*=mode;
    }
    return ret;
}