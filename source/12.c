#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
char * intToRoman(int num);
int main(){
    int num;
    scanf("%d",&num);
    printf("%s",intToRoman(num));
    return 0;
}
char * intToRoman(int num){
    char *ret=(char*)malloc(sizeof(char)*20);
    memset(ret,0,20);
    int tail=0;
    int slice=0;
    if(num>=1000){
        slice=num/1000;
        while(slice-->0)ret[tail++]='M';
    }
    num=num%1000;
    if(num>=100){
        slice=num/100;
        if(slice>=5){
            if(slice==9){
                ret[tail++]='C';
                ret[tail++]='M';
                slice=0;
            }
            else{
                ret[tail++]='D';
                slice-=5;
            }
        }
        if(slice==4){
            ret[tail++]='C';
            ret[tail++]='D';
            slice=0;
        }
        else{
            while(slice-->0)ret[tail++]='C';
        }
    }
    num=num%100;
    if(num>=10){
        slice=num/10;
        if(slice>=5){
            if(slice==9){
                ret[tail++]='X';
                ret[tail++]='C';
                slice=0;
            }
            else{
                ret[tail++]='L';
                slice-=5;
            }
        }
        if(slice==4){
            ret[tail++]='X';
            ret[tail++]='L';
            slice=0;
        }
        else{
            while(slice-->0)ret[tail++]='X';
        }
    }
    num=num%10;
    if(num>=1){
        slice=num;
        if(slice>=5){
            if(slice==9){
                ret[tail++]='I';
                ret[tail++]='X';
                slice=0;
            }
            else{
                ret[tail++]='V';
                slice-=5;
            }
        }
        if(slice==4){
            ret[tail++]='I';
            ret[tail++]='V';
            slice=0;
        }
        else{
            while(slice-->0)ret[tail++]='I';
        }
    }
    return ret;
}