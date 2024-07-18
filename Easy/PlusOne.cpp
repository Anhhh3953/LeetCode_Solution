#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> PlusOne(vector<int> v)
    {
        //C1
        int transport = 1;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            v[i] = (v[i] + transport) % 10;
            transport = (v[i] == 0) ? 1 : 0; // ternary condition operator(?:) - a shorthand way of writing if-else condition
            // if v[i]==0 -> transport=1
            // else transport=0
            if (transport == 0)
                break;
        }
        if (transport == 1)
        {
            v.insert(v.begin(), 1);
        }
        return v;
    }
};
int main()
{
    Solution result;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> result_vector = result.PlusOne(v); // notice what will be returned in the given function
    for (int i = 0; i < result_vector.size(); i++)
    {
        cout << result_vector[i] << " ";
    }
    cout << endl;
    return 0;
}