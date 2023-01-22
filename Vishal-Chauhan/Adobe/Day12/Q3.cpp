#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
using namespace std;
double knightProbability(int n, int k, int r, int c)
{
    vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
    dp[0][r][c] = 1;
    int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                for (int m = 0; m < 8; m++)
                {
                    int rr = j + dx[m], cc = l + dy[m];
                    if (rr >= 0 && rr < n && cc >= 0 && cc < n)
                    {
                        dp[i][j][l] += dp[i - 1][rr][cc] / 8.0;
                    }
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += dp[k][i][j];
        }
    }
    return ans;
}

int main()
{
    cout << knightProbability(3, 2, 0, 0) << endl;
}