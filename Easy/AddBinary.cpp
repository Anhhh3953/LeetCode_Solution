#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string AddBinary(string a, string b)
    {
        // C1:
        char carry = '0';
        int max_length = max(a.size(), b.size());
        if (a.size() < b.size())
            a = string(b.size() - a.size(), '0') + a;
        if (a.size() > b.size())
            b = string(a.size() - b.size(), '0') + b;
        string result(max_length, '0'); // must be like this because i use the index of result later
        for (int i = max_length - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0')
            {
                if (carry == '0')
                    result[i] = '0';
                else
                    result[i] = '1';
                carry = '0';
            }
            if (a[i] == '0' && b[i] == '1' || a[i] == '1' && b[i] == '0')
            {
                if (carry == '0')
                {
                    result[i] = '1';
                    carry = '0';
                }
                else
                {
                    result[i] = '0';
                    carry = '1';
                }
            }
            if (a[i] == '1' && b[i] == '1')
            {
                if (carry == '0')
                {
                    result[i] = '0';
                    carry = '1';
                }
                else
                {
                    result[i] = '1';
                    carry = '1';
                }
            }
        }
        if (carry == '1')
            result.insert(result.begin(), '1');
        return result;
        // C2:
        string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry == 1)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            result += carry % 2 + '0';
            carry /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
        // C3:???
    }
};
int main()
{
    Solution result;
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);
    string rl = AddBinary(a, b);
    for (int i = 0; i < rl.size(); i++)
    {
        cout << rl[i];
    }
    return 0;
}