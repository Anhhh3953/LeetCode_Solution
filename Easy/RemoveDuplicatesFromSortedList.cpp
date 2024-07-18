#include<iostream>
using namespace std;
class Solution{
    public:
    int RemoveDuplicates (vector<int>&v)
    {
        //C1:
        set<int>s;
        for(int c:v)
        {
            s.insert(c);
        }
        v.clear();
        for(int x:s)
        {
            v.push_back(x);
        }
        return v.size();
        //C2:
        int index=0;
        for(int i=1; i<v.size(); i++)
            if(v[i]!=v[index]);
                v[++index]=v[i];
        return index++;
        //C3:
        for(int i=1; i<v.size(); i++)
        {
            if(v[i]==v[i-1])
            {
                v.erase(v.begin()+i);
                i--;// notice this guy 
            }
            return v.size();
        }

    }

};
int main()
{
    vector<int>v;
    int n;
    cin>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
    }
    cout<RemoveDuplicates(v)<<endl;
    return 0;

}