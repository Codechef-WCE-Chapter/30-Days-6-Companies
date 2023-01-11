
class Solution
{
public:
    vector<int> rec(int ind, vector<int> &v, vector<vector<int>> &dp)
    {
        int n = v.size();
        if (ind == n)
            return {};

        if (dp[ind].size() != 0)
            return dp[ind];

        vector<int> ans;

        for (int j = ind + 1; j < n; ++j)
        {
            if (v[j] % v[ind])
                continue;
            vector<int> res = rec(j, v, dp);
            if (res.size() >= size(ans))
                ans = res;
        }
        ans.push_back(v[ind]);
        return dp[ind] = ans;
    }
    vector<int> largestDivisibleSubset(vector<int> &v)
    {
        sort(v.begin(), v.end());
        vector<int> ans;
        int n = v.size();
        for (int i = 0; i < v.size(); ++i)
        {
            vector<vector<int>> dp(n);
            vector<int> res;
            res = rec(i, v, dp);

            if (res.size() >= ans.size())
                ans = res;
        }
        return ans;
    }
};
