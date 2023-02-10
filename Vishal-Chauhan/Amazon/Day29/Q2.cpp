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
    void ttlWay(int s, int e, int k, int &ans)
    {
        if (s == e && k == 0)
        {
            ans++;
            return;
        }
        else if (k == 0)
            return;

        ttlWay(s + 1, e, k - 1, ans);
        ttlWay(s - 1, e, k - 1, ans);
    }

    // -------------
    int WayDp(int start, int end, int k)
    {
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int j = -i; j <= i; j++)
            {
                int pos = start + j;
                if (abs(pos - end) <= i)
                {
                    dp[i]++;
                }
            }
        }
        return dp[k];
    }

    int numberOfWays(int start, int end, int k)
    {

        // int ans=0;
        // ttlWay(start,end,k,ans);
        // return ans;
        // ------------------
        return WayDp(start, end, k);
    }
};
int main()
{
    Solution s;
}