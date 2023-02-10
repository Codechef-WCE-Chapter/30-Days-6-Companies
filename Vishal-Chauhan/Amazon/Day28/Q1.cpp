#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.length();
        queue<int> r, d;
        for (int i = 0; i < n; i++)
        {
            senate[i] == 'R' ? r.push(i) : d.push(i);
        }
        int ra, da;
        while (!r.empty() && !d.empty())
        {
            ra = r.front();
            da = d.front();
            r.pop();
            d.pop();
            if (ra < da)
                r.push(ra + n);
            else
                d.push(da + n);
        }
        if (r.size() > d.size())
            return "Radiant";
        else
            return "Dire";
    }
};

int main()
{
    Solution s;
}