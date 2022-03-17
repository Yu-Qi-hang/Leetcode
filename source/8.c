#include<stdio.h>
#include<string.h>
#define up 2147483647
#define bottom -2147483648
#define MAX 201
int myAtoi(char * s);
int main(){
    char read[MAX];
    memset(read,0,MAX);
    scanf("%s",read);
    printf("%d",myAtoi(read));
    return 0;
}
int myAtoi(char * s){
    int ret=0;
    int flag=1;
    int index=0;
    int cnt=0;
    while(s[index]&&s[index]==' ')index++;
    if(s[index]=='+'){
        index++;
        cnt++;
    }
    else if(s[index]=='-'){
        index++;
        flag=-1;
        cnt++;
    }
    if(cnt>1)return 0;
    if(flag>0){
        while(s[index]>='0'&&s[index]<='9'){
            if(ret<up/10)ret=ret*10+(s[index++]-'0');
            else if(ret==up/10){
                if(s[index]<='7')ret=ret*10+(s[index++]-'0');
                else return up;
            }
            else return up;
        }
    }
    else{
        while(s[index]>='0'&&s[index]<='9'){
            if(ret>bottom/10)ret=ret*10-(s[index++]-'0');
            else if(ret==bottom/10){
                if(s[index]<='8')ret=ret*10-(s[index++]-'0');
                else return bottom;
            }
            else return bottom;
        }
    }
    return ret;
}