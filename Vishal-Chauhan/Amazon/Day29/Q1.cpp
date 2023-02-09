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
    int Dp(string s1, string s2)
    {
        int l1 = s1.length(), l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 0; i <= l1; i++)
        {
            for (int j = 0; j <= l2; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1][l2];
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        for (auto w : words)
        {
            int len = Dp(s, w);
            if (len == w.length())
                ans++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
}