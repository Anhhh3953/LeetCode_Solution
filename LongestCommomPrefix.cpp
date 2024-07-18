// "reflight, flore, flight" ->" " running from index 0
// " flower, flore, flight "-> " fl "
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=0;
        /*C1: int pos=0;
        while(pos<strs[0].size())
        {
            char tmp=strs[0][pos];
            bool flag=true;
            for(int i=1; i<strs.size(); i++)
            {
                if(strs[i][pos]!=tmp)
                {
                    flag = false;
                    break;
                }
            }
            if(!flag)
            {
                break;
            }
            len++;
            pos++;
        }*/
        /* C2: for(int pos=0; ; pos++)
        {
            char tmp;
            if(pos<strs[0].size())
            {
                tmp=v[0][pos];
            }
            else{
                break;
            }
            bool flag=true;
            for(int i=1; i<strs.size(); i++)
            {
                if(strs[i][pos]!=tmp)
                {
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
            len++;
        }
        return strs[0].substr(0,len);
        */
        /* C2:if(strs.empty) return "";
        string prefix= strs[0];
        for(string s: strs)
            while(s.find(prefix)!=0)
                prefix=prefix.substr(0,prefix.length()-1);
        return prefix;
        */
       // C5:
       if(strs.empty()) return "";
       string prefix="";
       sort(strs.begin(), strs.end());
       string first=v[0];
       string last=v[n-1];
       for(int i=0; i<min(first.size(), last.size()); i++)
       {
            if(first[i]==last[i])
            {
                prefix.push_back(first[i]);
            }
            else{
                return prefix;
            }
       }
       return prefix;
    }
};
int main(){
    vector<string> strs;
    string s;
    int n; 
    cin>>n;
    for(int i=0; i<n; i++)
    {
        getline(cin,s);
        strs.push_back(s);
    }
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}