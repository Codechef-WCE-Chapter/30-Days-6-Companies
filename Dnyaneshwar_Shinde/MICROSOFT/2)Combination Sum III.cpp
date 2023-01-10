// https: // leetcode.com/problems/combination-sum-iii/description/

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9

#include <bits/stdc++.h>
using namespace std;

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

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}