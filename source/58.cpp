#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end,start;
        for(int i=s.length()-1;i>=0;i--)
            if(s[i]!=' '){
                end=i;
                break;
            }
        for(int i=end;i>=0;i--)
            if(s[i]==' '){
                start=i;
                break;
            }
        return end-start;
    }
};

int main(){
    string s="   fly me   to   the moon  ";
    Solution so;
    cout<<so.lengthOfLastWord(s)<<endl;
    return 0;
}