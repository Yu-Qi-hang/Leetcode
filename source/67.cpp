#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lena=a.length()-1,lenb=b.length()-1;
        string sum;
        int carry=0;
        int add=a[lena]-'0'+b[lenb]-'0';
        while(lena>=0||lenb>=0){
            if(add==0){
                sum.insert(sum.begin(),'0');
                carry=0;
            }
            else if(add==1){
                sum.insert(sum.begin(),'1');
                carry=0;
            }
            else if(add==2){
                sum.insert(sum.begin(),'0');
                carry=1;
            }
            else if(add==3){
                sum.insert(sum.begin(),'1');
                carry=1;
            }
            if(lena>0&&lenb>0){
                lena--;
                lenb--;
                add=a[lena]-'0'+b[lenb]-'0'+carry;
            }
            else if(lena>0){
                lena--;
                add=a[lena]-'0'+carry;
            }
            else if(lenb>0){
                lenb--;
                add=b[lenb]-'0'+carry;
            }
            else break;
        }
        if(carry)sum.insert(sum.begin(),'1');
        return sum;
    }
};

int main(){
    string a,b;
    cin>>a>>b;
    Solution s;
    string sum=s.addBinary(a,b);
    cout<<sum;
    return 0;
}