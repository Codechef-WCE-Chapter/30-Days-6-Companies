#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#define MOD 1000000007
using namespace std;

class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        int left[n], right[n];
        long long int sum[n];
        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + nums[i];
        }
        stack<pair<int, int>> s1, s2;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 1;
            while (!s1.empty() && (s1.top().first) > nums[i])
            {
                cnt += s1.top().second;
                s1.pop();
            }
            s1.push({nums[i], cnt});
            left[i] = cnt;
        }
        for (int i = n - 1; i >= 0; --i)
        {
            int cnt = 1;
            while (!s2.empty() && (s2.top().first) >= nums[i])
            {
                cnt += s2.top().second;
                s2.pop();
            }

            s2.push({nums[i], cnt});
            right[i] = cnt;
        }
        long long int res = 0;
        for (int i = 0; i < n; i++)
        {
            int a = i - left[i] + 1;
            int b = i + right[i] - 1;
            long long int subArraySum;
            if (a > 0)
                subArraySum = sum[b] - sum[a - 1];
            else
                subArraySum = sum[b];
            res = max(res, subArraySum * nums[i]);
        }
        return res % MOD;
    }
};

int main()
{
    Solution s;
    vector<int> arr{3, 4, 2, 1, 5};
    cout << "ans:" << s.maxSumMinProduct(arr) << endl;
}