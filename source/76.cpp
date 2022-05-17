#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    unordered_map< char, int > shs,ths;
    bool check(){
        for(auto item:ths){
            if(shs[item.first]<item.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        for(auto c:t)ths[c]++;
        int head=0,tail=0;//for search
        int minlen=s.length()+1;
        int retl=-1;//for record
        while(tail<s.size()){
            shs[s[tail]]++;
            while(check()&&head<=tail){
                if(tail-head+1<minlen){
                    minlen=tail-head+1;
                    retl=head;
                }
                shs[s[head]]--;
                head++;
            }
            tail++;
        }
        return retl==-1?"":s.substr(retl,minlen);
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    Solution res;
    cout<<res.minWindow(s,t);
    return 0;
}