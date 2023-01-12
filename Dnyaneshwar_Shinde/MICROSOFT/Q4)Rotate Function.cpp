// https: // leetcode.com/problems/rotate-function/

// Input: nums = [4,3,2,6]
// Output: 26
// Explanation:
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
// So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.


// currSum=prevSum+sum-(n*nums[i])

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {

        int n = nums.size();
        int prev = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            prev += (i * nums[i]);
            sum += nums[i];
        }

        int ans = prev;

        for (int i = n - 1; i > 0; i--)
        {
            prev += sum - (n * nums[i]);

            ans = max(ans, prev);
        }

        return ans;
    }
};

int32_t main()
{

    

    return 0;
}