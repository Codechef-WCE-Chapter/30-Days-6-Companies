// https: // leetcode.com/problems/largest-divisible-subset/description/

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

// Algo 
// - Run two for loops and find longest valid length of subset (sort it first)
// - then traverse from last , maintain a prev 

//1 2 4 8 then dp array --> 1 2 3 4



#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        int mxLen = 1;
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mxLen = max(mxLen, dp[i]);
        }

        // cout<<mxLen<<endl;

        int prev = -1;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] == mxLen)
            {
                if (prev == -1 || prev % nums[i] == 0)
                {
                    ans.push_back(nums[i]);
                    mxLen--;
                    prev = nums[i];
                }
            }
        }

        return ans;
    }
};

int32_t main()
{

    return 0;
}