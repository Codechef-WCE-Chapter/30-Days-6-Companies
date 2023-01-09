* Problem : https://leetcode.com/problems/combination-sum-iii/description/

* Solution : 

class Solution
{
public:
    void solution(int index, int t, vector<int> &c, vector<int> &ds, vector<vector<int>> &ans, int k)
    {
        if (t == 0) // BASE CASE
        {
            if(ds.size() == k)
                ans.push_back(ds);
            return;
        }

        for (int i = index; i < c.size(); ++i)
        {
            if (i > index and c[i] == c[i - 1]) // FOR AVOIDING DUPLICATE SUBSEQUENCES
                continue;
            if(c[i] > t) break;   //FOR AVOIDING TLE!\U0001f612
            ds.push_back(c[i]); // PICKING
            solution(i + 1, t - c[i], c, ds, ans, k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int t)
    {
        vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds;
        vector<vector<int>> ans;
        solution(0, t, c, ds, ans, k);
        return ans;
    }
};