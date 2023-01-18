
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
using namespace std;
#define ll long long
class Solution
{
public:
    int countBits(int mask)
    {
        int cnt = 0;
        while (mask)
        {
            cnt += mask & 1;
            mask >>= 1;
        }
        return cnt;
    }
    int isGood(int mask, int i)
    {
        return mask & (1 << i);
    }
    int maximumGood(vector<vector<int>> &statements)
    {
        int n = statements.size();
        int mask = 1 << n;
        int ans = 0;
        for (int s = mask - 1; s >= 0; --s)
        {
            int isValid = true;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (isGood(s, i))
                    {
                        if ((statements[i][j] == 0 && isGood(s, j)) || (statements[i][j] == 1 && !isGood(s, j)))
                        {
                            isValid = false;
                            break;
                        }
                    }
                }
                if (!isValid)
                    break;
            }
            if (isValid)
            {
                ans = max(ans, countBits(s));
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> statements = {{2, 1, 2}, {1, 2, 2}, {2, 0, 2}};
    Solution s;
    cout << s.maximumGood(statements) << endl;
}