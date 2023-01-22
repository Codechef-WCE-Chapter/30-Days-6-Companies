#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
using namespace std;

class Solution
{
public:
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 1; i < n; i++)
        { // decreasing value
            if (nums[i] < nums[i - 1])
            {
                mini = min(mini, nums[i]);
            }
        }
        for (int i = n - 2; i >= 0; i--)
        { // increasing value
            if (nums[i] > nums[i + 1])
            {
                maxi = max(maxi, nums[i]);
            }
        }
        if (mini == INT_MAX)
            return 0;

        // If array is not sorted
        int start = 0, end = n - 1;
        for (; start < n; start++)
        { // finding start point
            if (nums[start] > mini)
                break; // find index in the left for a no. greater than the min found
        }
        for (; end >= 0; end--)
        { // finding end point
            if (nums[end] < maxi)
                break; // find index in the right for a no. lesser than the max found
        }

        return end - start + 1;
    }
};

int main()
{
    Solution s;
    vector<int> arr{2, 3, 5, 6, 4, 8, 9, 1};
    cout << s.findUnsortedSubarray(arr) << endl;
}