#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[8][1 << 8];
    int ans = 0;
    int dfs(vector<vector<int>> &students, vector<vector<int>> &mentors, int idx, int mask)
    {
        if (idx == students.size())
            return 0;
        if (dp[idx][mask] != -1)
            return dp[idx][mask];
        int ans = 0;
        for (int i = 0; i < mentors.size(); i++)
        {
            if (mask & (1 << i))
                continue;
            int marks = 0;
            for (int j = 0; j < students[0].size(); j++)
            {
                if (students[idx][j] == mentors[i][j])
                    marks++;
            }
            ans = max(ans, marks + dfs(students, mentors, idx + 1, mask | 1 << i));
        }
        return dp[idx][mask] = ans;
    }
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(students, mentors, 0, 0);
    }
};
int main()
{
    Solution s;
    vector<vector<int>> stu{{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> mentor{{1, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    cout << s.maxCompatibilitySum(stu, mentor) << endl;
}