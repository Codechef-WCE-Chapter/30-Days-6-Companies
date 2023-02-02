#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
#define inf 11111111111
using namespace std;
class Solution
{
public:
    int partition(vector<int> &nums, int i, int j)
    {
        int pivotIndex = i;
        int end = j;
        i++;

        while (i <= j)
        {
            while (i <= end && nums[i] < nums[pivotIndex])
            {
                i++;
            }
            while (j >= pivotIndex && nums[j] > nums[pivotIndex])
            {
                j--;
            }
            if (i <= j)
            {
                swap(nums[i++], nums[j--]);
            }
        }
        swap(nums[pivotIndex], nums[j]);
        return j;
    }
    void quickSort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            // swapping element at index l with element at random index
            swap(nums[l + rand() % (r - l + 1)], nums[l]);
            int mid = partition(nums, l, r);
            quickSort(nums, l, mid - 1);
            quickSort(nums, mid + 1, r);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> arr{6, 5, 33, 1, 8, 2};
    s.sortArray(arr);
    for (auto val : arr)
    {
        cout << val << "  ";
    }
}