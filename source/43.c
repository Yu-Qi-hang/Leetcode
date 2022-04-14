#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *reverse(char *in){
    int right=strlen(in)-1;
    int left=0;
    while(left<right){
        char temp=in[left];
        in[left]=in[right];
        in[right]=temp;
        left++;
        right--;
    }
    return in;
}
char *rightshift(char*in){
    int idx=strlen(in);
    char *ret=(char*)malloc(sizeof(char)*(idx+2));
    ret[0]='0';
    strcpy(&ret[1],in);
    return ret;
}
char * submultiply(char *num, int a){//传入是倒过来的//输出也是倒过来的
    int len=40001;
    char *ret=(char*)malloc(sizeof(char)*len);
    memset(ret,0,len);
    int up=0;
    int i=0;
    for(i=0;i<strlen(num);i++){
        int result=(num[i]-'0')*a+up;
        up=result/10;
        ret[i]=result%10+'0';
    }
    if(up!=0)ret[i]=up+'0';
    while(ret[i]=='0'&&i>0){
        ret[i]='\0';
        i--;
    }
    return ret;
}
char * add(char* num1,char* num2){//传入是倒过来的//输出也是倒过来的
    int len=(strlen(num1)>strlen(num2)?strlen(num1):strlen(num2))+2;
    char *ret=(char*)malloc(sizeof(char)*len);
    memset(ret,0,len);
    int up=0;
    int idx=0;
    int sum;
    while(num1[idx]!='\0'&&num2[idx]!='\0'){
        sum=(num1[idx]-'0')+(num2[idx]-'0')+up;
        up=sum/10;
        ret[idx]=sum%10+'0';
        idx++;
    }
    while(num1[idx]!='\0'){
        sum=up+num1[idx]-'0';
        up=sum/10;
        ret[idx]=sum%10+'0';
        idx++;
    }
    while(num2[idx]!='\0'){
        sum=up+num2[idx]-'0';
        up=sum/10;
        ret[idx]=sum%10+'0';
        idx++;
    }
    if(up!=0)ret[idx]=up+'0';
    return ret;
}
char * multiply(char * num1, char * num2){
    int len1=strlen(num1),len2=strlen(num2);
    char *re=(char*)malloc(sizeof(char)*(len1+len2+2));
    memset(re,0,len1+len2+2);
    int up=0,idx=0;
    char *temp;
    num1=reverse(num1);
    while(idx<len2){
        if(idx!=0&&!(re[0]=='0'&&re[1]=='\0'))re=rightshift(re);
        temp=submultiply(num1,num2[idx]-'0');
        re=add(re,temp);
        free(temp);
        idx++;
    }
    int i=strlen(re)-1;
    while(re[i]=='0'&&i>0){
        re[i]='\0';
        i--;
    }
    re=reverse(re);
    return re;
}
int main(){
    char num1[201]={0},num2[201]={0};
    scanf("%s %s",num1,num2);
    printf("%s",multiply(num1,num2));
    return 0;
}