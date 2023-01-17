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
    struct BIT
    {
        vector<int> arr;

        int N;

        BIT(int n)
        {
            N = n + 1;
            arr = vector<int>(N, 0);
        }

        void add(int i)
        {
            i += 1;
            while (i < N)
            {
                arr[i] += 1;
                i += i & (-i);
            }
        }

        int query(int i)
        {
            int sum = 0;
            while (i > 0)
            {
                sum += arr[i];
                i = i & (i - 1);
            }
            return sum;
        }
    };

    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        long n = nums1.size();
        vector<pair<int, int>> points(n); // each number i in 0..n-1 can be represented by a point (pos1i, pos2i)
        for (long i = 0; i < n; i++)
            points[nums1[i]].first = i;
        for (long i = 0; i < n; i++)
            points[nums2[i]].second = i;
        sort(points.begin(), points.end()); // sort points based on pos1
        long ans = 0;
        long left, right;
        BIT bit(n); // use binary index tree to find out how many points are smaller than current point
        bit.add(points[0].second);
        for (long i = 1; i < n - 1; i++)
        {
            left = bit.query(points[i].second);          // number of smaller points
            right = n - 1 - points[i].second - i + left; // number of larger points
            ans += left * right;
            bit.add(points[i].second); // update binary index tree
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> num1 = {2, 0, 1, 3}, num2 = {0, 1, 2, 3};
    long long ans = s.goodTriplets(num1, num2);
    cout << ans << endl;
}