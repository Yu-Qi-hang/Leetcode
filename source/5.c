#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * longestPalindrome(char * s);
int check(char *s,int start,int end);
int main(){
    char s[1001];
    memset(s,0,1001);
    scanf("%s",&s);
    char *p=longestPalindrome(s);
    printf("%s",p);
    return 0;
}
/*solution1*/
// int check(char *s,int start,int end){
//     int i;
//     for(i=0;i<=(end-start)/2;i++){
//         if(s[start+i]!=s[end-i])return 0;
//     }
//     return 1;
// }
// char * longestPalindrome(char * s){
//     int a1=0,a2=0;
//     int length=1;
//     int len=strlen(s);
//     int start=0,end=len-1;
//     while(start<len-length){
//         while(start<end-length+1){
//             if(check(s,start,end)){
//                 a1=start;
//                 a2=end;
//                 length=end-start+1;
//                 break;
//             }
//             end--;
//         }
//         end=len-1;
//         start++;
//     }
//     char *ret=(char*)malloc(sizeof(char)*(length+1));
//     for(int i=a1;i<=a2;i++)ret[i-a1]=s[i];
//     ret[length]='\0';
//     return ret;
// }
/*solution2*/
char * longestPalindrome(char * s){
    int a1=0,a2=0;
    int length=1;
    int len=strlen(s);
    int start=0,end=len-1;
    int flag=1;
    while(start<len-length){
        while(end-start+1>length){
            for(int i=0;i<=(end-start)/2;i++){
                if(s[start+i]!=s[end-i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                a1=start;
                a2=end;
                length=end-start+1;
                break;
            }
            end--;
            flag=1;
        }
        end=len-1;
        start++;
        flag=1;
    }
    char *ret=(char*)malloc(sizeof(char)*(length+1));
    for(int i=a1;i<=a2;i++)ret[i-a1]=s[i];
    ret[length]='\0';
    return ret;
}