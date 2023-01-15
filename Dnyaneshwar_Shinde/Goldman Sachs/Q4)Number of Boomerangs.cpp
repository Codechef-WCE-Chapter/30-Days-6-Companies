// https: // leetcode.com/problems/number-of-boomerangs/description/

// boomerang is a tuple of points(i, j, k)
// such that the distance between i and j equals the distance between i and k(the order of the tuple matters).

// Input: points = [[0,0],[1,0],[2,0]]
// Output: 2
// Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &v)
    {

        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            map<int, int> mp;
            for (int j = 0; j < n; j++)
            {
                int x1 = v[i][0], y1 = v[i][1];
                int x2 = v[j][0], y2 = v[j][1];

                int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                mp[dist]++;
            }

            for (auto ind : mp)
            {
                ans += ind.second * (ind.second - 1);
            }
        }

        return ans;
    }
};

int32_t main()
{

   

    return 0;
}