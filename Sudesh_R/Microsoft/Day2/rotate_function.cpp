class Solution
{
public:
    // obtaining relation for dp : https://assets.leetcode.com/users/images/43f23648-7dca-47af-a823-ea51d1c9e1f3_1672734024.3253932.png
    int dp[100005];
    int solve(int i, int sum, int n, vector<int> &a)
    {
        if (dp[i] != -1)
        {
            return dp[i];
        }
        if (i > 0)
        {
            return dp[i] = solve(i - 1, sum, n, a) + sum - n * a[n - i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (i * a[i]);
        }
        return dp[i] = ans;
    }
    int maxRotateFunction(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        solve(nums.size() - 1, sum, nums.size(), nums);
        for (int i = 0; i < nums.size(); i++)
        {
            cout << dp[i] << ' ';
        }
        cout << endl;
        return *max_element(dp, dp + nums.size());
    }
};