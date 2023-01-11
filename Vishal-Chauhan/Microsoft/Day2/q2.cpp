#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;

vector<int> largestSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1);
    vector<int> pre(nums.size(), -1);
    int maxLen = 1;
    int maxIndex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
                if (dp[i] > maxLen)
                {
                    maxLen = dp[i];
                    maxIndex = i;
                }
            }
        }
    }
    vector<int> ans;
    while (maxIndex != -1)
    {
        ans.push_back(nums[maxIndex]);
        maxIndex = pre[maxIndex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> largestDivisibleSubset(vector<int> &num)
{
    vector<int> arr = largestSubset(num);
    return arr;
}

int main()
{
    vector<int> arr{1, 2, 4, 8};
    vector<int> ans = largestDivisibleSubset(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << ans[i] << " ";
    }
}