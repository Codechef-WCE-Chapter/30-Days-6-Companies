#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
// #define ll long long int
using namespace std;
class Solution
{
private:
    int bfs(int row, int col, vector<vector<int>> &vis,
            vector<vector<int>> &grid, int n, int m)
    {
        vis[row][col] = 1;
        queue<pair<pair<int, int>, int>> q;

        q.push({{row, col}, 1});

        int area = 1;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    area = area + 1;
                    q.push({{nrow, ncol}, area});
                }
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    int area = bfs(i, j, vis, grid, n, m);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};
int main()
{
    Solution s;
}