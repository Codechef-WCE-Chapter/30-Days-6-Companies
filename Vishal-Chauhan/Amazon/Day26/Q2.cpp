#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
    const int inf = 1e8;
    int dp[101][101];

public:
    int dfs(int node, int k, int dest, vector<vector<int>> &cost, vector<int> adj[])
    {
        if (k < 0)
            return inf;

        if (node == dest)
            return 0;

        if (dp[node][k] != -1)
            return dp[node][k];

        int ans = inf;
        for (auto i : adj[node])
            ans = min(ans, cost[node][i] + dfs(i, k - 1, dest, cost, adj));

        return dp[node][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        memset(dp, -1, sizeof dp);

        vector<vector<int>> cost(n, vector<int>(n));
        vector<int> adj[n];
        for (auto e : flights)
        {
            adj[e[0]].push_back(e[1]);
            cost[e[0]][e[1]] = e[2];
        }

        int ans = dfs(src, k + 1, dst, cost, adj);
        return ans == inf ? -1 : ans;
    }
};
int main()
{
}