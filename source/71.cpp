#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    vector<string> split(string &path){
        string temp;
        vector<string> ret;
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
                if(!temp.empty()){
                    ret.push_back(temp);
                    temp.clear();
                }
            }
            else{
                temp+=path[i];
            }
        }
        if(!temp.empty())ret.push_back(temp);
        return ret;
    }
    string simplifyPath(string path) {
        string ret="";
        vector<string> stack;
        vector<string> tokens=split(path);
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]==".")continue;
            else if(tokens[i]==".."){
                if(!stack.empty())stack.pop_back();
            }
            else{
                stack.push_back(tokens[i]);
            }
        }
        for(int i=0;i<stack.size();i++){
            ret+="/"+stack[i];
        }
        if(!ret.length())ret+="/";
        return ret;
    }
};

int main(){
    string path;
    cin>>path;
    Solution s;
    cout<<s.simplifyPath(path);
    return 0;
}