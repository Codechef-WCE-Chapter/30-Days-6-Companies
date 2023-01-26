#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int left = 0, right = mountainArr.length() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        int peak = left;
        int index = binarySearch(target, mountainArr, 0, peak, true);
        if (index != -1)
        {
            return index;
        }
        return binarySearch(target, mountainArr, peak + 1, mountainArr.length() - 1, false);
    }

private:
    int binarySearch(int target, MountainArray &mountainArr, int left, int right, bool isAscending)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            if ((mountainArr.get(mid) < target) == isAscending)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
