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
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());
        int cnt = 0;
        int cmn = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++)
        {
            cmn = __gcd(cmn, numsDivide[i]);
        }

        if (nums[0] > cmn)
        {
            return -1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (cmn % nums[i] == 0)
            {
                return cnt;
            }
            cnt++;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 3, 2, 4, 3}, numDiv{9, 6, 9, 3, 15};
    int ans = s.minOperations(nums, numDiv);
    cout << "ans:" << ans << endl;
}