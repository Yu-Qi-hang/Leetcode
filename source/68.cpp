#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curlen=0;
        int idx=0;
        int head=0;
        int idxlen=0;
        string temp;
        vector<string> lines;
        while(idx<words.size()){
            idxlen=words[idx].length();
            if(curlen==0){
                curlen+=idxlen;
                idx++;
            }
            else if(idxlen+curlen+1<=maxWidth){
                curlen+=idxlen+1;
                idx++;
            }
            else{
                int num_space=idx-head-1;
                int space=maxWidth-curlen+num_space;
                temp=words[head];
                int i=head+1;
                while(num_space>0){
                    int thespace;
                    if(space%num_space)thespace=space/num_space+1;
                    else thespace=space/num_space;      
                    string ad (thespace,' ');
                    temp+=ad;
                    temp+=words[i++];
                    space-=thespace;
                    num_space-=1;              
                }
                if(space){
                    string ad (space,' ');
                    temp+=ad;
                }
                lines.push_back(temp);
                head=idx;
                curlen=0;
            }
        }
        int num_space=idx-head-1;
        int space=maxWidth-curlen+num_space;
        temp=words[head];
        int i=head+1;
        while(num_space>0){    
            temp+=" ";
            temp+=words[i++];
            space-=1;
            num_space-=1;              
        }
        if(space){
            string ad (space,' ');
            temp+=ad;
        }
        lines.push_back(temp);
        return lines;
    }
};

int main(){
    vector<string> words;
    string word;
    int num=0,maxwidth=0;
    cin>>num>>maxwidth;
    while(num>0){
        cin>>word;
        words.push_back(word);
        num--;
    }
    Solution s;
    vector<string> lines=s.fullJustify(words,maxwidth);
    for(int i=0;i<lines.size();i++){
        cout<<lines[i]<<endl;
    }
    return 0;
}