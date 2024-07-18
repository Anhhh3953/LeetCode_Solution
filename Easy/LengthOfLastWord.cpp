#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty()) return 0;
        // C1:
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (isalpha(s[i]))
            {
                count++;
                if (i - 1 >= 0 && s[i - 1] == ' ')
                    break;
            }
        }
        return count;
        //C2:
        vector<string>v;
        stringstream ss(s);
        string tmp;
        while(ss>>tmp)
        {
            if(tmp!=' ')
            {
                v.push_back(tmp);
            }
        }
        return v.back().size();// v.back(): the last element in a vector
        //C3:
        int r,l;
        for(r=s.size()-1; r>=0; r--)
        {
            if(s[r]!=' ') break;
        }
        for(l=r; l>=0; l--)
        {
            if(s[l]==' ') break;
        }
        return r-l;
    }
};
int main()
{
    string s;
    getline(cin, s);
    Solution result;//Notice this one 
    cout << "Result = " << result.lengthOfLastWord(s) << endl;
    return 0;
}