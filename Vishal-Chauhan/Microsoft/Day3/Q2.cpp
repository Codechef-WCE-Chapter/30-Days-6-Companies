#include <vector>
#include <iostream>

using namespace std;

class Solution
{
    vector<vector<int>> edges;
    vector<int> amount;
    vector<int> dp;
    int dfs(int u, int parent)
    {
        if (edges[u].size() == 1 && edges[u][0] == parent)
        {
            return amount[u];
        }
        int maxIncome = 0;
        for (int v : edges[u])
        {
            if (v != parent)
            {
                maxIncome = max(maxIncome, dfs(v, u));
            }
        }
        int income = (amount[u] > 0) ? amount[u] : 0;
        for (int v : edges[u])
        {
            if (v != parent)
            {
                income += dp[v];
            }
        }
        if (amount[u] < 0)
        {
            income -= amount[u];
        }
        dp[u] = max(income, maxIncome);
        return dp[u];
    }

public:
    int solve(int N, vector<int> &A, vector<vector<int>> &E)
    {
        edges = E;
        amount = A;
        dp.resize(N);
        int res = dfs(0, -1);
        if (edges[0].size() > 1)
        {
            int bobIncome = 0;
            for (int v : edges[0])
            {
                bobIncome += dp[v];
            }
            res += bobIncome;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> E{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    vector<int> A{-2, 4, 2, -4, 6};
    int n = 3;
    Solution s;
    cout << s.solve(n, A, E) << endl;
}