#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        string head;
        int i=0;
        while(i<s.size()&&s[i]!='e'&&s[i]!='E'){
            i++;
        }
        head=s.substr(0,i);
        if(i==s.size()){
            return isinteger(head)||isdecimal(head);
        }
        else{
            i++;
            string tail;
            tail=s.substr(i);
            return (isinteger(head)||isdecimal(head))&&isinteger(tail);
        }
    }
    bool isinteger(string s){
        if(s.size()==0)return false;
        if(s[0]=='+'||s[0]=='-'){
            if(s.size()==1||s[1]=='+'||s[1]=='-')return false;
            else return isinteger(&s[1]);
        }
        else{
            for(int i=0;i<s.size();i++){
                if(s[i]>='0'&&s[i]<='9')continue;
                else return false;
            }
            return true;
        }
    }
    bool isdecimal(string s){
        if(s.size()==0)return false;
        if(s[0]=='+'||s[0]=='-'){
            if(s.size()==1||s[1]=='+'||s[1]=='-')return false;
            else return isdecimal(&s[1]);
        }
        else{
            string head;
            int i=0;
            while(i<s.size()&&s[i]!='.')i++;
            if(i==0&&s[0]=='.'){
                if(s[1]=='+'||s[1]=='-')return false;
                return isinteger(&s[1]);
            }
            else if(i==s.size()){
                head=s.substr(0,i);
                return isinteger(head);
            }
            else{
                if(s[i]!='.')return false;
                head=s.substr(0,i);
                if(i==s.size()-1)return isinteger(head);
                string tail=s.substr(i+1);
                if(tail[0]=='+'||tail[0]=='-')return false;
                return isinteger(head)&&isinteger(tail);
            }
        }
    }
};

int main(){
    string s;
    cin>>s;
    Solution ret;
    cout<<ret.isNumber(s);
    return 0;
}