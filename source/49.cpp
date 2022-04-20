#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> record;
        vector<string>::iterator it;
        for(it=strs.begin();it!=strs.end();it++){
            string key=*it;
            sort(key.begin(),key.end());
            record[key].emplace_back(*it);
        }
        vector<vector<string>> ret;
        for (auto iter = record.begin(); iter != record.end(); ++iter) {
            ret.emplace_back(iter->second);
        }
        return ret;
    }
};

int main(){
    vector<string>alp;
    int n;
    string temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        alp.push_back(temp);
    }
    Solution s;
    vector<vector<string>>ans=s.groupAnagrams(alp);
    vector<vector<string>>::iterator it;
    vector<string>::iterator it2;
    for(it=ans.begin();it!=ans.end();it++){
        for(it2=it->begin();it2!=it->end();it2++){
            cout<<*it2<<" ";
        }
        cout<<endl;
    }
    return 0;
}