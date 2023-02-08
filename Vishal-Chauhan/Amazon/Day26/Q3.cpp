#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int count = 0;
    void helper(set<string> &m, string s, string d)
    {
        if (s.empty())
        {
            int len = m.size();
            count = max(count, len);
            return;
        }

        for (int i = 0; i < s.length(); i++)
        {
            d = s.substr(0, i + 1);
            if (m.find(d) == m.end())
            {
                m.insert(d);
                helper(m, s.substr(i + 1), d);
                m.erase(d);
            }
        }
        return;
    }
    int maxUniqueSplit(string s)
    {
        set<string> m;
        string d;
        helper(m, s, d);
        return count;
    }
};
int main()
{
    Solution s;
}