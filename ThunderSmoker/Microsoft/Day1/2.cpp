// Combination sum 3

class Solution
{
public:
    vector<vector<int>> v;
    void f(int k, vector<int> ds, int target, int i)
    {
        if (ds.size() == k)
        {
            if (target == 0)
            {
                v.push_back(ds);
            }
            return;
        }
        if (i > 9)
            return;
        ds.push_back(i);
        f(k, ds, target - i, i + 1);
        ds.pop_back();
        f(k, ds, target, i + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> ds;
        f(k, ds, n, 1);
        return v;
    }
};