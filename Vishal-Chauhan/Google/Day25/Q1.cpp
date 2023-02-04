#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool chk(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> v(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({grid[0][0], {0, 0}});
        v[0][0] = grid[0][0];
        while (!q.empty())
        {
            int cnt = q.top().first, x = q.top().second.first, y = q.top().second.second;
            q.pop();
            int c[4] = {-1, 0, 1, 0};
            int r[4] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++)
            {
                int row = r[i] + x, col = c[i] + y;
                if (chk(row, col, n))
                {
                    if (cnt < grid[row][col])
                    {
                        v[row][col] = grid[row][col];
                        q.push({v[row][col], {row, col}});
                    }
                    else if (cnt < v[row][col])
                    {
                        v[row][col] = cnt;
                        q.push({v[row][col], {row, col}});
                    }
                }
            }
        }
        return v[n - 1][n - 1];
    }
};

int main()
{
}