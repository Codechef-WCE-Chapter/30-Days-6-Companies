#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>

#define ll long long
#define MOD 1000000007

using namespace std;
int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int r = n % 10;
        n /= 10;
        rev = rev * 10 + r;
    }
    return rev;
}
int countNicePairs(vector<int> &nums)
{
    ll ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // cout<<<<" ";
            int revNi = reverse(nums[i]);
            int revNj = reverse(nums[j]);
            if (nums[i] + revNj == nums[j] + revNi)
            {
                ans = (ans + 1) % MOD;
                cout << "i::" << i << "  j::" << j << endl;
            }
        }
    }
    return ans;
}

// ---------meth2
ll countNicePairs2(vector<int> &nums)
{
    unordered_map<ll, ll> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int rev = reverse(nums[i]);
        mp[nums[i] - rev] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int rev = reverse(nums[i]);
        ll diff = nums[i] - rev;
        if (mp.find(diff) != mp.end())
        {
            auto val = mp.find(diff);
            if (val->second > i)
            {
                ans = (ans + 1) % MOD;
                cout << "i:" << i << "  j:" << val->second << endl;
            }
        }
    }
    return ans;
}

// ---------meth3-->most updated till meth3-->but got time exceed after 75 text case
ll countNicePairs3(vector<int> &nums)
{
    unordered_map<ll, vector<ll>> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int rev = reverse(nums[i]);
        mp[nums[i] - rev].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int rev = reverse(nums[i]);
        ll diff = nums[i] - rev;
        if (mp.find(diff) != mp.end())
        {
            auto val = mp.find(diff);
            vector<ll> pos = val->second;
            for (auto idx : pos)
            {
                if (idx > i)
                {
                    ans = (ans + 1) % MOD;
                    cout << "i:" << i << "  j:" << idx << endl;
                }
            }
        }
    }
    return ans;
}

// meth4
// ---------meth4-->most updated till meth4-->but got time exceed after 75 text case
vector<int> reverse_of_nums(vector<int> arr)
{
    vector<int> ans;
    for (auto val : arr)
    {
        ans.push_back(reverse(val));
    }
    return ans;
}
ll countNicePairs4(vector<int> &nums)
{
    vector<int> rev = reverse_of_nums(nums);
    map<int, int> mp;
    int i = 0;
    int ans = 0;
    for (auto val : nums)
    {
        if (mp.find(val - rev[i]) != mp.end())
        {
            int temp = (mp[val - rev[i]]);
            // cout << "temp:" << temp << endl;
            ans = (ans + temp) % MOD;
            // cnt+=(m[nums[i]-v[i]])%M;
        }

        mp[val - rev[i]]++;
        i++;
    }
    return ans;
}

int main()
{
    vector<int> nums{13, 10, 35, 24, 76};
    // cout << countNicePairs(nums) << endl;
    // cout << countNicePairs2(nums) << endl;
    // cout << countNicePairs3(nums) << endl;
    cout << countNicePairs4(nums) << endl;
}