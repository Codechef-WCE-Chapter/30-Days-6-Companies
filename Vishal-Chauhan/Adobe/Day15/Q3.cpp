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
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> res;
        for (auto q : queries)
        {
            int k = q[0], trim = q[1];
            vector<pair<string, int>> tmp;
            for (int j = 0; j < nums.size(); j++)
            {
                int n = nums[j].size();
                string s = nums[j].substr(n - trim);
                if (s.size())
                    tmp.push_back({s, j});
            }
            sort(begin(tmp), end(tmp));
            res.push_back(tmp[k - 1].second);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> nums = {"102", "473", "251", "814"};
    vector<vector<int>> queries = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
    vector<int> ans = s.smallestTrimmedNumbers(nums, queries);
    for (auto val : ans)
        cout << val << " ";
}