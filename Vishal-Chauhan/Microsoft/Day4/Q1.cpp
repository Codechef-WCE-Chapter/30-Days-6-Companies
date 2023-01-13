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
int min(int a, int b)
{
    return a > b ? b : a;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int findUnsortedSubarray(vector<int> &nums) // nlog(n)
{
    int n = nums.size();
    vector<int> arr = nums;
    sort(nums.begin(), nums.end());
    // for (auto val : nums)
    //     cout << val << " ";
    // cout << endl;
    // for (auto val : arr)
    //     cout << val << " ";
    // cout << endl;
    int l = 0, r = n - 1;
    int i = 0;
    for (; i < n; i++)
    {
        if (nums[i] != arr[i])
        {
            // cout<<"nums:"<<nums[i]<<"  arr:"<<arr[i]<<endl;
            l = i;
            break;
        }
    }
    // cout<<"l:::::"<<l<<endl;
    if (i >= n)
        return 0;
    i = n - 1;
    for (; i >= 0; i--)
    {
        if (nums[i] != arr[i])
        {
            r = i;
            break;
        }
    }
    cout << "l:" << l << "  r:" << r << endl;
    return r - l + 1;
}
// ------------meth2------------

int findUnsortedSubarray2(vector<int> &nums)
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
// --------------------
int main()
{
    vector<int> nums{2, 6, 4, 8, 10, 9, 15};
    cout << findUnsortedSubarray(nums);
    cout << findUnsortedSubarray2(nums);
}