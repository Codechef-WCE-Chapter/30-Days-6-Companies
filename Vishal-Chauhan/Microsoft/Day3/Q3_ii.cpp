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

class Solution
{
public:
    long long c = 0;
    void Count(vector<int> &v, int start, int mid, int end, int d)
    {
        int l = start, r = mid + 1;
        while (l <= mid && r <= end)
        {
            if (v[l] <= (v[r] + d))
            {
                // if a condition is satisfied for index r then it will be satisfied for all indices in the right side
                // as both left and right parts already sorted
                c += (end - r + 1);
                l++;
            }
            else
            {
                r++;
            }
        }
        // now sort the combined list to use in upper levels
        sort(v.begin() + start, v.begin() + end + 1);
    }
    void mergeSort(vector<int> &v, int start, int end, int d)
    {
        if (start == end)
        {
            return;
        }
        // go deeper
        int mid = start + (end - start) / 2;
        // call for left side
        // will go deeper to left side and the left side will be returned as a sorted list
        mergeSort(v, start, mid, d);
        // will go deeper to the right side and right side will be returned as a sorted list
        mergeSort(v, mid + 1, end, d);

        // now both left and right side are a sorted list
        // and the indices of left sides are less than right side
        // call the count function
        Count(v, start, mid, end, d);
    }
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        vector<int> v;
        int n = nums1.size();
        // reduce the condition
        // nums1[i]-nums1[j]<=nums2[i]-nums2[j]+diff
        // nums1[i]-nums2[i]<=nums1[j]-nums2[j]+diff
        for (int i = 0; i < nums1.size(); i++)
        {
            v.push_back(nums1[i] - nums2[i]);
        }
        mergeSort(v, 0, n - 1, diff);
        return c;
    }
};

int main()
{
    vector<int> a{3, -1}, b{-2, 2};
    int diff = -1;
    Solution s;
    cout << s.numberOfPairs(a, b, diff) << endl;
}