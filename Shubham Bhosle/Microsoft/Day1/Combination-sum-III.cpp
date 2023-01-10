class Solution
{
public:
    void helper(int currNum, vector<vector<int>> &ans, vector<int> &temp, int k, int n)
    {
        // base case
        if (n < 0)
            return;
        if (temp.size() == k)
        {
            if (n == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        // take it
        for (int i = currNum; i <= 9; i++)
        {
            temp.push_back(i);
            helper(i + 1, ans, temp, k, n - i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1, ans, temp, k, n);
        return ans;
    }
};
