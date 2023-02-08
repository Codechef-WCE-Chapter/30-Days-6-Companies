
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int solve(vector<vector<int>> &grid, int r, int c)
    {
        int ans = 0;
        for (int i = r; i < r + 3; i++)
        {
            for (int j = c; j < c + 3; j++)
            {
                ans += grid[i][j];
            }
        }
        return ans - grid[r + 1][c] - grid[r + 1][c + 2];
    }
    int maxSum(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        int ans = INT_MIN;
        for (int i = 0; i <= r - 3; i++)
        {
            // cout << "i:" << i << endl;
            for (int j = 0; j <= c - 3; j++)
            {
                // cout << "j:" << j << endl;
                ans = max(ans, solve(grid, i, j));
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid{
        {2, 3, 4, 8, 5}, {6, 3, 1, 5, 2}, {4, 3, 7, 6, 2}};
    cout << s.maxSum(grid) << endl;
}