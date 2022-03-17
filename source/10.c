#include<stdio.h>
#include<string.h>
#define bool int
#define false 0
#define true 1

bool isMatch(char * s, char * p);
int expindex(char *s,char c){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]!=c)return i;
        i++;
    }
    return -1;
}
int main(){
    char s[21],p[31];
    memset(s,0,21);
    memset(p,0,31);
    scanf("%s",&s);
    scanf("%s",&p);
    if(isMatch(s,p))printf("true");
    else printf("false");
    return 0;
}
bool isMatch(char * s, char * p){
    printf("%s\n%s\n\n",s,p);
    if(p[0]=='\0'&&s[0]=='\0')return true;
    if(p[0]=='\0'&&s[0]!='\0')return false;
    if(p[0]!='\0'&&s[0]=='\0'){
        if(p[1]=='*')return isMatch(&s[0],&p[2]);
        else return false;
    }
    if(p[1]!='*'&&p[0]!='.'){
        if(s[0]==p[0])return isMatch(&s[1],&p[1]);
        else return false;
    }
    else if(p[1]=='*'&&p[0]!='.'){
        if(s[0]!=p[0])return isMatch(&s[0],&p[2]);
        if(p[2]==p[0]){
            if(p[3]!='*'){
                p[1]=p[0];
                p[2]='*';            
                return isMatch(&s[1],&p[1]);
            }
            else{
                return isMatch(&s[0],&p[2]);
            }
        }
        else{
            if(p[2]=='\0'){
                int idx=expindex(&s[0],p[0]);
                if(idx==-1)return true;
                else return false;
            }
            else if(p[3]!='*'){
                int idx=expindex(&s[0],p[0]);
                if(idx==-1)return false;
                else{
                    bool ret=isMatch(&s[idx],&p[2]);
                    for(int temp=0;temp<idx;temp++){
                        ret=ret|isMatch(&s[temp],&p[2]);
                    }
                    return ret;
                }
            }
            else{
                int idx=expindex(&s[0],p[0]);
                if(idx==-1){
                    p[2]=p[0];
                    return isMatch(&s[0],&p[2]);
                }
                else{
                    bool ret=isMatch(&s[idx],&p[2]);
                    for(int temp=0;temp<idx;temp++){
                        ret=ret|isMatch(&s[temp],&p[2]);
                    }
                    return ret;
                }
            }
        }
    }
    else if(p[1]=='*'&&p[0]=='.'){
        bool ret=false;
        if(p[2]=='\0')return true;
        else if(p[2]=='.'){
            if(p[3]!='*'){
                p[1]=p[0];
                p[2]='*';
                return isMatch(&s[1],&p[1]);
            }
            else return isMatch(&s[1],&p[2]);
        }
        else{
            if(p[3]=='*'){
                p[2]='.';
                return isMatch(&s[0],&p[2]);
            }
            int j=0;
            int flag=1;
            while(s[j]!='\0'){
                if(s[j]==p[2]){
                    ret=ret|isMatch(&s[j],&p[2]);
                    flag*=0;
                }
                j++;
            }
            return (1-flag)*ret;
        }
    }
    else{//p[1]!='*'&&p[0]=='.'
        return isMatch(&s[1],&p[1]);
    }
}