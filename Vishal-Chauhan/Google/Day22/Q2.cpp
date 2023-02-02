#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
        {
            return false;
        }
        if (grid[x][y] == 1)
        {
            return true;
        }
        grid[x][y] = 1;
        bool chk1 = dfs(x - 1, y, grid), chk2 = dfs(x, y - 1, grid), chk3 = dfs(x + 1, y, grid), chk4 = dfs(x, y + 1, grid);
        return (chk1 && chk2 && chk3 && chk4);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    if (dfs(i, j, grid))
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid{{2, 3, 1}, {6, 1, 3}};
    // cout < < < < s.closedIsland(grid);
}