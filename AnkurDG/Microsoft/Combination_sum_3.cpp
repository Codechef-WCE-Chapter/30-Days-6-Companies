class Solution
{
public:
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> ans;
    void solve(int i, int cursum, int k, int n, vector<int> v)
    {
        if (i >= 9)
        {
            if (cursum == n && v.size() == k)
            {
                ans.push_back(v);
            }
            return;
        }
        if (num[i] + cursum <= n)
        {
            v.push_back(num[i]);
            solve(i + 1, cursum + num[i], k, n, v);
            v.pop_back();
        }
        solve(i + 1, cursum, k, n, v);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> v;
        solve(0, 0, k, n, v);
        return ans;
    }
};